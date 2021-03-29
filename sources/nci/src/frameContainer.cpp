#include "frameContainer.h"

#include "virtualFrame.h"

namespace nci
{

FrameContainer::FrameContainer()
{
}

FrameContainer::~FrameContainer()
{
}

void FrameContainer::draw()
{
    for(auto frame: _frames)
        frame->draw();
}

} /* namespace nci */
