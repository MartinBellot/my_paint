/*
** EPITECH PROJECT, 2021
** All my draw tools
** File description:
** Draw tools for My paint project.
*/

#include "include/mypaint.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    if (x < framebuffer->width && y < framebuffer->height) {
        framebuffer->pixels[(y*framebuffer->width+x)*4] = color.r;
        framebuffer->pixels[(y*framebuffer->width+x)*4 +1] = color.g;
        framebuffer->pixels[(y*framebuffer->width+x)*4 +2] = color.b;
        framebuffer->pixels[(y*framebuffer->width+x)*4 +3] = color.a;
    }
}

void draw_square(framebuffer_t *framebuffer, sfVector2u position, unsigned int size, sfColor color)
{
    int x = position.x-(size/2);
    int y = position.y-(size/2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size; j++) {
            put_pixel(framebuffer, x, y, color);
            x++;
        }
        x = position.x-(size/2);
        y = position.y+(size/2);
    }
    x = position.x-(size/2);
    y = position.y-(size/2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size; j++) {
            put_pixel(framebuffer, x, y, color);
            y++;
        }
        x = position.x+(size/2);
        y = position.y-(size/2);
    }
}

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