/*
 * LED blink with FreeRTOS
 */

#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

volatile int lp1, lp2;

void led_task(void *p)
{
    int gpio = 25;
    int i;

    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
    while (true) {
        for (i = 0; i < lp1; i++)
            gpio_put(gpio, 1);
        for (i = 0; i < lp2; i++)
            gpio_put(gpio, 0);
    }
}

void ctrl_task(void *p)
{
    int s = 2;

    lp1 = 10;
    lp2 = 0;
    while (true) {
        lp2 += s;
        if (lp2 > 100 || lp2 < 0) {
            s = -s;
            lp2 += s;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

int main()
{
    stdio_init_all();
    printf("Start LED blink\n");

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    xTaskCreate(ctrl_task, "Control Task", 256, NULL, 2, NULL);
    vTaskStartScheduler();

    while (true)
        ;
}
