#include "renderer.h"
#include <stdlib.h>
#include <math.h>

void clear() {
    ClearBackground(BG_COLOR);
}

void draw_point(point_2d *p, double size, Color color) {
    DrawRectangle(p->x - size/2, p->y - size/2, size, size, color);
}

void draw_line(point_2d* p1, point_2d* p2) {
    DrawLine(p1->x, p1->y, p2->x, p2->y, FG_COLOR);
}

point_2d* new_2d_point(double x, double y) {
    point_2d* p = malloc(sizeof(point_2d));
    p->x = (x + 1) / 2 * WIDTH;
    p->y = (1 - (y + 1) / 2) * HEIGHT;
    return p;
}

point_3d* point(double x, double y, double z) {
    point_3d* p = malloc(sizeof(point_3d));
    p->x = x; p->y = y; p->z = z;
    return p;
}

point_2d* project(point_3d *p) {
    return new_2d_point(p->x / p->z, p->y / p->z);
}

void draw_3d_point(point_3d* p, double size, Color color) {
    point_2d* p2 = project(p);
    draw_point(p2, size, color);
    free(p2);
}

void draw_line_3d(point_3d* p1, point_3d* p2) {
    point_2d* proj1 = project(p1);
    point_2d* proj2 = project(p2);
    draw_line(proj1, proj2);
    free(proj1); 
    free(proj2);
}

void freePoints(point_3d** arr, int n) {
    for(int i = 0; i < n; i++) {
        free(arr[i]);
    }
}

void translate_z(point_3d* p, double dz) {
    p->z += dz;
}

void rotate_xz(point_3d* p, double angle) {
    double rad = angle * (PI / 180.0);
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    double old_x = p->x;
    double old_z = p->z;

    p->x = old_x * cos_a - old_z * sin_a;
    p->z = old_x * sin_a + old_z * cos_a;
}