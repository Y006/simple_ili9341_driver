#ifndef LCD_BASIC_H
#define LCD_BASIC_H

#include "ILI9341_Driver.h"

/**
 * @brief �� LCD ��Ļ����ʾһ���ַ�
 * 
 * @param x �ַ���ʼ������
 * @param y �ַ���ʼ������
 * @param character Ҫ��ʾ���ַ�
 * @param fontColor �ַ���ɫ
 */
void LCD_Display_Char(uint16_t x, uint16_t y, uint8_t character, uint16_t fontColor);
/**
 * @brief ��LCD��Ļ����ʾһ���ַ���
 *
 * @param x �ַ�������ʼx����
 * @param y �ַ�������ʼy����
 * @param string Ҫ��ʾ���ַ���
 * @param fontColor �ַ���������ɫ
 */
void LCD_Display_String(uint16_t x, uint16_t y, const uint8_t* string, uint16_t fontColor);



#endif
