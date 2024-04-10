#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <u8g2.h>
#include "u8g2_esp32_hal.h"

#define PIN_SDA GPIO_NUM_4
#define PIN_SCL GPIO_NUM_15
#define PIN_RST GPIO_NUM_16

void app_main()
{
    u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
    u8g2_esp32_hal.sda = PIN_SDA;
    u8g2_esp32_hal.scl = PIN_SCL;
    u8g2_esp32_hal.reset = PIN_RST;
    u8g2_esp32_hal_init(u8g2_esp32_hal);

    u8g2_t u8g2;

    u8g2_Setup_ssd1306_i2c_64x32_1f_f(&u8g2,
                                      U8G2_R0,
                                      u8g2_esp32_i2c_byte_cb,
                                      u8g2_esp32_gpio_and_delay_cb);

    u8x8_SetI2CAddress(&u8g2.u8x8, 0x78);
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_tiny5_tf);
    u8g2_DrawStr(&u8g2, 0, 15, "Hola mundo!");
    u8g2_SendBuffer(&u8g2);
}