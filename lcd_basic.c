#include "lcd_basic.h"
#include "lcd_font.h"

/**
 * @brief 在 LCD 屏幕上显示一个字符
 * 
 * @param x 字符起始横坐标
 * @param y 字符起始纵坐标
 * @param character 要显示的字符
 * @param fontColor 字符颜色
 */
void LCD_Display_Char(uint16_t x, uint16_t y, uint8_t character, uint16_t fontColor)
{
    uint8_t pixelData;
    uint16_t startX = x;
    
    // 将输入的字符转化为对应字库中的索引
    character = character - ' ';
    
    // 设置ILI9341 LCD屏幕上要显示的区域
    ILI9341_Set_Address(x, y, x+8-1, y+16-1);
    
    // 遍历16x8的像素矩阵
    for(uint16_t row = 0; row < 16; row++)
    {
        // 获取当前行的像素数据
        pixelData = ascii_1608[character][row];
        
        // 遍历当前行中的每个像素
        for(uint8_t column = 0; column < 8; column++)
        {
            // 如果当前像素位为1，则在该位置绘制一个点
            if(pixelData & (0x01<<column))
                ILI9341_Draw_Pixel(x, y, fontColor);
            x++;
            // 如果该行中的8个像素全部绘制完毕，则将绘制位置重置为该行起始位置，并开始下一行的绘制
            if((x - startX) == 8)
            {
                x = startX;
                y++;
                break;
            }
        }
    }
}
	 	  
/**
 * @brief 在LCD屏幕上显示一个字符串
 *
 * @param x 字符串的起始x坐标
 * @param y 字符串的起始y坐标
 * @param string 要显示的字符串
 * @param fontColor 字符的字体颜色
 */
void LCD_Display_String(uint16_t x, uint16_t y, const uint8_t* string, uint16_t fontColor)
{
    // 从字符串的第一个字符开始，循环遍历每个字符
    while (*string != '\0')
    {
        // 在LCD屏幕上显示当前字符
        LCD_Display_Char(x, y, *string, fontColor);
        // 增加x坐标的值，使得下一个字符可以紧接着当前字符绘制
        x += 8;
        
        // 将指针移动到下一个字符的位置
        string++;
    }
}
