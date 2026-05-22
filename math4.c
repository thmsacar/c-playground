#include "renderer.h" 
#include <math.h>

typedef struct {
    double m[4][4];
} mat4;

mat4 mat4_identity(){
    mat4 res;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                res.m[i][j] = 1.0;
            } else {
                res.m[i][j] = 0.0;
            }
        }
    }
    return res;
}

mat4 mat4_multiply(mat4 a, mat4 b){
    mat4 res;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                res.m[i][j] = 0.0;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++){
                res.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }

    return res;
}

point_3d mat4_multiply_point(mat4 m, point_3d p) {
    
    point_3d res;

    res.x = m.m[0][0]*p.x + m.m[0][1]*p.y + m.m[0][2]*p.z + m.m[0][3]*1.0;
    res.y = m.m[1][0]*p.x + m.m[1][1]*p.y + m.m[1][2]*p.z + m.m[1][3]*1.0;
    res.z = m.m[2][0]*p.x + m.m[2][1]*p.y + m.m[2][2]*p.z + m.m[2][3]*1.0;

    return res;
}

mat4 mat4_translate(double dx, double dy, double dz){
    mat4 res = mat4_identity();
    res.m[0][3] = dx;
    res.m[1][3] = dy;
    res.m[2][3] = dz;
    return res;
}


mat4 mat4_rotate_x(double angle){
    mat4 res = mat4_identity();
    double rad = angle * (PI / 180.0);
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    res.m[1][1] = cos_a;
    res.m[1][2] = -sin_a;
    res.m[2][1] = sin_a;
    res.m[2][2] = cos_a;
    return res;
}

mat4 mat4_rotate_y(double angle){
    mat4 res = mat4_identity();
    double rad = angle * (PI / 180.0);
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    res.m[0][0] = cos_a;
    res.m[0][2] = -sin_a;
    res.m[2][0] = sin_a;
    res.m[2][2] = cos_a;
    return res;
}

mat4 mat4_rotate_z(double angle){
    mat4 res = mat4_identity();
    double rad = angle * (PI / 180.0);
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    res.m[0][0] = cos_a;
    res.m[0][1] = -sin_a;
    res.m[1][0] = sin_a;
    res.m[1][1] = cos_a;
    return res;
}


