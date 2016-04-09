#include "cell.h"

bool cell::is_alive()
{
    return state == alive;
}

void cell::flip_state()
{
    is_alive() ? this->state = dead : this->state = alive;
}

bool cell::operator==(const cell &c)
{
    return this->state == c.state && this->x == c.x && this->y == c.y;
}

bool cell::operator!=(const cell &c)
{
    return !(*this == c);
}
