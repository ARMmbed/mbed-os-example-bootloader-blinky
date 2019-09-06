#include "mbed.h"

DigitalOut led1(LED1);

// main() runs in its own thread in the OS
// (note the calls to wait below for delays)
int main() {
    while (true) {
        led1 = !led1;
        wait(0.5);
        printf("hello, world\r\n");
    }
}

