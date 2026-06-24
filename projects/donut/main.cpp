#include <cmath>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <iostream>

int main() {
  float A=0, B=0;
  const float thetaSpacing = 0.07;
  const float phiSpacing = 0.02;
  
// Radius 
  const float R1 = 1; // inner
  const float R2 = 2; // outer
  const float k = 5; // distance from the eye [camera]
  
 // Screen width & height
  const int width = 80;
  const int height = 24;

const float k2 = width * k * 3 / (8 * (R1 + R2)) * 0.6;


  char output[width * height]; // output gird
  float zbuffer[width * height]; // stores 1/z
// for (;;) => runs idefinitely
  for (;;) {
    memset(output, ' ', width * height);  // reset cells 
   memset(zbuffer, 0, width * height * sizeof(float));  // reset depth to 0

    float cosA = cos(A), sinA = sin(A);
    float cosB = cos(B), sinB = sin(B);

    for (float theta  = 0; theta < 2 * M_PI; theta += thetaSpacing){
      float costheta = cos(theta), sintheta = sin(theta);

      for (float phi = 0; phi < 2 * M_PI; phi += phiSpacing){
        float cosphi = cos(phi), sinphi = sin(phi);
   
        float CX = R2 + R1 * costheta; // circleX
        float CY = R1 * sintheta;  //circleY

   float x = CX * (cosB * cosphi + sinA * sinB * sinphi) - CY * cosA * sinB;
float y = CX * (sinB * cosphi - sinA * cosB * sinphi) + CY * cosA * cosB;
float z = k + cosA * CX * sinphi + CY * sinA;
float ooz = 1 / z;
int xp = (int)(width / 2 + k2 * ooz * x);
int yp = (int)(height / 2 - k2 * ooz * y * 0.5);

        if ( xp < 0 || xp >= width || yp < 0 || yp >= height) 
          continue;

                 float L = cosphi * costheta * sinB - cosA * costheta * sinphi -
                           sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);
         if (L > 0) {
           int idx = xp + width * yp;
           if ( ooz > zbuffer[idx]) {
             zbuffer[idx] = ooz;
                        int luminance_index = L * 8;
                        output[idx] = ".,-~:;=!*#$@"[luminance_index];
           }
         }
      }
    }
            printf("\x1b[2J\x1b[H");
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                putchar(output[j * width + i]);
            }
            putchar('\n');
        }

        A += 0.07;
        B += 0.03;
        usleep(30000);
    
  }
return 0;
}