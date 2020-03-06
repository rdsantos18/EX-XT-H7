/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SYNC_RDS_Pin GPIO_PIN_3
#define SYNC_RDS_GPIO_Port GPIOE
#define SEL_1_Pin GPIO_PIN_4
#define SEL_1_GPIO_Port GPIOE
#define STEREO_SELECT_Pin GPIO_PIN_5
#define STEREO_SELECT_GPIO_Port GPIOE
#define REMOTE_Pin GPIO_PIN_6
#define REMOTE_GPIO_Port GPIOE
#define PROCESSOR_SELECT_Pin GPIO_PIN_13
#define PROCESSOR_SELECT_GPIO_Port GPIOC
#define FAN2_Pin GPIO_PIN_14
#define FAN2_GPIO_Port GPIOC
#define EMPHASE_SELECT_Pin GPIO_PIN_15
#define EMPHASE_SELECT_GPIO_Port GPIOC
#define ENABLE_RF_DRV_Pin GPIO_PIN_0
#define ENABLE_RF_DRV_GPIO_Port GPIOC
#define OSC_SELECT_Pin GPIO_PIN_2
#define OSC_SELECT_GPIO_Port GPIOC
#define CS_CS3310_Pin GPIO_PIN_3
#define CS_CS3310_GPIO_Port GPIOC
#define SEL_2_Pin GPIO_PIN_0
#define SEL_2_GPIO_Port GPIOA
#define MB1501_EN_Pin GPIO_PIN_3
#define MB1501_EN_GPIO_Port GPIOA
#define MB1501_DATA_Pin GPIO_PIN_4
#define MB1501_DATA_GPIO_Port GPIOA
#define MB1501_CLK_Pin GPIO_PIN_5
#define MB1501_CLK_GPIO_Port GPIOA
#define RF_ON_Pin GPIO_PIN_6
#define RF_ON_GPIO_Port GPIOA
#define PLL_LOCK_Pin GPIO_PIN_0
#define PLL_LOCK_GPIO_Port GPIOB
#define OSC_STATUS_Pin GPIO_PIN_1
#define OSC_STATUS_GPIO_Port GPIOB
#define TFT_D4_Pin GPIO_PIN_7
#define TFT_D4_GPIO_Port GPIOE
#define TFT_D5_Pin GPIO_PIN_8
#define TFT_D5_GPIO_Port GPIOE
#define TFT_D6_Pin GPIO_PIN_9
#define TFT_D6_GPIO_Port GPIOE
#define TFT_D7_Pin GPIO_PIN_10
#define TFT_D7_GPIO_Port GPIOE
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOE
#define SEL_4_Pin GPIO_PIN_14
#define SEL_4_GPIO_Port GPIOB
#define OSC_EN_10MHZ_Pin GPIO_PIN_15
#define OSC_EN_10MHZ_GPIO_Port GPIOB
#define EEPROM_HOLD_Pin GPIO_PIN_10
#define EEPROM_HOLD_GPIO_Port GPIOD
#define TFT_DC_Pin GPIO_PIN_11
#define TFT_DC_GPIO_Port GPIOD
#define TFT_D0_Pin GPIO_PIN_14
#define TFT_D0_GPIO_Port GPIOD
#define TFT_D1_Pin GPIO_PIN_15
#define TFT_D1_GPIO_Port GPIOD
#define MP3_RESET_Pin GPIO_PIN_8
#define MP3_RESET_GPIO_Port GPIOC
#define PWM_RF_Pin GPIO_PIN_8
#define PWM_RF_GPIO_Port GPIOA
#define PWM_FAN_Pin GPIO_PIN_9
#define PWM_FAN_GPIO_Port GPIOA
#define AD_EOC_Pin GPIO_PIN_10
#define AD_EOC_GPIO_Port GPIOA
#define CS_AD_Pin GPIO_PIN_15
#define CS_AD_GPIO_Port GPIOA
#define SPI3_AD_SCK_Pin GPIO_PIN_10
#define SPI3_AD_SCK_GPIO_Port GPIOC
#define SPI3_AD_MISO_Pin GPIO_PIN_11
#define SPI3_AD_MISO_GPIO_Port GPIOC
#define SPI3_AD_MOSI_Pin GPIO_PIN_12
#define SPI3_AD_MOSI_GPIO_Port GPIOC
#define TFT_D2_Pin GPIO_PIN_0
#define TFT_D2_GPIO_Port GPIOD
#define TFT_D3_Pin GPIO_PIN_1
#define TFT_D3_GPIO_Port GPIOD
#define LED_RF_ON_Pin GPIO_PIN_2
#define LED_RF_ON_GPIO_Port GPIOD
#define LED_PLL_LOCK_Pin GPIO_PIN_3
#define LED_PLL_LOCK_GPIO_Port GPIOD
#define TFT_RD_Pin GPIO_PIN_4
#define TFT_RD_GPIO_Port GPIOD
#define TFT_EN_Pin GPIO_PIN_5
#define TFT_EN_GPIO_Port GPIOD
#define LED_FAIL_Pin GPIO_PIN_6
#define LED_FAIL_GPIO_Port GPIOD
#define TFT_CS_Pin GPIO_PIN_7
#define TFT_CS_GPIO_Port GPIOD
#define FAN1_Pin GPIO_PIN_7
#define FAN1_GPIO_Port GPIOB
#define CLIPPER_SELECT_Pin GPIO_PIN_8
#define CLIPPER_SELECT_GPIO_Port GPIOB
#define SEL_3_Pin GPIO_PIN_0
#define SEL_3_GPIO_Port GPIOE
#define FAN3_Pin GPIO_PIN_1
#define FAN3_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
