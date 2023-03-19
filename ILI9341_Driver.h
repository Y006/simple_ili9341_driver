#ifndef ILI9341_DRIVER_H
#define ILI9341_DRIVER_H

/**
 * ============================== 开始 选择配置方式 ==================================
 *
 * 如果使用的是基于stm32cubeMX的HAL库并使用了硬件SPI，那么推荐选择STM_CONFIG；
 * 如果使用其他的芯片和配置方式，请选择USER_DEFINED自己进行配置
 */
 
// #define USER_DEFINED
#define STM_CONFIG

#ifdef USER_DEFINED
/**
 * 用户自己的配置
 */
#endif

#ifdef STM_CONFIG
/**
 * 基于stm32cubeMX的HAL库并使用了硬件SPI的配置
 */

#include "main.h"
#include "spi.h"
#include "gpio.h"

#define ILI9341_CS_LOW()    HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)
#define ILI9341_CS_HIGH()   HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)
#define ILI9341_DC_LOW()    HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET)
#define ILI9341_DC_HIGH()   HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET)
#define ILI9341_RST_HIGH()  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET)
#define ILI9341_RST_LOW()   HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET)

#define ILI9341_SPI_Transmit(Data)                \
    do {                                          \
        HAL_SPI_Transmit(&hspi1, &(Data), 1, 1);  \
    } while(0)

#define ILI9341_Delay(ms)           \
    do {                            \
        HAL_Delay(ms);              \
    } while(0)

void STM_HAL_SPI_Init(void);
	
#define ILI9341_SPI_Init()          \
    do {                            \
        STM_HAL_SPI_Init();         \
    } while(0)

#endif
/* ============================== 结束 选择配置方式 ================================== */

/* ============================== 常见的RGB565颜色值 开始 ============================== */
#define BLACK 		0x0000
#define PURPLE 		0x780F
#define BLUE 		0x001F
#define GREEN 		0x07E0
#define CYAN 		0x07FF
#define RED 		0xF800
#define YELLOW 		0xFFE0
#define WHITE 		0xFFFF
#define ORANGE 		0xFD20
#define PINK 		0xF81F
/* ============================== 常见的RGB565颜色值 结束 ============================== */

/* ============================== 芯片宏定义 开始 ================================== */

// 显示尺寸
#define ILI9341_SCREEN_HEIGHT 	240
#define ILI9341_SCREEN_WIDTH 	320

// 显示方向
#define SCREEN_VERTICAL_1 		0
#define SCREEN_HORIZONTAL_1 	1
#define SCREEN_VERTICAL_2 		2
#define SCREEN_HORIZONTAL_2 	3

/* 8.1. Command List （指令列表）
 * https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf
 * Regulative Command Set （常规指令集）
 */
#define CMD_NO_OPERATION 						0x00
#define CMD_SOFTWARE_RESET 						0x01
#define CMD_READ_DIS_IDENT_INFO 				0x04
#define CMD_READ_DIS_STATUS 					0x09
#define CMD_READ_DIS_POWER_MODE 				0x0a
#define CMD_READ_DIS_MADCTL 					0x0b
#define CMD_READ_DIS_PIXEL_FORMAT 				0x0c
#define CMD_READ_DIS_IMG_FORMAT 				0x0d
#define CMD_READ_DIS_SIG_MODE 					0x0e
#define CMD_READ_DIS_SELF_DIAGNOSTIC_RESULT 	0x0f
#define CMD_ENTER_SLEEP_MODE 					0x10
#define CMD_SLEEP_OUT 							0x11
#define CMD_PARTIAL_MODE_ON 					0x12
#define CMD_NORMAL_DIS_MODE_ON 					0x13
#define CMD_DIS_INVERSION_OFF 					0x20
#define CMD_DIS_INVERSION_ON 					0x21
#define CMD_GAMMA_SET 							0x26
#define CMD_DISPLAY_OFF 						0x28
#define CMD_DISPLAY_ON 							0x29
#define CMD_COL_ADDR_SET 						0x2a
#define CMD_PAGE_ADDR_SET 						0x2b
#define CMD_MEMORRY_WRITE 						0x2c
#define CMD_COLOR_SET 							0x2d
#define CMD_MEMORRY_READ						0x2e
#define CMD_PARTIAL_AREA 						0x30
#define CMD_VERTICAL_SCROLLING_DEF 				0x33
#define CMD_TEARING_EFFECT_LINE_OFF 			0x34
#define CMD_TEARING_EFFECT_LINE_ON 				0x35
#define CMD_MEMORY_ACCESS_CTRL 					0x36
#define CMD_VERTICAL_SCROLLING_START_ADDR 		0x37
#define CMD_IDLE_MODE_OFF 						0x38
#define CMD_INLE_MODE_ON 						0x39
#define CMD_COLMOD_PIXEL_FORMAT_SET 			0x3a
#define CMD_WRITE_MEMORY_CONTINUE 				0x3c
#define CMD_READ_MEMORY_CONTINUE 				0x3e
#define CMD_SET_TEAR_SCANLINE 					0x44
#define CMD_GET_SCANLINE 						0x45
#define CMD_WRITE_DIS_BRIGHTNESS 				0x51
#define CMD_READ_DIS_BRIGHTNESS 				0x52
#define CMD_WRITE_CTRL_DISPLAY 					0x53
#define CMD_READ_CTRL_DISPLAY 					0x54
#define CMD_WRITE_CONTENT_ADAPTIVE_BRIGHT_CTRL 	0x55
#define CMD_READ_CONTENT_ADAPTIVE_BRIGHT_CTRL 	0x56
#define CMD_WRITE_CABC_MIM_BRIGHT 				0x5e
#define CMD_READ_CABC_MIM_BRIGHT 				0x5f
#define CMD_READ_ID1 							0xda
#define CMD_READ_ID2 							0xdb
#define CMD_READ_ID3 							0xdc

/* Extended Command Set （扩展指令集）*/

// TODO

/* ============================== 芯片宏定义 结束 ================================== */

/* ============================== 函数声明列表 开始================================== */

/**
 * @brief ILI9341 写指令函数
 * 
 * @param Command 指令
 */
void ILI9341_Write_Command(uint8_t Command);
	
/**
 * @brief ILI9341 写数据函数
 * 
 * @param Data 数据
 */
void ILI9341_Write_Data(uint8_t Data);
	
/**
 * @brief 指定ILI9341写入数据的位置
 * 
 * @param X1 起始列地址
 * @param Y1 起始页地址
 * @param X2 结束列地址
 * @param Y2 结束页地址
 * 
 * @note 函数返回后即可向芯片(x1,y1)到(x2,y2)的范围内写入显示内容
 */
void ILI9341_Set_Address(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2);
	
/**
 * @brief 填充整个屏幕
 * @note  将整个屏幕设置为给定的颜色
 * @param Colour 像素点颜色，RGB565 格式，高位在前，低位在后
 * @retval None
 */
void ILI9341_Fill_Screen(uint16_t Colour);
	
/**
 * @brief 在指定坐标（X，Y）处绘制一个像素点
 * 
 * @param X     指定像素点的 X 坐标
 * @param Y     指定像素点的 Y 坐标
 * @param Color 像素点的颜色，使用 RGB565 格式
 */
void ILI9341_Draw_Pixel(uint16_t X, uint16_t Y, uint16_t Color);
	
/**
 * @brief 设置 ILI9341 芯片的 LCD 显示方向
 * 
 * @param Rotation 显示方向，可选值为：
 *                 SCREEN_VERTICAL_1: 	垂直屏幕向上
 *                 SCREEN_HORIZONTAL_1: 水平屏幕向上
 *                 SCREEN_VERTICAL_2: 	垂直屏幕向下
 *                 SCREEN_HORIZONTAL_2: 水平屏幕向下
 * 
 * @note 调用该函数可以设置 ILI9341 芯片的显示方向，同时会更新 LCD_WIDTH 和 LCD_HEIGHT 宏定义的值。
 * 
 * @note 在向 ILI9341 芯片写入数据前需要设置好显示方向，否则写入的图像会出现倒置等问题。
 */
void ILI9341_Set_Rotation(uint8_t Rotation);
	
/**
 * @brief 初始化 ILI9341 芯片
 */
void ILI9341_Init(void);

/* ============================== 函数声明列表 结束================================== */

#endif
