#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "textFrame.h"
#include "frame.h"


/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;

	std::cout << "I_KEY_DOWN\t\t= " << KEY_DOWN << ", /* down-arrow key */" << std::endl;
	std::cout << "I_KEY_UP\t\t= " << KEY_UP << ", /* up-arrow key */" << std::endl;
	std::cout << "I_KEY_LEFT\t\t= " << KEY_LEFT << ", /* left-arrow key */" << std::endl;
	std::cout << "I_KEY_RIGHT\t\t= " << KEY_RIGHT << ", /* right-arrow key */" << std::endl;
	std::cout << "I_KEY_HOME\t\t= " << KEY_HOME << ", /* home key */" << std::endl;
	std::cout << "I_KEY_BACKSPACE\t\t= " << KEY_BACKSPACE << ", /* backspace key */" << std::endl;
	std::cout << "I_KEY_F0\t\t= " << KEY_F0 << ", /* Function keys.  Space for 64 */" << std::endl;
	//std::cout << "I_KEY_F(n)    (KEY_F0+(n))    /* Value of function key n */" << std::endl;
	std::cout << "I_KEY_DL\t\t= " << KEY_DL << ", /* delete-line key */" << std::endl;
	std::cout << "I_KEY_IL\t\t= " << KEY_IL << ", /* insert-line key */" << std::endl;
	std::cout << "I_KEY_DC\t\t= " << KEY_DC << ", /* delete-character key */" << std::endl;
	std::cout << "I_KEY_IC\t\t= " << KEY_IC << ", /* insert-character key */" << std::endl;
	std::cout << "I_KEY_EIC\t\t= " << KEY_EIC << ", /* sent by rmir or smir in insert mode */" << std::endl;
	std::cout << "I_KEY_CLEAR\t\t= " << KEY_CLEAR << ", /* clear-screen or erase key */" << std::endl;
	std::cout << "I_KEY_EOS\t\t= " << KEY_EOS << ", /* clear-to-end-of-screen key */" << std::endl;
	std::cout << "I_KEY_EOL\t\t= " << KEY_EOL << ", /* clear-to-end-of-line key */" << std::endl;
	std::cout << "I_KEY_SF\t\t= " << KEY_SF << ", /* scroll-forward key */" << std::endl;
	std::cout << "I_KEY_SR\t\t= " << KEY_SR << ", /* scroll-backward key */" << std::endl;
	std::cout << "I_KEY_NPAGE\t\t= " << KEY_NPAGE << ", /* next-page key */" << std::endl;
	std::cout << "I_KEY_PPAGE\t\t= " << KEY_PPAGE << ", /* previous-page key */" << std::endl;
	std::cout << "I_KEY_STAB\t\t= " << KEY_STAB << ", /* set-tab key */" << std::endl;
	std::cout << "I_KEY_CTAB\t\t= " << KEY_CTAB << ", /* clear-tab key */" << std::endl;
	std::cout << "I_KEY_CATAB\t\t= " << KEY_CATAB << ", /* clear-all-tabs key */" << std::endl;
	std::cout << "I_KEY_ENTER\t\t= " << KEY_ENTER << ", /* enter/send key */" << std::endl;
	std::cout << "I_KEY_PRINT\t\t= " << KEY_PRINT << ", /* print key */" << std::endl;
	std::cout << "I_KEY_LL\t\t= " << KEY_LL << ", /* lower-left key (home down) */" << std::endl;
	std::cout << "I_KEY_A1\t\t= " << KEY_A1 << ", /* upper left of keypad */" << std::endl;
	std::cout << "I_KEY_A3\t\t= " << KEY_A3 << ", /* upper right of keypad */" << std::endl;
	std::cout << "I_KEY_B2\t\t= " << KEY_B2 << ", /* center of keypad */" << std::endl;
	std::cout << "I_KEY_C1\t\t= " << KEY_C1 << ", /* lower left of keypad */" << std::endl;
	std::cout << "I_KEY_C3\t\t= " << KEY_C3 << ", /* lower right of keypad */" << std::endl;
	std::cout << "I_KEY_BTAB\t\t= " << KEY_BTAB << ", /* back-tab key */" << std::endl;
	std::cout << "I_KEY_BEG\t\t= " << KEY_BEG << ", /* begin key */" << std::endl;
	std::cout << "I_KEY_CANCEL\t\t= " << KEY_CANCEL << ", /* cancel key */" << std::endl;
	std::cout << "I_KEY_CLOSE\t\t= " << KEY_CLOSE << ", /* close key */" << std::endl;
	std::cout << "I_KEY_COMMAND\t\t= " << KEY_COMMAND << ", /* command key */" << std::endl;
	std::cout << "I_KEY_COPY\t\t= " << KEY_COPY << ", /* copy key */" << std::endl;
	std::cout << "I_KEY_CREATE\t\t= " << KEY_CREATE << ", /* create key */" << std::endl;
	std::cout << "I_KEY_END\t\t= " << KEY_END << ", /* end key */" << std::endl;
	std::cout << "I_KEY_EXIT\t\t= " << KEY_EXIT << ", /* exit key */" << std::endl;
	std::cout << "I_KEY_FIND\t\t= " << KEY_FIND << ", /* find key */" << std::endl;
	std::cout << "I_KEY_HELP\t\t= " << KEY_HELP << ", /* help key */" << std::endl;
	std::cout << "I_KEY_MARK\t\t= " << KEY_MARK << ", /* mark key */" << std::endl;
	std::cout << "I_KEY_MESSAGE\t\t= " << KEY_MESSAGE << ", /* message key */" << std::endl;
	std::cout << "I_KEY_MOVE\t\t= " << KEY_MOVE << ", /* move key */" << std::endl;
	std::cout << "I_KEY_NEXT\t\t= " << KEY_NEXT << ", /* next key */" << std::endl;
	std::cout << "I_KEY_OPEN\t\t= " << KEY_OPEN << ", /* open key */" << std::endl;
	std::cout << "I_KEY_OPTIONS\t\t= " << KEY_OPTIONS << ", /* options key */" << std::endl;
	std::cout << "I_KEY_PREVIOUS\t\t= " << KEY_PREVIOUS << ", /* previous key */" << std::endl;
	std::cout << "I_KEY_REDO\t\t= " << KEY_REDO << ", /* redo key */" << std::endl;
	std::cout << "I_KEY_REFERENCE\t\t= " << KEY_REFERENCE << ", /* reference key */" << std::endl;
	std::cout << "I_KEY_REFRESH\t\t= " << KEY_REFRESH << ", /* refresh key */" << std::endl;
	std::cout << "I_KEY_REPLACE\t\t= " << KEY_REPLACE << ", /* replace key */" << std::endl;
	std::cout << "I_KEY_RESTART\t\t= " << KEY_RESTART << ", /* restart key */" << std::endl;
	std::cout << "I_KEY_RESUME\t\t= " << KEY_RESUME << ", /* resume key */" << std::endl;
	std::cout << "I_KEY_SAVE\t\t= " << KEY_SAVE << ", /* save key */" << std::endl;
	std::cout << "I_KEY_SBEG\t\t= " << KEY_SBEG << ", /* shifted begin key */" << std::endl;
	std::cout << "I_KEY_SCANCEL\t\t= " << KEY_SCANCEL << ", /* shifted cancel key */" << std::endl;
	std::cout << "I_KEY_SCOMMAND\t\t= " << KEY_SCOMMAND << ", /* shifted command key */" << std::endl;
	std::cout << "I_KEY_SCOPY\t\t= " << KEY_SCOPY << ", /* shifted copy key */" << std::endl;
	std::cout << "I_KEY_SCREATE\t\t= " << KEY_SCREATE << ", /* shifted create key */" << std::endl;
	std::cout << "I_KEY_SDC\t\t= " << KEY_SDC << ", /* shifted delete-character key */" << std::endl;
	std::cout << "I_KEY_SDL\t\t= " << KEY_SDL << ", /* shifted delete-line key */" << std::endl;
	std::cout << "I_KEY_SELECT\t\t= " << KEY_SELECT << ", /* select key */" << std::endl;
	std::cout << "I_KEY_SEND\t\t= " << KEY_SEND << ", /* shifted end key */" << std::endl;
	std::cout << "I_KEY_SEOL\t\t= " << KEY_SEOL << ", /* shifted clear-to-end-of-line key */" << std::endl;
	std::cout << "I_KEY_SEXIT\t\t= " << KEY_SEXIT << ", /* shifted exit key */" << std::endl;
	std::cout << "I_KEY_SFIND\t\t= " << KEY_SFIND << ", /* shifted find key */" << std::endl;
	std::cout << "I_KEY_SHELP\t\t= " << KEY_SHELP << ", /* shifted help key */" << std::endl;
	std::cout << "I_KEY_SHOME\t\t= " << KEY_SHOME << ", /* shifted home key */" << std::endl;
	std::cout << "I_KEY_SIC\t\t= " << KEY_SIC << ", /* shifted insert-character key */" << std::endl;
	std::cout << "I_KEY_SLEFT\t\t= " << KEY_SLEFT << ", /* shifted left-arrow key */" << std::endl;
	std::cout << "I_KEY_SMESSAGE\t\t= " << KEY_SMESSAGE << ", /* shifted message key */" << std::endl;
	std::cout << "I_KEY_SMOVE\t\t= " << KEY_SMOVE << ", /* shifted move key */" << std::endl;
	std::cout << "I_KEY_SNEXT\t\t= " << KEY_SNEXT << ", /* shifted next key */" << std::endl;
	std::cout << "I_KEY_SOPTIONS\t\t= " << KEY_SOPTIONS << ", /* shifted options key */" << std::endl;
	std::cout << "I_KEY_SPREVIOUS\t\t= " << KEY_SPREVIOUS << ", /* shifted previous key */" << std::endl;
	std::cout << "I_KEY_SPRINT\t\t= " << KEY_SPRINT << ", /* shifted print key */" << std::endl;
	std::cout << "I_KEY_SREDO\t\t= " << KEY_SREDO << ", /* shifted redo key */" << std::endl;
	std::cout << "I_KEY_SREPLACE\t\t= " << KEY_SREPLACE << ", /* shifted replace key */" << std::endl;
	std::cout << "I_KEY_SRIGHT\t\t= " << KEY_SRIGHT << ", /* shifted right-arrow key */" << std::endl;
	std::cout << "I_KEY_SRSUME\t\t= " << KEY_SRSUME << ", /* shifted resume key */" << std::endl;
	std::cout << "I_KEY_SSAVE\t\t= " << KEY_SSAVE << ", /* shifted save key */" << std::endl;
	std::cout << "I_KEY_SSUSPEND\t\t= " << KEY_SSUSPEND << ", /* shifted suspend key */" << std::endl;
	std::cout << "I_KEY_SUNDO\t\t= " << KEY_SUNDO << ", /* shifted undo key */" << std::endl;
	std::cout << "I_KEY_SUSPEND\t\t= " << KEY_SUSPEND << ", /* suspend key */" << std::endl;
	std::cout << "I_KEY_UNDO\t\t= " << KEY_UNDO << ", /* undo key */" << std::endl;
	std::cout << "I_KEY_MOUSE\t\t= " << KEY_MOUSE << ", /* Mouse event has occurred */" << std::endl;
	std::cout << "I_KEY_RESIZE\t\t= " << KEY_RESIZE << ", /* Terminal resize event */" << std::endl;
	std::cout << "I_KEY_EVENT\t\t= " << KEY_EVENT << ", /* We were interrupted by an event */" << std::endl;
	std::cout << "I_KEY_MAX\t\t= " << KEY_MAX << ", /* Maximum key value is 0633 */" << std::endl;

	return manager.run();
}

int main()
{
	bool result = false;

 	try
	{
		result = run_frontend();
	}
	catch (const std::exception& e)
	{
		nci::tear_down_ncurses();
	}

	if (!result)
		std::cout << "Check the log to see keys" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
