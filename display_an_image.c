/*
** EPITECH PROJECT, 2021
** display_an_image
** File description:
** display an image in a window
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "framebuffer.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My window",  sfClose, NULL);;
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("1543418740562.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    sfVector2f pos = {300, 200};

    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);

        }
    }
}
