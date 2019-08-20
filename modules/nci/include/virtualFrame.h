/**
 * @file            virtualFrame.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main nci workspace.
 * @author          vgonisanz
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __VIRTUALFRAME_HEADER_FILE_H
#define __VIRTUALFRAME_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>

#include "types.h"
#include "frameContainer.h"

namespace nci
{

class VirtualFrame
{
protected:
    WINDOW *_border;
    WINDOW *_content;

    std::string _id;
    FrameContainer _children;

    int _background_color;
    bool _has_border;

public:
    VirtualFrame() {};
    virtual ~VirtualFrame() {};

    /**
     * \brief Create all windows follow internal variables
     *
     * Constructor use this method, but also setters that reconfigure the widget
     *
     */
    virtual void create(Point2D origin, Size2D size) = 0;
    /**
     * \brief Destroy all windows follow internal variables
     *
     * Destructor use this method, but also setters that reconfigure the widget
     *
     */
    virtual void destroy() = 0;
    /**
     * \brief Dummy method to draw the interface
     */
    virtual void draw() = 0;
    /**
     * \brief Call internal logic to control the interface
     *
     * This method take the control until the execution end
     */
    virtual void run() = 0;

    template <typename F>
    void add(F frame)
    { /// border bug TODO
        Point2D origin;
        getbegyx(_border, origin.y, origin.x);
        _children.add(frame, origin);
    }

    virtual void set_background_color(int color_id) = 0;
};

}   // namespace nci
#endif  /* __VIRTUALFRAME_HEADER_FILE_H */
