/**
 * @file rc_uart_loopback.c
 * @example    rc_uart_loopback
 *
 * This is a test to check read and write operation of UART buses. For this
 * example to work, connect the RX and TX wires of one of the included 4-pin
 * JST-SH pigtails and plug into the UART1 or UART5 headers. You may also elect
 * to test UART0 on the debug header or UART2 on the GPS header. The test
 * strings this programs transmits will then loopback to the RX channel.
 */
#include <stdio.h>
#include <stdlib.h> // for atoi
#include <string.h>
#include <rc/uart.h>
#define BUF_SIZE    8
#define TIMEOUT_S   1.0
#define BAUDRATE    19200

#define header_H    0x55 //Header
#define header_L    0xAA //Header
#define device_Addr 0x11 //Address
#define data_Length 0x00 //Data length
#define get_Dis_CMD 0x02 //Command: Read Distance
#define checksum    (header_H+header_L+device_Addr+data_Length+get_Dis_CMD) //Checksum


unsigned int distance;
int temp;
char bytes_array[] = {header_H,header_L,device_Addr,data_Length,get_Dis_CMD,checksum};

int main(int argc, char *argv[])
{
    char buf[BUF_SIZE];
    int ret; // return value
    int bus = 5; // which bus to use
    int length = 6; //sizeof(bytes)    

    printf("\nUltrasonic testing UART bus %d\n\n", bus);
    // disable canonical (0), 1 stop bit (1), disable parity (0)
    if(rc_uart_init(bus, BAUDRATE, TIMEOUT_S, 0,1,0)){
        printf("Failed to rc_uart_init%d\n", bus);
        return -1;
    }
   	
    
    // Flush and Write
    printf("Sending  %d bytes\n", length);
    rc_uart_flush(bus);
    rc_uart_write(bus, &bytes_array[0], length);
    
    // Read
    printf("reading bytes:\n");
    memset(buf,0,sizeof(buf));
    if(rc_uart_bytes_available(bus) != -1) {
	ret = rc_uart_read_line(bus, buf, length);
    	ret = rc_uart_read_bytes(bus, buf, length);
    	if(ret<0) { fprintf(stderr,"Error reading bus\n");}
    	else if(ret==0) { printf("timeout reached, %d bytes read\n", ret);}
    	else{
		distance = buf[0];
 		printf("Distance %d \n", distance);
	}
    }

    // close
    rc_uart_close(bus);
    return 0;
}
