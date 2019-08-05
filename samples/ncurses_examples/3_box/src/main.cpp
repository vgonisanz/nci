#include <ncurses.h>

/******************************************************************************/
/* This sample shall draw a box around your terminal.                         */
/* If you see a glitch box, it is a problem with terminfo.                    */
/* To fix execute:                                                            */
// infocmp | sed 's/\(\s\+\)rep=[^,]*,\s*/\1/' | tic - -o ~/.terminfo/        */
/******************************************************************************/

int main()
{
	initscr();
	wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
	refresh();
	getch();
	endwin();
	return 0;
}
