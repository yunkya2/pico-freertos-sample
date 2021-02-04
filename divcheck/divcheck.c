/*
 * RP2040 divider check program
 */

#include <FreeRTOS.h>
#include <task.h>
#include <timers.h>
#include <stdio.h>
#include "pico/stdlib.h"

struct div_task_arg {
    int dividend;
    int divisor;
    int result;
};

void div_task(void *p)
{
    struct div_task_arg *a = (struct div_task_arg *)p;
    int result_check;

    while (true) {
        result_check = a->dividend / a->divisor;
        if (a->result != result_check) {
            vTaskSuspendAll();
            printf("Division failure!!!! expected=%d result=%d\n", a->result, result_check);
            xTaskResumeAll();
        }
    }
}

void timerfunc(TimerHandle_t tm)
{
    taskYIELD();
}

int main()
{
    stdio_init_all();
    printf("Start divider test\n");

    struct div_task_arg arg1 = { 1200, 1 , 1200 / 1 };
    xTaskCreate(div_task, "div_task 1", 256, &arg1, 1, NULL);

    struct div_task_arg arg2 = { 1000, 2 , 1000 / 2 };
    xTaskCreate(div_task, "div_task 2", 256, &arg2, 1, NULL);

    struct div_task_arg arg3 = { 900, 3 , 900 / 3 };
    xTaskCreate(div_task, "div_task 3", 256, &arg3, 1, NULL);

    TimerHandle_t tm;
    tm = xTimerCreate("timer 1", 1, pdTRUE, NULL, timerfunc);
    xTimerStart(tm, 0);

    vTaskStartScheduler();

    while (true)
        ;
}
