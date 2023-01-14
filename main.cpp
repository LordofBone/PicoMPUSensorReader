#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "mpu6050.h"
#define SCL 1
#define SDA 0
int main()
{
	stdio_init_all();

	i2c_init(I2C_PORT, 100000);
	gpio_set_function(SCL, GPIO_FUNC_I2C);
	gpio_set_function(SDA, GPIO_FUNC_I2C);
	gpio_pull_up(SCL);
	gpio_pull_up(SDA);

	int16_t accelerometer[3], gyro[3], temp;
	mpu6050_reset();
	while (1)
	{
		mpu6050_read(accelerometer, gyro, &temp);
		// accX, accY, accZ, gyroX, gyroY, gyroZ
		printf("%d,%d,%d,%d,%d,%d\n", accelerometer[0], accelerometer[1], accelerometer[2], gyro[0], gyro[1], gyro[2]);

		sleep_ms(1);
	}

	return 0;
}