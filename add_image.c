/*
** EPITECH PROJECT, 2021
** display_an_image
** File description:
** display an image in a window
*/

#include "framebuffer.h"
#include "my.h"

sfSprite *add_an_image(sfVector2f position, char const *filename)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    texture = sfTexture_createFromFile(filename, NULL);
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}