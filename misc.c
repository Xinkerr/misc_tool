
/**
 * GITHUB: https://github.com/Xinkerr/misc_tool
 * LICENSE: Apache-2.0
 * VERSION: v1.1 
 **/
 
#include <stdint.h>
#include <stdio.h>
#include "misc.h"

#define ASCII_A_BASE            ('A' - 0x0a)

static char halftoa(uint8_t src)
{
    if(src < 0x0a)
    {
        return src + '0';
    }
    else
    {
        return src + ASCII_A_BASE;
    }
}

/**
 * @brief 数值转ASCII
 * 
 * @param[in]  src: 源数据，数值数组的地址
 * @param[out] dest: 目标地址, 存储ASCII
 * @param[in]  len: 数值长度
 * 
 * @return  字符串长度
 */ 
int mc_itoa(uint8_t* src, char* dest, uint16_t len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        *dest = halftoa(src[i] >> 4);
        dest ++;
        *dest = halftoa(src[i] & 0x0f);
        dest ++;
    }
    return i<<1;
}

/**
 * @brief 字节序转换 short类型 16bit
 * @param[in]   n: 数值
 * @return 转换后的数值
 */
uint16_t mc_htons(uint16_t n)
{
  return ((n & 0xff) << 8) | ((n & 0xff00) >> 8);
}

/**
 * @brief 字节序转换 int类型 32bit
 * @param[in]   n: 数值
 * @return 转换后的数值
 */
uint32_t mc_htoni(uint32_t source)  
{  
    return 0
    | ((source & 0x000000ff) << 24)
    | ((source & 0x0000ff00) << 8)
    | ((source & 0x00ff0000) >> 8)
    | ((source & 0xff000000) >> 24);  
}

/**
 * @brief 单个HEX字符转HEX数值格式
 * @param[in]   str: HEX字符串
 * @return 转换后的数值
 */
uint8_t mc_strhex(const char* str)
{
	uint8_t ascii_val = *str;
	uint8_t hex_val = 0;
	if(ascii_val >= 'a' && ascii_val <= 'f')
	{
		hex_val =  ascii_val - 'a' + 10;
	}
    else if(ascii_val >= 'A' && ascii_val <= 'F')
	{
		hex_val =  ascii_val - 'A' + 10;
	}
	else
	{
		hex_val = ascii_val - '0';
	}
	hex_val <<= 4;
	ascii_val = *(str+1);
	if(ascii_val >= 'a' && ascii_val <= 'f')
	{
		hex_val |=  0x0f & (ascii_val - 'a' + 10);
	}
    else if(ascii_val >= 'A' && ascii_val <= 'F')
    {
        hex_val |=  0x0f & (ascii_val - 'A' + 10);
    }
	else
	{
		hex_val = 0x0f & (ascii_val - '0');
	}
	return hex_val;
}

/**
 * @brief HEX字符串转HEX数值格式
 * @param[in]   dest_hex: 存放hex数值格式的数组地址
 * @param[in]   str: HEX字符串
 * @param[in]   len: 字符串长度
 * @return 转换后的数值
 */
void mc_strhexs(uint8_t* dest_hex, const char* str, size_t len)
{
	size_t i, hex_len;
	hex_len = len / 2;
	for(i = 0; i < hex_len; i++)
	{
		*dest_hex = mc_strhex(str);
		str += 2;
		dest_hex++;
	}
}