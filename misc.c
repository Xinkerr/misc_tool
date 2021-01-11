#include <stdint.h>
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
uint16_t htons(uint16_t n)
{
  return ((n & 0xff) << 8) | ((n & 0xff00) >> 8);
}

/**
 * @brief 字节序转换 int类型 32bit
 * @param[in]   n: 数值
 * @return 转换后的数值
 */
uint32_t htoni(uint32_t source)  
{  
    return 0
    | ((source & 0x000000ff) << 24)
    | ((source & 0x0000ff00) << 8)
    | ((source & 0x00ff0000) >> 8)
    | ((source & 0xff000000) >> 24);  
}
