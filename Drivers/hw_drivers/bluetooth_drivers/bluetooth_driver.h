/*
 * bluetooth_driver.h
 *
 *  Created on: Feb 7, 2022
 *      Author: anka26
 */

#ifndef BLUETOOTH_DRIVERS_BLUETOOTH_DRIVER_H_
#define BLUETOOTH_DRIVERS_BLUETOOTH_DRIVER_H_

void send_nitro_data_to_bluetooth(uint8_t data);
void send_phos_data_to_bluetooth(uint8_t data);
void send_pota_data_to_bluetooth(uint8_t data);

#endif /* BLUETOOTH_DRIVERS_BLUETOOTH_DRIVER_H_ */
