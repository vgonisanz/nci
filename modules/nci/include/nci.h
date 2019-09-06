/**
 * @file            nci.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main nci workspace.
 * @author          vgonisanz
 *
 * Namespace to include all required elemens in nci library
 *
 * @license LGPL v3.0
 */
#ifndef __NCI_HEADER_FILE_H
#define __NCI_HEADER_FILE_H

#include <ncurses.h>
#include "types.h"
#include "imanager.h"

namespace nci
{

WINDOW* initialize_ncurses();
void tear_down_ncurses();
void feedback_ncurses(bool print);

}   // namespace nci
#endif  /* __NCI_HEADER_FILE_H */
