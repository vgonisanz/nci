#include "nci.h"

namespace nci
{

WINDOW* initialize_ncurses()
{

    WINDOW* general = initscr();
    raw();				            /* Line buffering disabled */
	keypad(stdscr, TRUE);	        /* We get F1, F2... */
	noecho();			            /* Don't echo() while we do getch */
    cbreak();

    /* Trick to avoid have to call getch to start drawing: TODO why is happening */
    nodelay(stdscr, TRUE);
    getch();
    nodelay(stdscr, FALSE);

    curs_set(CURSOR::INVISIBLE);
    if (has_colors())
    {
        use_default_colors();
        start_color();                  /* Allow color */
        if (can_change_color())         // TODO pallete colors
        {
            init_pair(1, COLOR_WHITE, COLOR_WHITE);
            init_pair(2, COLOR_WHITE, COLOR_BLACK);
            init_pair(3, COLOR_WHITE, COLOR_RED);
            init_pair(4, COLOR_WHITE, COLOR_GREEN);
            init_pair(5, COLOR_WHITE, COLOR_YELLOW);
            init_pair(6, COLOR_WHITE, COLOR_BLUE);
            init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
            init_pair(8, COLOR_WHITE, COLOR_CYAN);
            init_pair(9, COLOR_WHITE, COLOR_MAGENTA);
            init_pair(10, COLOR_WHITE, COLOR_MAGENTA);
        }
    }
    return general;
}

void tear_down_ncurses()
{
    /* Ncurses tear down */
    noraw();
    endwin();
}

void feedback_ncurses(bool print)
{
    if(print)
    {
        //echo();
        curs_set(1);
    }
    else
    {
        //noecho();
        curs_set(0);
    }
}

} /* namespace nci */
