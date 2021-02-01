/*
 * LED blink with FreeRTOS
 */

#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

struct led_task_arg {
    int gpio;
    int delay;
};

void led_task(void *p)
{
    struct led_task_arg *a = (struct led_task_arg *)p;

    gpio_init(a->gpio);
    gpio_set_dir(a->gpio, GPIO_OUT);
    while (true) {
        gpio_put(a->gpio, 1);
        vTaskDelay(pdMS_TO_TICKS(a->delay));
        gpio_put(a->gpio, 0);
        vTaskDelay(pdMS_TO_TICKS(a->delay));
    }
}

int main()
{
    stdio_init_all();
    printf("Start LED blink\n");

    struct led_task_arg arg1 = { 15, 100 };
    xTaskCreate(led_task, "LED_Task 1", 256, &arg1, 1, NULL);

    struct led_task_arg arg2 = { 14, 200 };
    xTaskCreate(led_task, "LED_Task 2", 256, &arg2, 1, NULL);

    struct led_task_arg arg3 = { 13, 300 };
    xTaskCreate(led_task, "LED_Task 3", 256, &arg3, 1, NULL);

    vTaskStartScheduler();

    while (true)
        ;
}
