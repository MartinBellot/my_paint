/*
** EPITECH PROJECT, 2021
** Get mouse pos !
** File description:
** have the position of mouse
*/

#include "include/mypaint.h"

sfVector2i getMousePosi(sfRenderWindow *WINDOW)
{
    sfVector2i pos;
    pos.x = sfMouse_getPositionRenderWindow(WINDOW).x;
    pos.y = sfMouse_getPositionRenderWindow(WINDOW).y;
    return (pos);
}

sfVector2f getMouseposf(sfRenderWindow *WINDOW)
{
    sfVector2f pos;
    pos.x = sfMouse_getPositionRenderWindow(WINDOW).x;
    pos.y = sfMouse_getPositionRenderWindow(WINDOW).y;
    return (pos);
}