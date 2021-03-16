#include "keybindingContainer.h"

#include "virtualFrame.h"
#include "imanager.h"

namespace nci
{

KeybindingContainer::KeybindingContainer(std::string id):
_id(id)
{
}

KeybindingContainer::~KeybindingContainer()
{
}

void KeybindingContainer::add(int character, std::function<void()> function)
{
    _keybinding[character] = function;
}

void KeybindingContainer::run()
{
    uint16_t character;

    while((character = getch()) != 'n')
    {
        std::cout << "User action in " << _id << " key: " << character << std::endl;
        IManager::execute_key_if_exist(character);
        auto key = _keybinding.find(character);
        if (key == _keybinding.end())
            continue;

        key->second();
    }
}

} /* namespace nci */
