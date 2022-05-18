/*
 * bluetooth_driver.c
 *
 *  Created on: Feb 7, 2022
 *      Author: anka26
 */
#include <stdio.h>
#include <string.h>
#include "bluetooth_driver.h"
#include "main.h"

extern UART_HandleTypeDef huart1;

void send_nitro_data_to_bluetooth(uint8_t data){

	char send_nitro[16];

	if(1 == data){
		HAL_UART_Transmit(&huart1, (uint8_t*)"N: NULL\n", strlen("N: NULL\n"), 50);
	}
	else{
		sprintf(send_nitro, "N: %d\n", data);
		HAL_UART_Transmit(&huart1, (uint8_t*)send_nitro, strlen(send_nitro), 50);
	}
}

void send_phos_data_to_bluetooth(uint8_t data){

	char send_phos[16];

	if(1 == data){
		HAL_UART_Transmit(&huart1, (uint8_t*)"P: NULL\n", strlen("P: NULL\n"), 50);
	}
	else{
		sprintf(send_phos, "P: %d\n", data);
		HAL_UART_Transmit(&huart1, (uint8_t*)send_phos, strlen(send_phos), 50);
	}
}

void send_pota_data_to_bluetooth(uint8_t data){

	char send_pota[16];

	if(1 == data){
		HAL_UART_Transmit(&huart1, (uint8_t*)"K: NULL\n", strlen("K: NULL\n"), 50);
	}
	else{
		sprintf(send_pota, "K: %d\n", data);
		HAL_UART_Transmit(&huart1, (uint8_t*)send_pota, strlen(send_pota), 50);
	}
}

void send_hum_data_to_bluetooth(uint32_t data){

	char send_hum[16];

	sprintf(send_hum, "Hum: %d\n", data);
	HAL_UART_Transmit(&huart1, (uint8_t*)send_hum, strlen(send_hum), 50);
}

