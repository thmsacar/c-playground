#include "renderer.h"
#include "math4.h"


int main() {
    InitWindow(WIDTH, HEIGHT, "Cube");
    SetTargetFPS(FPS);

    double dz = 1;
    double angle = 0;

    point_3d* arr[] = {
        point(  0.25,  0.25,  0.25), point( -0.25,  0.25,  0.25),
        point(  0.25, -0.25,  0.25), point( -0.25, -0.25,  0.25),
        point(  0.25,  0.25, -0.25), point( -0.25,  0.25, -0.25),
        point(  0.25, -0.25, -0.25), point( -0.25, -0.25, -0.25)
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        clear();

        angle += 100.0 / FPS;

        mat4 rotY = mat4_rotate_y(angle);
        mat4 transZ = mat4_translate(0, 0, dz);

        mat4 transformation = mat4_multiply(transZ, rotY);

        point_3d scene[8];
        for(int i = 0; i < 8; i++) {
            scene[i] = mat4_multiply_point(transformation, *arr[i]);
            draw_3d_point(&scene[i], VERTEX_SIZE, RED);
        }

        draw_line_3d(&scene[0], &scene[1]); draw_line_3d(&scene[1], &scene[3]);
        draw_line_3d(&scene[3], &scene[2]); draw_line_3d(&scene[2], &scene[0]);
        draw_line_3d(&scene[4], &scene[5]); draw_line_3d(&scene[5], &scene[7]);
        draw_line_3d(&scene[7], &scene[6]); draw_line_3d(&scene[6], &scene[4]);
        draw_line_3d(&scene[0], &scene[4]); draw_line_3d(&scene[1], &scene[5]);
        draw_line_3d(&scene[2], &scene[6]); draw_line_3d(&scene[3], &scene[7]);
            
        EndDrawing();
    }

    freePoints(arr, 8);
    CloseWindow();
    return 0;
}