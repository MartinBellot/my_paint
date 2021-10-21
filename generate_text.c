/*
** EPITECH PROJECT, 2021
** GENERATE_TEXT.C
** File description:
** This function generate texte in CSFML
*/

#include "include/mypaint.h"

sfText *generate_text(char *str, sfVector2f position, int size_text, sfColor colors)
{
    sfFont *font = NULL;
    sfText *text = NULL;

    font = sfFont_createFromFile("polices/arial.ttf");
    if (!font)
        return NULL;
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, position);
    sfText_setCharacterSize(text, size_text);
    sfText_setColor(text, colors);
    return text;
}
