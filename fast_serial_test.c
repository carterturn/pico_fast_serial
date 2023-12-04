#include <stdio.h>
#include "hardware/gpio.h"
#include "fast_serial.h"

const uint LED_PIN = 25;
bool led_state;

#define CDC_BUF_LEN 250000
char cdc_buf[CDC_BUF_LEN];
unsigned int cdc_buf_idx;

int main(){
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	cdc_buf_idx = 0;

	fast_serial_init();

	while(1){
		fast_serial_task();

		cdc_buf_idx = fast_serial_read(cdc_buf, 240001);
		gpio_put(LED_PIN, 1);

		fast_serial_write(cdc_buf, cdc_buf_idx);
		gpio_put(LED_PIN, 0);

		cdc_buf_idx = 0;
	}
}
