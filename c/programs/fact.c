#include "time.h"
#include "utils.h"
#include "print.h"
#include "procs.h"

void fact_main() {
    int fact = 1, i = 1;

    while (fact < 1000000) {
        fact *= i;
        i++;

        for (int i = 0; i < curr_pid; i++) {
            for (int j = 0; j < 30; j++) {
                print(" ");
            }
        }

        print_num(curr_pid);
        print(" ");
        print_hex(get_sp());
        print(" ");
        print_num(fact);
        print_endl();
        sleep(1000);
    }
}
