/*
** EPITECH PROJECT, 2021
** Framebuffer
** File description:
** framebuffer for graphical project.
*/

#include "include/framebuffer.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *element = malloc(sizeof(framebuffer_t));
    element->pixels = malloc(width * height * 4);
    element->width = width;
    element->height = height;  
    return (element);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}