#include "libraries/sys.h"

#include "libraries/print.h"

u32 handle_sys_call(u32 code) {
    print("System Call\n");
    switch (code) {
        default:
            return -1;
    }
}
