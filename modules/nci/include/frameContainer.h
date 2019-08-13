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

    uint32_t size() { return _frames.size(); }
    bool empty() { return _frames.empty(); }
    void clear() { _frames.clear(); }
    std::shared_ptr<VirtualFrame> at(uint32_t index) { return _frames.at(index); }

    void draw();
    // run_once
    // run

    template <typename F>
    void add(F frame, Point2D origin = Point2D(0, 0))
    {
        const Point2D relative = frame->get_origin();
        frame->move(relative + origin);
        _frames.push_back(frame);
    }

};

}   // namespace nci
#endif  /* __FRAMECONTAINER_HEADER_FILE_H */