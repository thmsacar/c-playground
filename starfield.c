#include "renderer.h"
#include <time.h>
#include <stdlib.h>

#define STAR_COUNT 500


int main(){

    InitWindow(WIDTH, HEIGHT, "Starfield");
    SetTargetFPS(FPS);

    point_3d* stars[STAR_COUNT];

    for (int i = 0; i < STAR_COUNT; i++) {
        double rx = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        double ry = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        double rz = 0.1 + ((double)rand() / RAND_MAX) * 4.9; 

        stars[i] = point(rx, ry, rz);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        clear();

        for (int i = 0; i < STAR_COUNT; i++) {
            stars[i]->z -= 0.004; 

            if (stars[i]->z <= 0.0) {
                stars[i]->z = 5.0;
                
                stars[i]->x = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
                stars[i]->y = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            }

            double star_size = 1.2 / stars[i]->z;
            draw_3d_point(stars[i], star_size, WHITE); 
        }
            
        EndDrawing();
    }

    freePoints(stars, STAR_COUNT);

    return 0;
}