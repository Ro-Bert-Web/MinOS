#include "time.h"
#include "utils.h"
#include "print.h"
#include "procs.h"

void square_main() {
    int x = 0;

    while (x < 30) {
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
        print_num(x * x);
        print_endl();
        sleep(1000);
    }
}
