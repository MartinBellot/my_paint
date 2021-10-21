/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** Open, display, and others...
*/

#include "include/mypaint.h"

void destroy_all(sfTexture *texture, sfSprite *sprite, framebuffer_t *framebuffer, sfRenderWindow *window)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    framebuffer_destroy(framebuffer);
    sfRenderWindow_destroy(window);
}

int display(int ac, char **av)
{
    printf("Starting...\n");
    char *title = "My paint";
    sfVideoMode mode;
    sfRenderWindow *WINDOW;
    if (ac > 1) {
        if (av[1][0] == '-' && av[1][1] == 'f') {
            mode.width = 1920;
            mode.height = 1080;
            WINDOW = sfRenderWindow_create(mode, title, sfClose | sfFullscreen, NULL);
        }
    }
    else {
        mode.width = 800;
        mode.height = 600;
        WINDOW = sfRenderWindow_create(mode, title, sfClose, NULL);
    }
    sfEvent event;
    framebuffer_t *framebuffer = framebuffer_create(mode.width, mode.height);
    sfTexture *texture = sfTexture_create(mode.width, mode.height);
    sfSprite *screen = sfSprite_create();
    sfSprite_setTexture(screen, texture, sfTrue);
    sfTexture_setSmooth(texture, sfTrue);
    sfColor color = sfWhite;
    int brush_size = 4;

    
    sfText *text = generate_text("MPaint (v0.1)", (sfVector2f){0,0}, 20, sfWhite);

    while (sfRenderWindow_isOpen(WINDOW)) {
        check_event(WINDOW, event, framebuffer, &color, &brush_size);
    
        sfRenderWindow_clear(WINDOW, sfBlack);    
        sfTexture_updateFromPixels(texture, framebuffer->pixels, mode.width, mode.height, 0, 0);
        sfRenderWindow_drawSprite(WINDOW, screen, NULL);
        sfRenderWindow_drawText(WINDOW, text, NULL);

        sfCircleShape *cursor = get_cursor(WINDOW, brush_size, color);

        sfRenderWindow_drawCircleShape(WINDOW, cursor, NULL);
        sfRenderWindow_display(WINDOW);
    }
    sfImage *image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, "rendus/output.jpg");
    sfImage_copy(image);
    destroy_all(texture, screen, framebuffer, WINDOW);
    printf("Bye :)\n");
    exit(EXIT_SUCCESS);
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
    display(ac, av);
    return (EXIT_SUCCESS);
}