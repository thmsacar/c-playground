#include "raylib.h"
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * System constants
 */
const int FPS = 120;
const int WIDTH = 800;
const int HEIGHT = 800;
const Color BG_COLOR = BLACK;
const Color FG_COLOR = RED;
const double s = 10; //Size of vertexes 

typedef struct {
    double x;
    double y;
} point_2d;


typedef struct {
    double x;
    double y;
    double z;
} point_3d;


/**
 * Clears the screen
 */
void clear(){
    ClearBackground(BG_COLOR);

}

/**
 * Draws a point_2d on screen
 */
void draw_point(point_2d *p){
    DrawRectangle(p->x - s/2, p->y - s/2, s, s, FG_COLOR);
}

/**
 * Draws a line between two point_2d
 */
void draw_line(point_2d* p1, point_2d* p2){
    DrawLine(p1->x, p1->y, p2->x, p2->y, FG_COLOR);
}

/**
 * Create a new 2D point 
 * @param x X coordinate between [-1,1]
 * @param y Y coordinate between [-1,1]
 * @return A new point on cartesian plain
 */
point_2d* new_2d_point(double x, double y){
    point_2d* p = malloc(sizeof(point_2d));
    p->x = (x+1)/2*WIDTH;
    p->y = (1-(y+1)/2)*HEIGHT; //Reverse the Y coord
    return p;
}

/**
 * Create a new 3D point 
 * @param x X coordinate between [-1,1]
 * @param y Y coordinate between [-1,1]
 * @param z Z coordinate 
 * @return A new point on cartesian plain
 */
point_3d* point(double x, double y, double z){
    point_3d* p = malloc(sizeof(point_3d));
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

/**
 * Projects a 3D point to 2D point
 * @param p 3D point to project
 * @return 2D projection
 */
point_2d* project(point_3d *p){
    return new_2d_point(p->x/p->z, p->y/p->z);
}

/**
 * Draws a point_3d on screen
 */
void draw_3d_point(point_3d* p){
    point_2d* p2 = project(p);
    draw_point(p2);
    free(p2);
}

/**
 * Draws a line between two point_3d
 */
void draw_line_3d(point_3d* p1, point_3d* p2) {
    point_2d* proj1 = project(p1);
    point_2d* proj2 = project(p2);

    draw_line(proj1, proj2);
    
    free(proj1); 
    free(proj2);
}

/**
 * Free an array of point_3d 
 */
void freePoints(point_3d** arr, int n){
    for(int i=0; i<n; i++){
        free(arr[i]);
    }

}

/**
 * Translates a 3D point on Z axis
 * @param p
 * @param dz translation on z axis
 */
void translate_z(point_3d* p, double dz){
    p->z += dz;
}

/**
 * Rotates a 3D on XZ plain (Rotation around Y axis)
 * @param p 
 * @param angle angle to rotate [0, 360)
 */

void rotate_xz(point_3d* p, double angle){
    double rad = angle * (PI / 180.0);
    double cos_a = cos(rad);
    double sin_a = sin(rad);

    double old_x = p->x;
    double old_z = p->z;

    p->x = old_x * cos_a - old_z * sin_a;
    p->z = old_x * sin_a + old_z * cos_a;
}


int main(){

    InitWindow(WIDTH, HEIGHT, "Line");
    SetTargetFPS(FPS);

    double lastTime = GetTime();
    double dz = 1;
    double dt = 1.0/FPS;
    double angle = 0;

    //Creating an array with our vertexes
    point_3d* arr[] = {
        point(  0.25,  0.25,  0.25),
        point( -0.25,  0.25,  0.25),
        point(  0.25, -0.25,  0.25),
        point( -0.25, -0.25,  0.25),

        point(  0.25,  0.25, -0.25),
        point( -0.25,  0.25, -0.25),
        point(  0.25, -0.25, -0.25),
        point( -0.25, -0.25, -0.25)
    };

    while (!WindowShouldClose()) {
        //Check if enough time passed before redrawing the frame
        double currentTime = GetTime();
        if (currentTime - lastTime >= 1.0/FPS) { 
            lastTime = currentTime; 
        }

        BeginDrawing();
        clear();

        // dz += dt;
        angle += 100.0/FPS;

        //New array
        point_3d scene[8];
        for(int i=0; i<8; i++){
            //Copying the original array
            scene[i] = *arr[i];

            //Transform the points and draw
            rotate_xz(&scene[i], angle);
            translate_z(&scene[i], dz);
            draw_3d_point(&scene[i]);
        }

        //We are now adding lines between the points
        //Front face
        draw_line_3d(&scene[0], &scene[1]);
        draw_line_3d(&scene[1], &scene[3]);
        draw_line_3d(&scene[3], &scene[2]);
        draw_line_3d(&scene[2], &scene[0]);

        //Rear face
        draw_line_3d(&scene[4], &scene[5]);
        draw_line_3d(&scene[5], &scene[7]);
        draw_line_3d(&scene[7], &scene[6]);
        draw_line_3d(&scene[6], &scene[4]);

        //Side connection
        draw_line_3d(&scene[0], &scene[4]);
        draw_line_3d(&scene[1], &scene[5]);
        draw_line_3d(&scene[2], &scene[6]);
        draw_line_3d(&scene[3], &scene[7]);

    
        EndDrawing();
    }

    //Free the points in original array just in case.
    freePoints(arr, 8);

    CloseWindow();
    return 0;
}

