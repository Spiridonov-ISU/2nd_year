#include "Point.h"

Point::Point(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}
int Point::GetX() { return x; }
int Point::GetY() { return y; }