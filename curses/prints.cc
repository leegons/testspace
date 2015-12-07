#include <ncurses.h>
#include <unistd.h>

int main() {

    initscr();
    raw();
    noecho();

    char *map = " abcdefghijklmnopqrstuvwxyz,0123456789().!@#$%^&*-=\\_+|`~[]{};'\":,./<>?";
    char *str = "hello lijian7, you are good people!";
    int x = 10, y = 10;
    move(x, y);

    char* st = str;
    while (*st) {
        int cur = 0;
        do {
            char tmp[100] = {0};
            sprintf(tmp, "%c", map[cur]);
            move(x, y);
            waddstr(stdscr, tmp);
            move(0, 0);
            refresh();
            usleep(50000);
        } while (map[cur++] != *st);
        st++;
        y++;
    }
    sleep(10);
    echo();
    endwin();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
