/**
 * @file            frame.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main nci workspace.
 * @author          vgonisanz
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __FRAME_HEADER_FILE_H
#define __FRAME_HEADER_FILE_H

#include <ncurses.h>

#include "types.h"
#include "virtualFrame.h"
#include "frameContainer.h"

namespace nci
{

class Frame : public VirtualFrame
{
public:
    Frame(std::string id, Point2D origin = Point2D(0, 0), Size2D size = Size2D(1, 1), bool has_border = true);
    ~Frame();

    /**
     * \brief Create all windows follow internal variables
     *
     * Constructor use this method, but also setters that reconfigure the widget
     *
     */
    virtual void create(Point2D origin, Size2D size);
    /**
     * \brief Destroy all windows follow internal variables
     *
     * Destructor use this method, but also setters that reconfigure the widget
     *
     */
    virtual void destroy();
    /**
     * \brief Dummy method to draw the interface
     */
    virtual void draw();
    /**
     * \brief Call internal logic to control the interface
     *
     * This method take the control until the execution end
     */
    virtual void run();
    /**
     * \brief Move the interface
     *
     * This method move all internal windows active.
     * The reference dependes of parent position.
     */
    virtual void move(Point2D origin);
    /**
     * \brief Resize the interface
     *
     * This method resize all internal windows active.
     */
    virtual void resize(Size2D size);
    /**
     * \brief Set up background color
     *
     * By default, it change the color for all elements
     */
    virtual void set_background_color(int color_id);
    /**
     * \brief Put color on windows
     */
    virtual void color_me();
    /**
     * \brief Draw a box around the border
     *
     * This method only draw if border window exist
     */
    virtual void box_me();
    /**
     * \brief Add an attribute when drawing
     *
     * This method use elements from enum TODO
     * Use A_NORMAL to remove all them.
     */
    virtual void add_attribute(int attr);
    /**
     * \brief Remove an attribute when drawing
     *
     * This method use elements from enum TODO
     */
    virtual void remove_attribute(int attr);
    virtual void apply_attributes();
    virtual void unapply_attributes();


    //void set_border(bool value);
    /**
     * \brief Get Point2D to the origin of the content.
     */
    virtual Point2D get_origin() const;

    /**
     * \brief Get Size2D to the origin of the content.
     */
    virtual Size2D get_size() const;
    /**
     * \brief Get Point2D to the origin of the border.
     *
     * If no border exist, return (0, 0)
     */
    virtual Point2D get_border_origin() const;
    /**
     * \brief Get Point2D to the origin of the border.
     *
     * If no border exist, return (0, 0)
     */
    virtual Size2D get_border_size() const;
    /**
     * \brief Get Point2D to the current cursor position.
     */
    virtual Point2D cursor_get_position() const;
    /**
     * \brief Set the cursor at x,y based on length
     */
    virtual void cursor_set_position(uint16_t lenght);
    /**
     * \brief Set the cursor at x,y based on Point2D
     */
    virtual Point2D cursor_set_position(Point2D position);
    /**
     * \brief Move the cursor left
     */
    virtual Point2D cursor_left();
    /**
     * \brief Move the cursor right
     */
    virtual Point2D cursor_right(bool update = true);
    /**
     * \brief Move the cursor up
     */
    virtual Point2D cursor_up();
    /**
     * \brief Move the cursor down
     */
    virtual Point2D cursor_down();



    /**
     * \brief Set border property
     *
     * Change the current value imply destroy and create windows
     */
    virtual void set_border(bool value);
    virtual void set_runnable(bool runnable);
    void keybind(int character, std::function<void()> function);
};

}   // namespace nci
#endif  /* __FRAME_HEADER_FILE_H */
