/*========================================
 *    sl.c: SL version 5.03
 *        Copyright 1993,1998,2014-2015
 *                  Toyoda Masashi
 *                  (mtoyoda@acm.org)
 *        Last Modified: 2014/06/03
 *========================================
 */

#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "goheels.h"

int add_D51(int x);
int my_mvaddstr(int y, int x, char *str);

int main(int argc, char *argv[])
{
    int x;

    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1;; --x)
    {
        if (add_D51(x) == ERR)
            break;
        getch();
        refresh();
        usleep(40000);
    }
    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();

    return 0;
}

int my_mvaddstr(int y, int x, char *str)
{
    for (; x < 0; ++x, ++str)
        if (*str == '\0')
            return ERR;
    for (; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)
            return ERR;
    return OK;
}

int add_D51(int x)
{
    static char *d51[D51PATTERNS][D51HEIGHT + 1] =
        {{D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
          D51WHL11, D51WHL12, D51WHL13, D51DEL},
         {D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
          D51WHL21, D51WHL22, D51WHL23, D51DEL},
         {D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
          D51WHL31, D51WHL32, D51WHL33, D51DEL},
         {D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
          D51WHL41, D51WHL42, D51WHL43, D51DEL},
         {D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
          D51WHL51, D51WHL52, D51WHL53, D51DEL},
         {D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
          D51WHL61, D51WHL62, D51WHL63, D51DEL}};
    static char *coal[D51HEIGHT + 1] =
        {COAL01, COAL02, COAL03, COAL04, COAL05,
         COAL06, COAL07, COAL08, COAL09, COAL10, COALDEL};

    int y, i, dy = 0;

    if (x < -D51LENGTH)
        return ERR;
    y = LINES / 2 - 5;

    for (i = 0; i <= D51HEIGHT; ++i)
    {
        my_mvaddstr(y + i, x, d51[(D51LENGTH + x) % D51PATTERNS][i]);
        my_mvaddstr(y + i + dy, x + 53, coal[i]);
    }
    // add_smoke(y - 1, x + D51FUNNEL);
    return OK;
}