/**
 * @file            keybindingContainer.h
 * @version         1.0
 * @date            August 2019
 * @brief           Frame container to manage children elements.
 * @author          vgonisanz
 *
 * @license LGPL v3.0
 */
#ifndef __KEYBINDINGCONTAINER_HEADER_FILE_H
#define __KEYBINDINGCONTAINER_HEADER_FILE_H

#include <memory>
#include <map>
#include <functional>
#include <vector>

#include "types.h"

namespace nci
{

class KeybindingContainer
{
private:
    std::string _id;
    std::map<int, std::function<void()> > _keybinding;

public:
    KeybindingContainer(std::string id = "Unknown");
    ~KeybindingContainer();

    void run();
};

}   // namespace nci
#endif  /* __KEYBINDINGCONTAINER_HEADER_FILE_H */
