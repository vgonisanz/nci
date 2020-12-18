#ifndef __NCI_IMANAGER_HEADER_FILE_H
#define __NCI_IMANAGER_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "types.h"
#include "frameContainer.h"
#include "popup.h"
#include "imanager.h"

namespace nci
{

class IManager
{
private:
    static WINDOW *_stdscr;
    static bool _initialized;

    static FrameContainer _children;

    std::ofstream _logstream;
    std::string _log_filename;

    int _ch;            /* Store last character readed */
    bool _end_execution;

    std::streambuf *_coutbuf;   /* stdout store pointer */

public:
    IManager();
    ~IManager();

    void init();
    static void redraw();
    bool run();

    void test();
    static Size2D get_size();    /* Return stdscr size */
    static void info();

    template <typename F>
    void add(F frame, Point2D origin = Point2D(0, 0), Size2D parent_size = Size2D(0, 0))
    {
        parent_size = get_size();
        nci::IManager::_children.add(frame, origin, parent_size);
    }
};

} /* namespace nci */
#endif  /* __NCI_IMANAGER_HEADER_FILE_H */
