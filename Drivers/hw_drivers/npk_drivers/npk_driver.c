/*
 * npk_driver.c
 *
 *  Created on: Feb 2, 2022
 *      Author: anka26
 */
#include <stdio.h>
#include "npk_driver.h"
#include "main.h"

UART_HandleTypeDef huart6;

uint8_t get_nitrogen_data(void){

	uint8_t nitroAdd[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
	uint8_t nitroVal[9] = {0};
	uint8_t nitroRet;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	HAL_Delay(10);
	if(HAL_UART_Transmit(&huart6, nitroAdd, sizeof(nitroAdd),50) == HAL_OK){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

		HAL_UART_Receive(&huart6, (uint8_t*)nitroVal, sizeof(nitroVal),200);

		if(nitroVal[0]==0 && nitroVal[1]==1 && nitroVal[2]==3 && nitroVal[3]==2){

			nitroRet = nitroVal[5];
		}
		else{

			nitroRet = (uint8_t)1;
		}
	}
	return nitroRet;
}

uint8_t get_phosphorous_data(void){

	uint8_t phosAdd[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
	uint8_t phosVal[9] = {0};
	uint8_t phosRet;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	HAL_Delay(10);
	if(HAL_UART_Transmit(&huart6, phosAdd, sizeof(phosAdd),50) == HAL_OK){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

		HAL_UART_Receive(&huart6, (uint8_t*)phosVal, sizeof(phosVal),200);

		if(phosVal[0]==0 && phosVal[1]==1 && phosVal[2]==3 && phosVal[3]==2){

			phosRet = phosVal[5];
		}
		else{

			phosRet = (uint8_t)1;
		}
	}
	return phosRet;
}

uint8_t get_potassium_data(void){

	uint8_t potaAdd[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
	uint8_t potaVal[9] = {0};
	uint8_t potaRet;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	HAL_Delay(10);
	if(HAL_UART_Transmit(&huart6, potaAdd, sizeof(potaAdd),50) == HAL_OK){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

		HAL_UART_Receive(&huart6, (uint8_t*)potaVal, sizeof(potaVal),200);

		if(potaVal[0]==0 && potaVal[1]==1 && potaVal[2]==3 && potaVal[3]==2){

			potaRet = potaVal[5];
		}
		else{

			potaRet = (uint8_t)1;
		}

	}
	return potaRet;
}

//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
//
//}
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
//
//}
