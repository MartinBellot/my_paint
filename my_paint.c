/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** Open, display, and others...
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Text.h>
#include "include/framebuffer.h"
#include "include/my.h"
#include <stdio.h>
#include <string.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
int draw_circle(framebuffer_t *framebuffer, sfVector2i center, int rad, sfColor color);

void destroy_all(sfTexture *texture, sfSprite *sprite, framebuffer_t *framebuffer, sfRenderWindow *window)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    framebuffer_destroy(framebuffer);
    sfRenderWindow_destroy(window);
}

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

sfVector2i getPos(sfRenderWindow *WINDOW)
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
                sfVector2i posi = getPos(WINDOW);
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
        }
    }
}

int display(void)
{
    printf("Starting...\n");
    char *title = "My paint";
    sfVideoMode mode = {800, 600};
    sfRenderWindow *WINDOW = sfRenderWindow_create(mode, title, sfClose | sfResize, NULL);
    sfEvent event;
    framebuffer_t *framebuffer = framebuffer_create(mode.width, mode.height);
    sfTexture *texture = sfTexture_create(mode.width, mode.height);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfTexture_setSmooth(texture, sfTrue);
    sfColor color = sfWhite;
    int size = 4;

    while (sfRenderWindow_isOpen(WINDOW)) {
        check_event(WINDOW, event, framebuffer, &color, &size);
        
        sfRenderWindow_clear(WINDOW, sfBlack);    
        sfTexture_updateFromPixels(texture, framebuffer->pixels, mode.width, mode.height, 0, 0);
        sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
        sfRenderWindow_display(WINDOW);
    }
    sfImage *image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, "rendus/output.jpg");
    destroy_all(texture, sprite, framebuffer, WINDOW);
    printf("Bye :)\n");
}

int main(int ac, char **av)
{
    if (ac > 1) {
        if (av[1][0] == '-') {
            if (av[1][1] == 'h') {
                printf("{-- HELP MENU --}\n\n");
                printf("Shortcuts -> [g]Eraser    [r]Reset\n");
                printf("             [+]Increase  [-]Decrease\n\n");
                printf("mpaint -h: Menu help\n");
                printf("mpaint -o: Choose output file.\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
    display();
    return (EXIT_SUCCESS);
}