/*
** EPITECH PROJECT, 2020
** DRAW_CIRCLE.C
** File description:
** SCREEN_SAVER/
*/

#include "include/framebuffer.h"
#include "include/my.h"
#include <math.h>

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);

int draw_circle(framebuffer_t *framebuffer, sfVector2i center, int rad, sfColor color)
{
    int i;
    int j;
    for (i = center.y-rad; i <= center.y+rad; i++) {
        for (j = center.x-rad; j <= center.x+rad; j++) {
            if (pow(j - center.x, 2) + pow(i - center.y, 2) <= pow(rad, 2))
                put_pixel(framebuffer, j, i, color);
        }
    }
    return (0);
}