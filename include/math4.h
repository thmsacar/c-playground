#ifndef MATH4_H
#define MATH4_H

#include "renderer.h" // point_3d tanımını kullanabilmek için

// 4x4 matris yapımız
typedef struct {
    double m[4][4];
} mat4;

// 1. Birim Matris (Identity Matrix) Üretir
// Köşegeni 1, diğer her yeri 0 olan, çarpmada etkisiz eleman olan matris.
mat4 mat4_identity(void);

// 2. İki Matrisi Birbiriyle Çarpar (Row x Column)
// Bu fonksiyon senin kutsal mekanın, transformasyonları üst üste bindirecek.
mat4 mat4_multiply(mat4 a, mat4 b);

// 3. Bir 3D Noktayı 4x4 Matris ile Çarpar ve Yeni Noktayı Döner
// Noktanın arkasına gizlice W=1 koyup çarpımı yapacak, sonra W'yu atıp point_3d dönecek.
point_3d mat4_multiply_point(mat4 m, point_3d p);

// 4. Öteleme (Translation) Matrisi Üretir
mat4 mat4_translate(double dx, double dy, double dz);

// 5. Y Ekseni Etrafında Dönme (Rotation Y - Senin eski rotate_xz) Matrisi Üretir
mat4 mat4_rotate_y(double angle);

#endif