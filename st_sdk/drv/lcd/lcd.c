#include "lcd.h"
#include "output.h"

#include <stdio.h>

/*
    EN: D9: PD15 
    RS: D8: PF12

    LCD_D7: D7: PF13
    LCD_D6: D6: PE9
    LCD_D5: D5: PE11
    LCD_D4: D4: PF14

    Ardiuno pinout: http://store-usa.arduino.cc/products/arduino-uno-rev3
    STM32L4r5zi nucleo pinout: https://os.mbed.com/platforms/NUCLEO-L4R5ZI/
*/

#define D4_PIN GPIO_PIN_14
#define D5_PIN GPIO_PIN_11
#define D6_PIN GPIO_PIN_9
#define D7_PIN GPIO_PIN_13
#define RS_PIN GPIO_PIN_12
#define EN_PIN GPIO_PIN_15

#define D4_PORT GPIOF
#define D5_PORT GPIOE
#define D6_PORT GPIOE
#define D7_PORT GPIOF
#define RS_PORT GPIOF
#define EN_PORT GPIOD

static void send_data(unsigned char data);
static void send_command(unsigned char data);
static void write_data(unsigned char data);
static void enable_pulse();

void lcd_init()
{
    outputinit(GPIOF, GPIO_PIN_14 | GPIO_PIN_13 | GPIO_PIN_12);
    outputinit(GPIOE, GPIO_PIN_11 | GPIO_PIN_9);
    outputinit(GPIOD, GPIO_PIN_15);

    clearpin(GPIOF, GPIO_PIN_14 | GPIO_PIN_13 | GPIO_PIN_12);
    clearpin(GPIOE, GPIO_PIN_11 | GPIO_PIN_9);
    clearpin(GPIOD, GPIO_PIN_15);

    /*Display on */
    send_command(0x0C);
    HAL_Delay(50);
    send_command(0x28);
    HAL_Delay(50);
    send_command(0x01);
    HAL_Delay(50);
}

void lcd_display(unsigned char *data_name, int line_selection) 
{
  if(line_selection == 1)
  {
    send_command(0x80);
  }
  else
  {
    send_command(0xC0);
  }

  while(*data_name != '\0')
  {
    send_data(*data_name);
    data_name++;
  }
}

static void enable_pulse()
{
  HAL_GPIO_WritePin(EN_PORT, EN_PIN, GPIO_PIN_SET);
  HAL_Delay(20);
  HAL_GPIO_WritePin(EN_PORT, EN_PIN, GPIO_PIN_RESET);
  HAL_Delay(20);
}

static void write_data(unsigned char data)
{
  unsigned char lsb_nibble = data & 0xF, msb_nibble = (data >> 4) & 0xF;

  // MSB data
  HAL_GPIO_WritePin(D4_PORT, D4_PIN, (GPIO_PinState)(msb_nibble & 0x1));
  HAL_GPIO_WritePin(D5_PORT, D5_PIN, (GPIO_PinState)(msb_nibble & 0x2));
  HAL_GPIO_WritePin(D6_PORT, D6_PIN, (GPIO_PinState)(msb_nibble & 0x4));
  HAL_GPIO_WritePin(D7_PORT, D7_PIN, (GPIO_PinState)(msb_nibble & 0x8));

  enable_pulse();
  
  // LSB data
  HAL_GPIO_WritePin(D4_PORT, D4_PIN, (GPIO_PinState)(lsb_nibble & 0x1));
  HAL_GPIO_WritePin(D5_PORT, D5_PIN, (GPIO_PinState)(lsb_nibble & 0x2));
  HAL_GPIO_WritePin(D6_PORT, D6_PIN, (GPIO_PinState)(lsb_nibble & 0x4));
  HAL_GPIO_WritePin(D7_PORT, D7_PIN, (GPIO_PinState)(lsb_nibble & 0x8));

  enable_pulse();
}

static void send_data(unsigned char data)
{
  /*Setting rs pin high */
  HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_SET);
  HAL_Delay(20);

  write_data(data);
}

static void send_command(unsigned char data)
{
  /*Setting rs pin low */
  HAL_GPIO_WritePin(RS_PORT, RS_PIN, GPIO_PIN_RESET);
  HAL_Delay(20);

  write_data(data);
}
