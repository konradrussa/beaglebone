/**
 * @file rc_test_lidar.c
 *
 * This is meant to be a skeleton program for robotics cape projects. Change
 * this description and file name before starting your own.
 */

#include <stdio.h>
#include <roboticscape.h> // includes ALL robotics cape subsystems

#define I2C_BUS 1
#define LIDAR_ADDR 0x62 // Lidar Lite V3 address
#define W_REG_1 0x00
#define W_REG_1_BYTE 0x04
#define R_REG_1 0x01
#define R_REG_2 0x8F

static bool sensor_busy()
{
	int res;
	uint8_t status = 0xFF;

	if ((res = rc_i2c_read_byte(I2C_BUS, R_REG_1, &status)) != 0)
	{
		printf("failed to read status from I2C: %d\n", res);
		return true;
	}
	return status & R_REG_1;
}


int main()
{
	int res;
	res= rc_i2c_init(I2C_BUS, LIDAR_ADDR);
	
	if(res !=0) {
		printf("Failed to rc_i2c_init%d\n", I2C_BUS);
        	return -1;
	}
	
	//while (sensor_busy())
	//	usleep(1000);
	
	res = rc_i2c_write_byte(I2C_BUS, W_REG_1, W_REG_1_BYTE);
	if(res !=0) {
                printf("Failed to write to %d\n", I2C_BUS);
        } else {
		uint16_t reading;
		if((res = rc_i2c_read_word(1, R_REG_2, &reading)) != 0)
		{
			printf("Failed to read :(");
		} else {
			printf("Reading is %u\n", reading);
		}
	}

	rc_i2c_close(I2C_BUS);
	return 0;
}
