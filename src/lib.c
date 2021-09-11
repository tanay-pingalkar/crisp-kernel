#include "utils/print.h"
#include "utils/keyboard.h"

void kernel_main()
{
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    while (1 == 1)
    {
        print_str("$ ");
        input();
    };
}