/**
 * @file            utils.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main drawing utils for nci.
 * @author          vgonisanz
 *
 * Draw helpers around windows for nci library
 *
 * @license LGPL v3.0
 */
#ifndef __NCI_UTILS_HEADER_FILE_H
#define __NCI_UTILS_HEADER_FILE_H

#include "types.h"

#include <ncurses.h>
#include <iostream>

namespace nci
{

/**
 * \brief Draw a box around a window
 */
void box(WINDOW* win, std::string id = "Unknown");
/**
 * \brief Draw a box that fit with a bot box at the bottom of this one 
 */
void top_box(WINDOW* win, std::string id = "Unknown");
/**
 * \brief Draw a box that fit with a tot box at the top of this one
 */
void bot_box(WINDOW* win, std::string id = "Unknown");


}   // namespace nci
#endif  /* __NCI_UTILS_HEADER_FILE_H */
