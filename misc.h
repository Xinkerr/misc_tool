#ifndef __MISC_H__
#define __MISC_H__
/**
 * @brief 数值转ASCII
 * 
 * @param[in]  src: 源数据，数值数组的地址
 * @param[out] dest: 目标地址, 存储ASCII
 * @param[in]  len: 数值长度
 * 
 * @return  字符串长度
 */ 
int mc_itoa(uint8_t* src, char* dest, uint16_t len);

/**
 * @brief 字节序转换 short类型 16bit
 * @param[in]   n: 数值
 * @return 转换后的数值
 */
uint16_t htons(uint16_t n);

/**
 * @brief 字节序转换 int类型 32bit
 * @param[in]   n: 数值
 * @return 转换后的数值
 */
uint32_t htoni(uint32_t source);

/**
 * @brief 单个HEX字符转HEX数值格式
 * @param[in]   str: HEX字符串
 * @return 转换后的数值
 */
uint8_t strhex(const char* str);

/**
 * @brief HEX字符串转HEX数值格式
 * @param[in]   dest_hex: 存放hex数值格式的数组地址
 * @param[in]   str: HEX字符串
 * @param[in]   len: 字符串长度
 * @return 转换后的数值
 */
void strhexs(uint8_t* dest_hex, const char* str, size_t len);

#endif
