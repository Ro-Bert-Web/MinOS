#include "utils.h"
#include "print.h"

int fib_main() {
    int i = 0, j = 1;

    while (1) {
        int k = i + j;
        i = j;
        j = k;

        print_num(i);
        print_endl();
        delay(1000000);
    }
}
