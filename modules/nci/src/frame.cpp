#include "frame.h"

#include <string> 
#include <ncurses.h>
#include <sstream>

#include "utils.h"
#include "popup.h"
#include <imanager.h>

namespace nci
{

Frame::Frame(std::string id, Point2D origin, Size2D size, bool has_border)
{
    _runnable = false;
    _has_border = has_border;
    _id = id;
    _background_color = 0;
    _attributes = A_NORMAL;
    _is_selected = false;
    _ch = -1;
    _end_execution = false;

    create(origin, size);
}

Frame::~Frame()
{
    std::cout << "Destroying frame: " << _id << std::endl;
    destroy();
}

void Frame::create(Point2D origin, Size2D size)
{
    std::cout << "Create frame: " << _id
        << " origin (" << origin.x << ", " << origin.y << ")"
        << " size (" << size.width << ", " << size.height << ")"
        << std::endl;

    if(_has_border)
    {
        _border = newwin(size.height, size.width, origin.y, origin.x);
        keypad(_border, true);

        if(_border == nullptr)
            std::cout << "Warning: border created is a nullptr, maybe not call initscr before create Frame" << std::endl;

        size -= 2;
        origin += 1;
    }

    _content = newwin(size.height, size.width, origin.y, origin.x);
    keypad(_content, true);

    if(_content == nullptr)
        std::cout << "Warning: border created is a nullptr, maybe not call initscr before create Frame" << std::endl;
}

void Frame::destroy()
{
    /* "free" smart pointers */
    _children.clear();

    if(_has_border)
        delwin(_border);
    delwin(_content);
}

void Frame::draw()
{
    std::cout << "draw: " << _id << std::endl;

    color_me();
    box_me();
    border_selected();
    wrefresh(_content);
    _children.draw();
}

void Frame::move(Point2D origin)
{
    Point2D original = get_origin();

    if(_has_border)
    {
        mvwin(_border, origin.y, origin.x);
        origin += 1;
    }
    mvwin(_content, origin.y, origin.x);

    std::cout << "move: " << _id
    << " from (" << original.x << "," << original.y << ")"
    << " to (" << origin.x << "," << origin.y << ")"
    << std::endl;
}

void Frame::resize(Size2D size)
{
    Size2D original = get_size();
    std::cout << "resize: " << _id
        << " from (" << original.width << "," << original.height << ")"
        << " to (" << size.width << "," << size.height << ")"
        << std::endl;
    if(_has_border)
    {
        wresize(_border, size.height, size.width);
        size -= 2;
    }
    wresize(_content, size.height, size.width);
}

void Frame::run()
{
    std::cout << "run: " << _id << std::endl;

    /* Frame and children no run if not active */
    if(!_runnable)
        return;
    
    set_selected(true);
    draw();
    for(auto child: _children)
        child->run();
    
    _keys.run();
    
    set_selected(false);
    draw();
    /* _ch = getch(); // Block for a new entry
    
        switch(_ch)
        {
            case 'q':
                _end_execution = true;
                clear();
                mvaddstr(0,0, "User end execution. Push any button...");
                getch();
                break;
            case 'n':
                draw();
                break;
            case 'h':
                //generate_help_pop_from_keybinding();
                _keys.run();
                break;
            default:
                break;
        }
     */
}

void Frame::set_background_color(int color_id)
{
    _background_color = color_id;
}

int Frame::get_background_color() const
{   
    int color = _background_color;
    return color;
}


void Frame::set_selected(bool highlight)
{
    _is_selected = highlight;
}

bool Frame::get_selected() const
{
    return _is_selected;
}

void Frame::box_me()
{
    if(!_has_border)
        return;

    box(_border, _id);
    wrefresh(_border);
}

void Frame::add_attribute(int attr)
{
    _attributes |= attr;
}


void Frame::remove_attribute(int attr)
{
    _attributes ^= attr;
}

void Frame::apply_attributes()
{
    wattron(_content, _attributes);

    Point2D cursor;
    getyx(_content, cursor.y, cursor.x);

    Size2D size = get_size();
    for(int i = 0; i < size.height; i++)
    {
        mvwchgat(_content, i, 0, -1, _attributes, 3, nullptr);
    }
    wmove(_content, cursor.y, cursor.x);
}

void Frame::unapply_attributes()
{
    wattroff(_content, _attributes);

    Point2D cursor;
    getyx(_content, cursor.y, cursor.x);

    Size2D size = get_size();
    for(int i = 0; i < size.height; i++)
    {
        mvwchgat(_content, i, 0, -1, _attributes, 3, nullptr);
    }
    wmove(_content, cursor.y, cursor.x);
}

void Frame::color_me()
{
    if(_has_border)
        wbkgd(_border, COLOR_PAIR(_background_color));
    wbkgd(_content, COLOR_PAIR(_background_color));
}

void Frame::border_selected()
{
    if(!_has_border)
        return;

    if(get_selected())
        wbkgd(_border, A_REVERSE);
    else
        color_me();
    
    wrefresh(_border);
}

Point2D Frame::get_origin() const
{
    Point2D origin;
    if(_has_border)
        getbegyx(_border, origin.y, origin.x);
    else
        getbegyx(_content, origin.y, origin.x);
    return origin;
}

Size2D Frame::get_size() const
{
    Size2D size;
    if(_has_border)
        getmaxyx(_border, size.height, size.width);
    else
        getmaxyx(_content, size.height, size.width);
    return size;
}

Point2D Frame::get_border_origin() const
{
    Point2D origin;
    if(_has_border)
        getbegyx(_border, origin.y, origin.x);
    return origin;
}

Size2D Frame::get_border_size() const
{
    Size2D size;
    if(_has_border)
        getmaxyx(_border, size.height, size.width);
    return size;
}

void Frame::cursor_set_position(uint16_t lenght)
{
    const Size2D size = get_size();
    uint16_t y = lenght / size.width;
    uint16_t x = lenght % size.width;
    wmove(_content, y, x);
}

Point2D Frame::cursor_set_position(Point2D position)
{
    /* limit */
    Size2D size = get_size();
    if(position.y >= size.height)
        position.y = size.height - 1;
    if(position.x >= size.width)
        position.x = size.width - 1;
    wmove(_content, position.y, position.x);
    return position;
}

Point2D Frame::cursor_get_position() const
{
    Point2D origin;
    getyx(_content, origin.y, origin.x);
    return origin;
}

Point2D Frame::cursor_left()
{
    Point2D current = cursor_get_position();
    Size2D size = get_size();

    if(current.x == 0)
    {
        if(current.y == 0)
            return current;

        current.x = size.width - 1;
        current.y -= 1;
    }
    else
    {
        current.x -= 1;
    }
    cursor_set_position(current);
    return current;
}

Point2D Frame::cursor_right()
{
    Point2D current = cursor_get_position();
    Size2D size = get_size();

    if(current.x >= size.width - 1)
    {
        if(current.y >= size.height - 1)
            return current;

        current.x = 0;
        current.y += 1;
    }
    else
    {
        current.x += 1;
    }
    cursor_set_position(current);
    return current;
}

Point2D Frame::cursor_up()
{
    Point2D current = cursor_get_position();

    if(current.y == 0)
        return current;

    current.y -= 1;
    cursor_set_position(current);
    return current;
}

Point2D Frame::cursor_down()
{
    Point2D current = cursor_get_position();
    Size2D size = get_size();

    if(current.y >= size.height - 1)
        return current;

    current.y += 1;
    cursor_set_position(current);

    return current;
}

void Frame::set_border(bool value)
{
    Point2D origin;
    Size2D size;

    if(_has_border)
    {
        origin = get_border_origin();
        size = get_border_size();
    }
    else
    {
        origin = get_origin();
        size = get_size();
    }

    destroy();
    _has_border = value;
    create(origin, size);
}

void Frame::set_runnable(bool runnable)
{
    std::cout << "Setting " << _id << " runnable: " << runnable << std::endl;
    _runnable = runnable;
}

void Frame::keybind(int character, std::function<void()> function)
{
    _keys.add(character, function);
}

void test()
{
        std::cout << "test" << std::endl;
}

void Frame::generate_help_pop_from_keybinding()
{
    std::cout << "Generating help popup" << std::endl;
	std::shared_ptr<nci::Popup> help_popup(new nci::Popup("Help Popup"));
    _help_popup = help_popup;
	_help_popup->set_background_color(2);
	_help_popup->set_title("Informative popup - " + _id);
	_help_popup->set_text("Hello world popup in da jaus!");
    set_runnable(true);
    keybind('h', std::bind(&Popup::run, _help_popup));
}

} /* namespace nci */
