// File: Inc/uart_frame.h
#ifndef UART_FRAME_H
#define UART_FRAME_H

#include <stdint.h>

#define START_BYTE 0xAA //start byte of Frame

// define structure of a packet frame UART
typedef struct {
    uint8_t start_byte; // (1 byte)
    uint8_t length;     // length of data (1 byte)
    uint8_t cmd_id;     // commnad (1 byte)
    uint8_t *data;      // Pointer to array_data
    uint8_t checksum;   // CRC (1 byte)
} UartFrame;

/*---Function Process---*/
// 1. function cal checksum
uint8_t calculate_checksum(uint8_t length, uint8_t cmd_id, uint8_t *data);

// 2. function packet: To raw data -> create a complete frame
UartFrame pack_frame(uint8_t cmd_id, uint8_t *data,  uint8_t length);

// 3. simulate funtion packet to printf console
void print_frame(UartFrame frame);



#endif