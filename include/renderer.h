#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"

#define WIDTH 800
#define HEIGHT 800
#define FPS 120
#define VERTEX_SIZE 10

#define BG_COLOR BLACK
#define FG_COLOR RED

typedef struct {
    double x;
    double y;
} point_2d;

typedef struct {
    double x;
    double y;
    double z;
} point_3d;

void clear(void);
void draw_point(point_2d *p, double size, Color color);
void draw_line(point_2d* p1, point_2d* p2);
point_2d* new_2d_point(double x, double y);
point_3d* point(double x, double y, double z);
point_2d* project(point_3d *p);
void draw_3d_point(point_3d* p, double size, Color color);
void draw_line_3d(point_3d* p1, point_3d* p2);
void freePoints(point_3d** arr, int n);
void translate_z(point_3d* p, double dz);
void rotate_xz(point_3d* p, double angle);

#endif