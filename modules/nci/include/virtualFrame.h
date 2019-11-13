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
#include <functional>

#include "types.h"
#include "frameContainer.h"
#include "keybindingContainer.h"

namespace nci
{

class VirtualFrame
{
protected:
    WINDOW *_border;
    WINDOW *_content;

    std::string _id;
    FrameContainer _children;
    KeybindingContainer _keys;

    int _attributes;
    int _background_color;
    bool _runnable;
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

    /**
     * \brief Get Point2D to the origin of the content.
     */
    virtual Point2D get_origin() const = 0;

    /**
     * \brief Get Size2D to the origin of the content.
     */
    virtual Size2D get_size() const = 0;
    /**
     * \brief Get Point2D to the origin of the border.
     *
     * If no border exist, return (0, 0)
     */
    virtual Point2D get_border_origin() const = 0;
    /**
     * \brief Get Point2D to the origin of the border.
     *
     * If no border exist, return (0, 0)
     */
    virtual Size2D get_border_size() const = 0;

    /**
     * \brief Get Point2D to the current cursor position.
     */
    template <typename F>
    void add(F frame)
    {
        Point2D origin;
        const Size2D parent_size = get_size();

        /* Content shall exist always by design */
        getbegyx(_content, origin.y, origin.x);

        _children.add(frame, origin, parent_size);
    }
    virtual void keybind(int character, std::function<void()> function) = 0;

    virtual void set_background_color(int color_id) = 0;
    virtual void set_runnable(bool runnable) = 0;
    //virtual std::string get_name() const = 0;

};

}   // namespace nci
#endif  /* __VIRTUALFRAME_HEADER_FILE_H */
