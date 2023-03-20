# simple_ili9341_driver

### 介绍

- 一个简单的 ili9341 驱动，使用 STM32F411RE 和中景园的 [ZJY_TFT240_8P_CS](https://m.tb.cn/h.UqX0tab?tk=EKABdjzItGw) 显示屏进行测试
- 代码参考了该项目：[STM32-ILI9341](https://github.com/martnak/STM32-ILI9341)
- 代码借助了 ChatGPT 进行了辅助编写

### 使用方法

1. 添加 `ILI9341_Driver.c` 和 `lcd_basic.c` 两个文件到工程中，将文件夹添加到 Include Paths。
2. 在 `ILI9341_Driver.h` 中进行配置：如果使用 STM32CubeMX，那么仅需要配置好硬件 SPI；否则需要在 `ILI9341_Driver.h` 中添加自己的配置。
3. 在 `main.c` 中调用芯片初始化函数 `ILI9341_Init()`，然后使用 `ILI9341_Fill_Screen(WHITE)` 设置背景色为白色（或其他颜色），最后调用 LCD 字符串显示函数进行测试 `LCD_Display_String(10,20,"Hello,World!",RED)`。
