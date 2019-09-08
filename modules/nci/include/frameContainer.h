/**
 * @file            frameContainer.h
 * @version         1.0
 * @date            August 2019
 * @brief           Frame container to manage children elements.
 * @author          vgonisanz
 *
 * @license LGPL v3.0
 */
#ifndef __FRAMECONTAINER_HEADER_FILE_H
#define __FRAMECONTAINER_HEADER_FILE_H

#include <memory>
#include <vector>

#include "types.h"

namespace nci
{
class VirtualFrame;

class FrameContainer
{
private:
    std::vector<std::shared_ptr<VirtualFrame> > _frames;

public:
    FrameContainer();
    ~FrameContainer();

    /* Iterator for frames: TODO test properly */
    using iterator = std::vector<std::shared_ptr<VirtualFrame> >::iterator;
    using const_iterator = std::vector<std::shared_ptr<VirtualFrame> >::const_iterator;
    iterator begin() { return _frames.begin(); }
    iterator end() { return _frames.end(); }
    const_iterator begin() const { return _frames.begin(); }
    const_iterator end() const { return _frames.end(); }
    const_iterator cbegin() const { return _frames.cbegin(); }
    const_iterator cend() const { return _frames.cend(); }

    uint32_t size() { return _frames.size(); }
    bool empty() { return _frames.empty(); }
    void clear() { _frames.clear(); }
    std::shared_ptr<VirtualFrame> at(uint32_t index) { return _frames.at(index); }

    void draw();
    // run_once
    // run

    template <typename F>
    void add(F frame, Point2D origin = Point2D(0, 0), Size2D parent_size = Size2D(0, 0))
    {
        const Point2D relative = frame->get_origin();
        Size2D size = frame->get_size();

        /* Max size parent's size to avoid problems rendering */
        if(size.width >= parent_size.width)
            size.width = parent_size.width - 2;

        if(size.height >= parent_size.height)
            size.height = parent_size.height - 2;

        Point2D final_origin = relative + origin;
        frame->resize(size);
        frame->move(final_origin);
        _frames.push_back(frame);
    }

};

}   // namespace nci
#endif  /* __FRAMECONTAINER_HEADER_FILE_H */
