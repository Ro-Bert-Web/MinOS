#include "time.h"
#include "utils.h"
#include "print.h"
#include "procs.h"

void fib_main() {
    int i = 0, j = 1;

    while (i < 10000) {
        int k = i + j;
        i = j;
        j = k;

        for (int i = 0; i < curr_pid; i++) {
            for (int j = 0; j < 30; j++) {
                print(" ");
            }
        }

        print_num(curr_pid);
        print(" ");
        print_hex(get_sp());
        print(" ");
        print_num(i);
        print_endl();
        sleep(1000);
    }
}
