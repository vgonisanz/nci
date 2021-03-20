#include <ncurses.h>

int main()
{
	int ch;

	initscr();			/* Start curses mode 		*/
	start_color();		/* Start the color functionality */
	cbreak();			/* Line buffering disabled, Pass on
					 	 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	noecho();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	attron(COLOR_PAIR(1));
	printw("Press F1 to exit\n");
	refresh();
	attroff(COLOR_PAIR(1));

	while((ch = getch()) != KEY_F(1))
	{
		switch(ch)
		{	case KEY_LEFT:
				printw("KEY_LEFT\n");
				break;
			case KEY_RIGHT:
				printw("KEY_RIGHT\n");
				break;
			case KEY_UP:
				printw("KEY_UP\n");
				break;
			case KEY_DOWN:
				printw("KEY_DOWN\n");
				break;
		}
	}
	endwin();
	return 0;
}
