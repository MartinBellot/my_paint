/*
** EPITECH PROJECT, 2021
** Events for My paint project
** File description:
** All events gestion of my paint project
*/

#include "include/mypaint.h"

void check_event(sfRenderWindow *WINDOW, sfEvent event, framebuffer_t *framebuffer, sfColor *color, int *size)
{
    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(WINDOW);
        }
        if (event.type == sfEvtMouseMoved) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfVector2i posi = getMousePosi(WINDOW);
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
            if (sfKeyboard_isKeyPressed(sfKeyR)) {
                for (int x=0; x<framebuffer->width; x++) {
                    for (int y=0; y<framebuffer->height; y++) {
                        put_pixel(framebuffer, x, y, sfBlack);
                    }
                }
            }
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