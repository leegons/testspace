#include <ncurses.h>

int main() {

    initscr();
    raw();
    noecho();

    // draw a box
    //box(stdscr, ACS_VLINE, ACS_HLINE);
    box(stdscr, '|', '-');
    // move the cursor to the center
    int x = LINES / 2, y = COLS / 2;
    move(x, y);
    refresh();

    bool f_run = true;
    while (f_run) {
        char c = getch();
        char str[100];
        switch (c) {
            case 'j':
                if (x < LINES - 1) ++x;
                break;
            case 'k':
                if (x > 1) --x;
                break;
            case 'h':
                if (y > 1) --y;
                break;
            case 'l':
                if (y < COLS - 1) ++y;
                break;
            case 'x':
                f_run = false;
                break;
            default:
                sprintf(str, "%c", c);
                waddstr(stdscr, str);
                break;
        }
        move(x, y);
        refresh();
    }
    endwin();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
