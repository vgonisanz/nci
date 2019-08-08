/**
 * @file            types.h
 * @version         1.0
 * @date            May 2019
 * @brief           General Types for nci library.
 * @author          vgonisanz
 *
 */
#ifndef __NCI_TYPES_HEADER_FILE_H
#define __NCI_TYPES_HEADER_FILE_H

#include <stdint.h>

namespace nci
{

enum CURSOR : uint8_t {
    INVISIBLE = 0,
    VISIBLE = 1,
    VERY_VISIBLE = 2,
};

typedef struct Point2D
{
    int x;
    int y;
} Point2D;

typedef struct Size2D
{
    int width;
    int height;
} Size2D;

}   // namespace nci

#endif  /* __NCI_TYPES_HEADER_FILE_H */
