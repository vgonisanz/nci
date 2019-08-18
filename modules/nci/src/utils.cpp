#include "utils.h"

namespace nci
{

    void box(WINDOW* win, std::string id)
    {
        uint16_t x, y, w, h;

        x = 0;
        y = 0;

        getmaxyx(win, h, w);
        w -= 1;
        h -= 1;

        std::cout << "box_me " << id << " from: (" << x << ", " << y << ") ->"
            << "(" << (x + w) << ", " << (y + h) << ")" << std::endl;

        /* corners */
        mvwaddch(win, y, x, ACS_ULCORNER);
        mvwaddch(win, y, w, ACS_URCORNER);
        mvwaddch(win, h, x, ACS_LLCORNER);
        mvwaddch(win, h, w, ACS_LRCORNER);

        /* top line */
        for(uint16_t i = x + 1; i < w; ++i)
            mvwaddch(win, y, i, ACS_HLINE);

        /* bot line */
        for(uint16_t i = x + 1; i < w; ++i)
            mvwaddch(win, h, i, ACS_HLINE);

        /* left line */
        for(uint16_t i = y + 1; i < h; ++i)
            mvwaddch(win, i, x, ACS_VLINE);

        /* right line */
        for(uint16_t i = y + 1; i < h; ++i)
            mvwaddch(win, i, w, ACS_VLINE);
    }

} /* namespace nci */
