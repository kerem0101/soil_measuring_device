/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "../../16x2Lcd/LCD16x2.h"
#include "../../16x2Lcd/LCD16x2.c"
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
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
uint8_t nitrogen(void);
uint8_t phosphorous(void);
uint8_t potassium(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
uint8_t phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
uint8_t pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};

uint8_t val_nitro[9] = {0};
uint8_t val_phos[9] = {0};
uint8_t val_pota[9] = {0};

char temp_nitro[16];
char temp_phos[16];
char temp_pota[16];

uint8_t r_nitro;
uint8_t r_phos;
uint8_t r_pota;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t lcd_nitro, lcd_phos, lcd_pota;
  uint8_t lcd_nitro_previous, lcd_phos_previous, lcd_pota_previous;
  uint8_t lcd_nitro_previous2, lcd_phos_previous2, lcd_pota_previous2;
  uint8_t lcd_nitro_previous3, lcd_phos_previous3, lcd_pota_previous3;
  uint8_t lcd_nitro_previous4, lcd_phos_previous4, lcd_pota_previous4;
  uint8_t lcd_nitro_previous5, lcd_phos_previous5, lcd_pota_previous5;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USART6_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
  LCD_Clear();
  LCD_Set_Cursor(1, 1);
  LCD_Write_String("Baslatiliyor...");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	HAL_Delay(3000);

	lcd_nitro = nitrogen();
	lcd_phos = phosphorous();
	lcd_pota = potassium();

	if(lcd_nitro == 0 && lcd_phos == 0 && lcd_pota == 0){
		LCD_Set_Cursor(1, 1);
		LCD_Write_String("Olcume Hazir!  ");
	}
	else if(lcd_nitro != 0 && lcd_nitro != 1 && lcd_phos != 0 && lcd_phos != 1 && lcd_pota != 0 && lcd_pota != 1){
		LCD_Set_Cursor(1, 1);
		LCD_Write_String("Olcum Basliyor!");

		if(lcd_nitro == lcd_nitro_previous5 && lcd_phos == lcd_phos_previous5 && lcd_pota == lcd_pota_previous5){
			LCD_Set_Cursor(1, 1);
			LCD_Write_String("Olcum Tamamlandi!");

			return 0;
		}
	}
	lcd_nitro_previous5 = lcd_nitro_previous4;
	lcd_phos_previous5 = lcd_phos_previous4;
	lcd_pota_previous5 = lcd_pota_previous4;

	lcd_nitro_previous4 = lcd_nitro_previous3;
	lcd_phos_previous4 = lcd_phos_previous3;
	lcd_pota_previous4 = lcd_pota_previous3;

	lcd_nitro_previous3 = lcd_nitro_previous2;
	lcd_phos_previous3 = lcd_phos_previous2;
	lcd_pota_previous3 = lcd_pota_previous2;

	lcd_nitro_previous2 = lcd_nitro_previous;
	lcd_phos_previous2 = lcd_phos_previous;
	lcd_pota_previous2 = lcd_pota_previous;

	lcd_nitro_previous = lcd_nitro;
	lcd_phos_previous = lcd_phos;
	lcd_pota_previous = lcd_pota;

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 4800;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC10 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
uint8_t nitrogen(void){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	HAL_Delay(10);
	if(HAL_UART_Transmit(&huart6, nitro, sizeof(nitro), 50) == 0){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

		HAL_UART_Receive(&huart6, (uint8_t*)val_nitro, sizeof(val_nitro), 200);

		if(val_nitro[0]==0 && val_nitro[1]==1 && val_nitro[2]==3 && val_nitro[3]==2){

			sprintf(temp_nitro, "N: %d\n", val_nitro[5]);
			HAL_UART_Transmit(&huart1, (uint8_t*)temp_nitro, strlen(temp_nitro), 50);

			r_nitro = val_nitro[5];
		}
		else{
			HAL_UART_Transmit(&huart1, (uint8_t*)"N: NULL\n", strlen("N: NULL\n"), 50);

			r_nitro = (uint8_t)1;
		}
	}
	return r_nitro;
}

uint8_t phosphorous(void){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	HAL_Delay(10);
	if(HAL_UART_Transmit(&huart6, phos, sizeof(phos), 50) == 0){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

		HAL_UART_Receive(&huart6, (uint8_t*)val_phos, sizeof(val_phos), 200);

		if(val_phos[0]==0 && val_phos[1]==1 && val_phos[2]==3 && val_phos[3]==2){

			sprintf(temp_phos, "P: %d\n", val_phos[5]);
			HAL_UART_Transmit(&huart1, (uint8_t*)temp_phos, strlen(temp_phos), 50);

			r_phos = val_phos[5];
		}
		else{
			HAL_UART_Transmit(&huart1, (uint8_t*)"P: NULL\n", strlen("P: NULL\n"), 50);

			r_phos = (uint8_t)1;
		}
	}
	return r_phos;
}

uint8_t potassium(void){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	HAL_Delay(10);
	if(HAL_UART_Transmit(&huart6, pota, sizeof(pota), 50) == 0){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

		HAL_UART_Receive(&huart6, (uint8_t*)val_pota, sizeof(val_pota), 200);

		if(val_pota[0]==0 && val_pota[1]==1 && val_pota[2]==3 && val_pota[3]==2){

			sprintf(temp_pota, "K: %d\n", val_pota[5]);
			HAL_UART_Transmit(&huart1, (uint8_t*)temp_pota, strlen(temp_pota), 50);

			r_pota = val_pota[5];
		}
		else{
			HAL_UART_Transmit(&huart1, (uint8_t*)"K: NULL\n", strlen("K: NULL\n"), 50);

			r_pota = (uint8_t)1;
		}

	}
	return r_pota;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
