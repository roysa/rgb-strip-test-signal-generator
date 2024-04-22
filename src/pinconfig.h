#ifndef PINCONFIG_H
#define PINCONFIG_H

#ifndef SG_BOARD
    #error "SG_BOARD not defined"
#endif

#if SG_BOARD == uno
    #define ENC_DT_PIN 3
    #define ENC_CLK_PIN 4
    #define BTN_PIN 5

    #define DIS_SCL_PIN A5
    #define DIS_SDA_PIN A4

    #define DIS_MOSI_PIN 9
    #define DIS_SCK_PIN 10
    #define DIS_DC_PIN 11
    #define DIS_CS_PIN 12

    #define DIS_RESET_PIN 13

    #define LEDS_COUNT 8
    #define LED_DATA_PIN 6


#elif SG_BOARD == nano
    #define ENC_DT_PIN 3
    #define ENC_CLK_PIN 4
    #define BTN_PIN 5

    #define DIS_SCL_PIN A5
    #define DIS_SDA_PIN A4

    #define DIS_MOSI_PIN 9
    #define DIS_SCK_PIN 10
    #define DIS_DC_PIN 11
    #define DIS_CS_PIN 12

    #define DIS_RESET_PIN 13

    #define LEDS_COUNT 8
    #define LED_DATA_PIN 6

#elif SG_BOARD == promini
    #define ENC_DT_PIN 3
    #define ENC_CLK_PIN 4
    #define BTN_PIN 5

    #define DIS_SCL_PIN A5
    #define DIS_SDA_PIN A4

    #define DIS_MOSI_PIN 9
    #define DIS_SCK_PIN 10
    #define DIS_DC_PIN 11
    #define DIS_CS_PIN 12

    #define DIS_RESET_PIN 13

    #define LEDS_COUNT 8
    #define LED_DATA_PIN 6


#elif SG_BOARD == bluepill
    #define ENC_DT_PIN 3
    #define ENC_CLK_PIN 4
    #define BTN_PIN 5

    #define DIS_SCL_PIN A5
    #define DIS_SDA_PIN A4

    #define DIS_MOSI_PIN PA7
    #define DIS_DC_PIN PA3
    #define DIS_SCK_PIN PA5
    #define DIS_CS_PIN PA4
    
    #define DIS_RESET_PIN PB1

    #define LEDS_COUNT 8
    #define LED_DATA_PIN 6

    
#else
    #error "Board not supported"
#endif

#ifndef NUM_LEDS
    #define NUM_LEDS 8
#endif

#ifdef DISPLAY_I2C
    #ifndef DIS_SDA_PIN
        #error "Display I2C bus SDA DIS_SDA_PIN not defined"
    #endif
    #ifndef DIS_SCL_PIN
        #error "Display I2C bus SCL DIS_SCL_PIN not defined"
    #endif
#endif
    
#ifdef DISPLAY_SPI
    #ifndef DIS_MOSI_PIN
        #error "Display SPI MOSI DIS_MOSI_PIN not defined"
    #endif
    #ifndef DIS_SCK_PIN
        #error "Display SPI SCK DIS_SCK_PIN not defined"
    #endif
    #ifndef DIS_CS_PIN
        #error "Display SPI CS DIS_CS_PIN not defined"
    #endif
    #ifndef DIS_DC_PIN
        #error "Display SPI DC DIS_DC_PIN not defined"
    #endif
#endif

#ifndef LED_DATA_PIN
    #error "LED data pin LED_DATA_PIN not defined"
#endif

#ifndef SCREEN_WIDTH
    #define SCREEN_WIDTH 128
#endif
#ifndef SCREEN_HEIGHT
    #define SCREEN_HEIGHT 64
#endif
#ifndef DISPLAY_I2C_ADDRESS
    #define DISPLAY_I2C_ADDRESS 0x3C
#endif

#endif