#include <stdio.h>
#include <stdint.h>
#include "uart_frame.h"

int main() {
    printf("--- HE THONG GIA LAP UART PACKET ---\n\n");

    uint8_t data_led[] = {0x01}; 
    UartFrame frame_led = pack_frame(0x01, data_led, 1);
    printf("Data led:"); 
    print_frame(frame_led);

    uint8_t data_sensor[] = {25, 60}; 
    UartFrame frame_sensor = pack_frame(0x02, data_sensor, 2);
    print_frame(frame_sensor);

    return 0;
}