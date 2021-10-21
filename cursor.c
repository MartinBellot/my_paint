/*
** EPITECH PROJECT, 2021
** Cursor
** File description:
** Cursor for my paint project
*/

#include "include/mypaint.h"

sfCircleShape *get_cursor(sfRenderWindow *WINDOW, int brush_size, sfColor color)
{
    //CURSOR:
    sfVector2f cursor_pos = getMouseposf(WINDOW);
    cursor_pos.x -= brush_size;
    cursor_pos.y -= brush_size;
    sfCircleShape *cursor = generate_circleshape(brush_size, cursor_pos, color);
    sfCircleShape_setPosition(cursor, cursor_pos);
    sfCircleShape_setRadius(cursor, brush_size);
    
    return (cursor);
}