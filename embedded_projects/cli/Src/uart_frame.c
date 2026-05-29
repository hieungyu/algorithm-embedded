// File: Src/uart_frame.c
// Author: Hieu_self-study

#include <stdint.h>
#include <stdio.h>
#include "uart_frame.h"

// 1. Function cal checksum (sum += length + cmd + byte datas)
uint8_t calculate_checksum( uint8_t length,uint8_t cmd_id, uint8_t *data){
    uint8_t sum = 0;
    for(int i = 0; i < length; i++){
        sum += data[i];  
    }
    return sum;
}

// 2. Function packet: input raw data to Frame
UartFrame pack_frame(uint8_t cmd_id, uint8_t *data,  uint8_t length){
    UartFrame frame;
    frame.start_byte = START_BYTE;
    frame.length = length;
    frame.cmd_id = cmd_id;
    frame.data = data;
    // call check to ensure frame ok
    frame.checksum = calculate_checksum(length, cmd_id, data);
    
    return frame;
}

// 3. Function printf console to test (HEX)
void print_frame(UartFrame frame)
{
    printf("[UART TX] ");

    printf("%02X ", frame.start_byte);
    printf("%02X ", frame.length);
    printf("%02X ", frame.cmd_id);

    for (int i = 0; i < frame.length; i++) {
        printf("%02X ", frame.data[i]);
    }

    printf("%02X\n", frame.checksum);
}
