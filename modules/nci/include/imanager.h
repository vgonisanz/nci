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
#include "frame.h"

namespace nci
{

class IManager
{
private:
    static WINDOW *_stdscr;

    std::ofstream _logstream;
    std::string _log_filename;

    int _ch;            /* Store last character readed */
    bool _end_execution;

    std::vector<std::shared_ptr<Frame> > _frames;

    std::streambuf *_coutbuf;   /* stdout store pointer */

public:
    IManager();
    ~IManager();

    void init();
    void redraw();
    bool run();

    void add_frame(std::shared_ptr<Frame> frame);

    Size2D get_size();    /* Return stdscr size */
    void test();
    static void info();
};

} /* namespace nci */
#endif  /* __NCI_IMANAGER_HEADER_FILE_H */
