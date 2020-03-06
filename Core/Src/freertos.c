/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for TaskMain */
osThreadId_t TaskMainHandle;
const osThreadAttr_t TaskMain_attributes = {
  .name = "TaskMain",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};
/* Definitions for TaskGUI */
osThreadId_t TaskGUIHandle;
const osThreadAttr_t TaskGUI_attributes = {
  .name = "TaskGUI",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 8191 * 4
};
/* Definitions for TaskBuzzer */
osThreadId_t TaskBuzzerHandle;
const osThreadAttr_t TaskBuzzer_attributes = {
  .name = "TaskBuzzer",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 512 * 4
};
/* Definitions for TaskPSU */
osThreadId_t TaskPSUHandle;
const osThreadAttr_t TaskPSU_attributes = {
  .name = "TaskPSU",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 512 * 4
};
/* Definitions for QueueUSART3 */
osMessageQueueId_t QueueUSART3Handle;
const osMessageQueueAttr_t QueueUSART3_attributes = {
  .name = "QueueUSART3"
};
/* Definitions for QueueUSART6 */
osMessageQueueId_t QueueUSART6Handle;
const osMessageQueueAttr_t QueueUSART6_attributes = {
  .name = "QueueUSART6"
};
/* Definitions for myQueue03 */
osMessageQueueId_t myQueue03Handle;
const osMessageQueueAttr_t myQueue03_attributes = {
  .name = "myQueue03"
};
/* Definitions for MutexI2C */
osMutexId_t MutexI2CHandle;
const osMutexAttr_t MutexI2C_attributes = {
  .name = "MutexI2C"
};
/* Definitions for MutexLVGL */
osMutexId_t MutexLVGLHandle;
const osMutexAttr_t MutexLVGL_attributes = {
  .name = "MutexLVGL"
};
/* Definitions for BinarySemI2C */
osSemaphoreId_t BinarySemI2CHandle;
const osSemaphoreAttr_t BinarySemI2C_attributes = {
  .name = "BinarySemI2C"
};
/* Definitions for BinarySemLVGL */
osSemaphoreId_t BinarySemLVGLHandle;
const osSemaphoreAttr_t BinarySemLVGL_attributes = {
  .name = "BinarySemLVGL"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartTaskMain(void *argument);
void StartTaskGUI(void *argument);
void StartTaskBuzzer(void *argument);
void StartTaskPSU(void *argument);

extern void MX_LWIP_Init(void);
extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of MutexI2C */
  MutexI2CHandle = osMutexNew(&MutexI2C_attributes);

  /* creation of MutexLVGL */
  MutexLVGLHandle = osMutexNew(&MutexLVGL_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of BinarySemI2C */
  BinarySemI2CHandle = osSemaphoreNew(1, 1, &BinarySemI2C_attributes);

  /* creation of BinarySemLVGL */
  BinarySemLVGLHandle = osSemaphoreNew(1, 1, &BinarySemLVGL_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of QueueUSART3 */
  QueueUSART3Handle = osMessageQueueNew (16, sizeof(uint8_t), &QueueUSART3_attributes);

  /* creation of QueueUSART6 */
  QueueUSART6Handle = osMessageQueueNew (16, sizeof(uint8_t), &QueueUSART6_attributes);

  /* creation of myQueue03 */
  myQueue03Handle = osMessageQueueNew (4, sizeof(uint8_t), &myQueue03_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of TaskMain */
  TaskMainHandle = osThreadNew(StartTaskMain, NULL, &TaskMain_attributes);

  /* creation of TaskGUI */
  TaskGUIHandle = osThreadNew(StartTaskGUI, NULL, &TaskGUI_attributes);

  /* creation of TaskBuzzer */
  TaskBuzzerHandle = osThreadNew(StartTaskBuzzer, NULL, &TaskBuzzer_attributes);

  /* creation of TaskPSU */
  TaskPSUHandle = osThreadNew(StartTaskPSU, NULL, &TaskPSU_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartTaskMain */
/**
  * @brief  Function implementing the TaskMain thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartTaskMain */
void StartTaskMain(void *argument)
{
  /* init code for LWIP */
  MX_LWIP_Init();

  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartTaskMain */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskMain */
}

/* USER CODE BEGIN Header_StartTaskGUI */
/**
* @brief Function implementing the TaskGUI thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskGUI */
void StartTaskGUI(void *argument)
{
  /* USER CODE BEGIN StartTaskGUI */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskGUI */
}

/* USER CODE BEGIN Header_StartTaskBuzzer */
/**
* @brief Function implementing the TaskBuzzer thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskBuzzer */
void StartTaskBuzzer(void *argument)
{
  /* USER CODE BEGIN StartTaskBuzzer */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskBuzzer */
}

/* USER CODE BEGIN Header_StartTaskPSU */
/**
* @brief Function implementing the TaskPSU thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskPSU */
void StartTaskPSU(void *argument)
{
  /* USER CODE BEGIN StartTaskPSU */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskPSU */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
