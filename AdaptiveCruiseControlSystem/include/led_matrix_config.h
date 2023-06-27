/*
 * led_matrix.c
 *
 *  Created on: May 14, 2023
 *      Author: Hager Badr
 */

#ifndef _LED_MATRIX_CONFIG_H_
#define _LED_MATRIX_CONFIG_H_


#define HLEDMAT_ROW_PORT		GPIO_PORTA
#define HLEDMAT_COLUM_PORT		GPIO_PORTB


#define HLEDMAT_R0_PIN			GPIO_PIN1
#define HLEDMAT_R1_PIN          GPIO_PIN2
#define HLEDMAT_R2_PIN          GPIO_PIN3
#define HLEDMAT_R3_PIN          GPIO_PIN7
#define HLEDMAT_R4_PIN          GPIO_PIN8
#define HLEDMAT_R5_PIN          GPIO_PIN11
#define HLEDMAT_R6_PIN          GPIO_PIN12
#define HLEDMAT_R7_PIN          GPIO_PIN15

#define HLEDMAT_C0_PIN			GPIO_PIN0
#define HLEDMAT_C1_PIN          GPIO_PIN1
#define HLEDMAT_C2_PIN          GPIO_PIN2
#define HLEDMAT_C3_PIN          GPIO_PIN3
#define HLEDMAT_C4_PIN          GPIO_PIN4
#define HLEDMAT_C5_PIN          GPIO_PIN5
#define HLEDMAT_C6_PIN          GPIO_PIN6
#define HLEDMAT_C7_PIN          GPIO_PIN7

#endif
