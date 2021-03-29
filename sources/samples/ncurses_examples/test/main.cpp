#include <ncurses.h>

int main()
{
    int counter, counter2=0;
    initscr();
    curs_set(0);
    attron(A_UNDERLINE);
    mvprintw(0,24,"NCURSES ALTCHARSET CHARACTERS\n");
    attroff(A_UNDERLINE);
    for (counter=43; counter < 256; counter++)
            {
            printw("%3d = ", counter);
            addch(counter | A_ALTCHARSET);
            if (counter2 < 7)
                    {
                    addch(' ');
                    addch(ACS_VLINE);
                    printw(" ");
                    }
            counter2++;
            if (counter2 > 7)
                    {
                    addch('\n');
                    counter2=0;
                    }
            switch (counter)
                    {
                    case 46:
                            counter=47;
                            break;
                    case 48:
                            counter=95;
                            break;
                    case 97:
                            counter=101;
                            break;
                    case 126:
                            counter=127;
                            break;
                    case 128:
                            counter=160;
                            break;
                    case 172:
                            counter=173;
                    }
            }
    getch();
    endwin();
    return 0;
}
