/*
** EPITECH PROJECT, 2021
** Events for My paint project
** File description:
** All events gestion of my paint project
*/

#include "include/mypaint.h"

sfVector2i getMousePos(sfRenderWindow *WINDOW)
{
    sfVector2i pos;
    pos.x = sfMouse_getPositionRenderWindow(WINDOW).x;
    pos.y = sfMouse_getPositionRenderWindow(WINDOW).y;
    return (pos);
}

void check_event(sfRenderWindow *WINDOW, sfEvent event, framebuffer_t *framebuffer, sfColor *color, int *size)
{
    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(WINDOW);
        }
        if (event.type == sfEvtMouseMoved) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfVector2i posi = getMousePos(WINDOW);
                draw_circle(framebuffer, posi, *size, *color);
            }
        }
        if (event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyNum1))
                *color = sfRed;
            if (sfKeyboard_isKeyPressed(sfKeyNum2))
                *color = sfGreen;
            if (sfKeyboard_isKeyPressed(sfKeyNum3))
                *color = sfBlue;
            if (sfKeyboard_isKeyPressed(sfKeyNum4))
                *color = sfWhite;
            if (sfKeyboard_isKeyPressed(sfKeyG))
                *color = sfBlack;
            if (sfKeyboard_isKeyPressed(sfKeyAdd))
                *size += 1;
            if (sfKeyboard_isKeyPressed(sfKeySubtract))
                if (*size >= 1)
                    *size -= 1;
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(WINDOW);
        }
    }
}