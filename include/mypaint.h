/*
** EPITECH PROJECT, 2021
** My paint h
** File description:
** All includes for My paint project.
*/
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Text.h>
#include "framebuffer.h"
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
int draw_circle(framebuffer_t *framebuffer, sfVector2i center, int rad, sfColor color);
sfText *generate_text(char *str, sfVector2f position, int size_text, sfColor colors);
void check_event(sfRenderWindow *WINDOW, sfEvent event, framebuffer_t *framebuffer, sfColor *color, int *size);
