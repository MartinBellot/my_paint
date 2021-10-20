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

sfVector2u getPos(sfRenderWindow *WINDOW)
{
    sfVector2u pos;
    pos.x = sfMouse_getPositionRenderWindow(WINDOW).x;
    pos.y = sfMouse_getPositionRenderWindow(WINDOW).y;
    return (pos);
}

sfText *generate_text(char *text, float x, float y, int size)
{
    sfVector2f pos;
    pos.x = x;
    pos.y = y;
    sfText *data = sfText_create();
    sfText_setString(data, text);
    sfText_setCharacterSize(data, size);
    sfText_setColor(data, sfWhite);
    sfText_setPosition(data, pos);
    return (data);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

sfColor choose_color(void) 
{
    char  *r, *g, *b = 0;
    sfColor color;
    int i = 0;
    FILE *zenity;
    char *justnumber;
    char answer[20];
    if ((zenity = popen("zenity --color-selection --show-palette","r")) != NULL)
        fgets(answer,sizeof(answer),zenity);
    printf("%s\n",answer);
    while (answer[i] != '\0') {
        if (answer[i] == 'r' || answer[i] == 'g' || answer[i] == 'b' || answer[i] == '(' || answer[i] == ')' || answer[i] == ',');
        else {
            char merge[2];
            merge[0] = answer[i];
            merge[1] = '\0';
            strncat(justnumber, merge, 1);
        }
    }
    printf("%s", justnumber);
    return (color);
}

void check_event(sfRenderWindow *WINDOW, sfEvent event, framebuffer_t *framebuffer, sfColor *color)
{
    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(WINDOW);
        }
        if (event.type == sfEvtMouseMoved) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfVector2u posi = getPos(WINDOW);
                draw_square(framebuffer, posi, 4, *color);
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
        }
    }
}

int display(void)
{
    //choose_color();
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

    sfText *text_title = generate_text(title, 300.0, 300.0, 500);

    while (sfRenderWindow_isOpen(WINDOW)) {
        check_event(WINDOW, event, framebuffer, &color);
        
        sfRenderWindow_clear(WINDOW, sfBlack);    
        sfTexture_updateFromPixels(texture, framebuffer->pixels, mode.width, mode.height, 0, 0);
        sfRenderWindow_drawSprite(WINDOW, sprite, NULL);
        sfRenderWindow_drawText(WINDOW, text_title, NULL);
        sfRenderWindow_display(WINDOW);
    }
    sfImage *image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, "rendus/output.jpg");
    destroy_all(texture, sprite, framebuffer, WINDOW);
}

int main(void)
{
    display();
    return (EXIT_SUCCESS);
}