/*
** EPITECH PROJECT, 2021
** Framebuffer structure
** File description:
** Framebuffer's structure
*/

#include <SFML/Graphics.h>

typedef struct framebuffer 
{
    sfUint8 *pixels;
    int width;
    int height;
} framebuffer_t;