/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** include for my_radar
*/

#ifndef MY_RADAR
    #define MY_RADAR

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Mouse.h>
    #include <time.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include "my.h"
    #include "math.h"

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f ori;
} sprite_t;

typedef struct val_s {
    char *path;
    int size;
    int posx;
    int posy;
    int rtop;
    int rleft;
    int rwidth;
    int rheight;
    int orix;
    int oriy;
} val_t;

typedef struct plane_s {
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    sfVector2f dir;
    float abscisse;
    float ordonnee;
    int destroy;
    int dx;
    int dy;
    int ax;
    int ay;
    int s;
    int d;
} plane_t;

typedef struct tower_s {
    sfSprite *sprite;
    sfCircleShape *area;
    int x;
    int y;
    int r;
} tower_t;

typedef struct game_timer_s {
    sfClock *clock;
    sfTime time;
    int second;
    char *str;
} gt_t;

typedef struct tick_s {
    sfClock *clock;
    sfTime time;
    float second;
} tick_t;

typedef struct all_s {
    sprite_t *sprite;
    int screen;
    int switch_e;
    int switch_h;
    sfEvent event;
    sfVector2i mouse;
    sfRenderWindow *window;
    sfText **txt;
    char *str;
    char **tab;
    int nbr_planes;
    int nbr_towers;
    int landed;
    int crashed;
    char *str_landed;
    char *str_crashed;
    plane_t *pl;
    tower_t *to;
    gt_t *timer;
    tick_t *tick;
} all_t;

void init(all_t *all);
void setwindow(all_t *all);
void recup(all_t *all, char **argv);
void movement(all_t *all);
void destroy(all_t *all);
void check_collide(all_t *all);
void memory_allocation(all_t *all);
void create_text(all_t *all);
void create_text(all_t *all);
char *write_nbr(int nbr, char *count);
void update_txt(all_t *all);
void destroy_all(all_t *all);
void free_all(all_t *all);

    #define SDRS sfRenderWindow_drawRectangleShape
    #define SDCS sfRenderWindow_drawCircleShape
    #define SFST sfSprite_setTexture
    #define SFCR sfSprite_create()
    #define SRWC sfRenderWindow_create
    #define SFCF sfTexture_createFromFile
    #define SFWC sfRenderWindow_create
    #define SFDS sfRenderWindow_drawSprite
    #define TO_DEG(x) ((x) * 180 / 3.14)
    #define SPRITE_NBR 3

#endif
