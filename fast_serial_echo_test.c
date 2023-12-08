#include <stdio.h>
#include "hardware/gpio.h"
#include "fast_serial.h"

const uint LED_PIN = 25;
bool led_state;

#define CDC_BUF_LEN 512
char cdc_buf[CDC_BUF_LEN];
unsigned int cdc_buf_idx;

int main(){
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	cdc_buf_idx = 0;

	fast_serial_init();

	while(1){
		memset(cdc_buf, 0, CDC_BUF_LEN);
		cdc_buf_idx = 0;

		fast_serial_task();

		cdc_buf_idx = fast_serial_read_until(cdc_buf, CDC_BUF_LEN, '\n');
		fast_serial_printf(cdc_buf);
		fast_serial_printf("Response should have been %d bytes\n", cdc_buf_idx);
	}
}
