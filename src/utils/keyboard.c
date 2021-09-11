#include "keyboard.h"

char get_input_keycode()
{
    char ch = 0;
    while ((ch = inb(KEYBOARD_PORT)) != 0)
    {
        if (ch > 0)
            return ch;
    }
    return ch;
}

void input()
{
    char ch = 0;
    while (ch = inb(KEYBOARD_PORT))
    {
        if (ch == KEY_ENTER)
        {
            outb(KEYBOARD_PORT, 0);
            print_newline();
            break;
        }
        else if (ch == KEY_BACKSPACE)
        {
            clear_char();
            outb(KEYBOARD_PORT, 0);
        }
        else
        {
            ch = get_ascii_char(ch);
            if (ch != 0)
            {
                print_char(ch);
                // c++;
                // ch = 0;
                // realloc(ptr, c);
                // ptr[ch] = ch;
                outb(KEYBOARD_PORT, 0);
            }
        }
    }
}

char get_ascii_char(char keycode)
{
    switch (keycode)
    {
    case KEY_A:
        return 'a';

    case KEY_B:
        return 'b';

    case KEY_C:
        return 'c';

    case KEY_D:
        return 'd';

    case KEY_E:
        return 'e';

    case KEY_F:
        return 'f';

    case KEY_G:
        return 'g';

    case KEY_H:
        return 'h';

    case KEY_I:
        return 'i';

    case KEY_J:
        return 'j';

    case KEY_K:
        return 'k';

    case KEY_L:
        return 'l';

    case KEY_M:
        return 'm';

    case KEY_N:
        return 'n';

    case KEY_O:
        return 'o';

    case KEY_P:
        return 'p';

    case KEY_Q:
        return 'q';

    case KEY_R:
        return 'r';

    case KEY_S:
        return 's';

    case KEY_T:
        return 't';

    case KEY_U:
        return 'u';

    case KEY_V:
        return 'V';

    case KEY_X:
        return 'x';

    case KEY_Y:
        return 'y';

    case KEY_Z:
        return 'z';

    case KEY_SPACE:
        return ' ';

    default:
        return 0;
    }
}