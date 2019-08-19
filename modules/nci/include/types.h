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
#include <iostream>

namespace nci
{

enum CURSOR : uint8_t {
    INVISIBLE = 0,
    VISIBLE = 1,
    VERY_VISIBLE = 2,
};

typedef struct Point2D
{
    uint32_t x;
    uint32_t y;

    Point2D(uint32_t x = 0, uint32_t y = 0):
    x(x),
    y(y) {}

    inline Point2D operator+(const Point2D& other) const
    {
        Point2D res {x + other.x, y + other.y};
        return res;
    }
/*    inline Point2D &operator+=(const uint32_t &other)
    {
        x += other;
        y += other;
        return *this;
    }*/
    inline Point2D operator-(const Point2D& other) const
    {
        Point2D res {x - other.x, y - other.y};
        return res;
    }
/*    inline Point2D &operator-=(const uint32_t &other)
    {
        x -= other;
        y -= other;
        return *this;
    }
    */
} Point2D;

typedef struct Size2D
{
    uint32_t width;
    uint32_t height;

    Size2D(uint32_t width = 2, uint32_t height = 2):
    width(width),
    height(height) {}

    inline Size2D operator+(const Size2D& other) const
    {
        Size2D res {width + other.width, height + other.height};
        return res;
    }
/*    inline Size2D &operator+=(const Size2D &lhs, const uint32_t &other) const
    {
        lhs.x += other.x;
        lhs.y += other.y;
        return lhs;
    }*/
    inline Size2D operator-(const Size2D& other) const
    {
        Size2D res {width - other.width, height - other.height};
        return res;
    }
/*    inline Size2D &operator-=(const Size2D &lhs, const uint32_t &other) const
    {
        lhs.x -= other.x;
        lhs.y -= other.y;
        return lhs;

    }
    */
} Size2D;

}   // namespace nci

#endif  /* __NCI_TYPES_HEADER_FILE_H */
