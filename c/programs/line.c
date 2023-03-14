#include "utils.h"
#include "print.h"
#include "procs.h"

void line_main() {
    int x = 0;

    while (1) {
        x++;

        for (int i = 0; i < curr_pid; i++) {
            for (int j = 0; j < 30; j++) {
                print(" ");
            }
        }

        print_num(curr_pid);
        print(" ");
        print_hex(get_sp());
        print(" ");
        print_num(x);
        print_endl();
        delay(1000000);
    }
}
