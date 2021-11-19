#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <iostream>
using namespace std;
#include "stb_image_write.h"
/*
Dynamic memory bitmap homework
hex: base 16
0   0000
1   0001
2   0010
3   0011
4   0100
5   0101
6   0110
7   0111
8   1000
9   1001
A   1010
B   1011
C   1100
D   1101
E   1110
F   1111
row-major order
    0  1  2  3
    4  5  6  7
    8  9  10 11


    our color format is RRGGBBAA  (red, green, blue, alpha = transparency)
*/

class Bitmap {
 private:
  uint32_t w, h;
  uint32_t* pixel;  // allocate an array of w*h elements
 public:
     Bitmap(uint32_t a, uint32_t b, uint32_t x) {
         w = a;
         h = b;
         pixel = new uint32_t[w * h];
         for (uint32_t i = 0; i < w * h; i++) {
             pixel[i] = x;
         }
     }
     Bitmap(const Bitmap &bitmap) {
         this->w = bitmap.w;
         this->h = bitmap.h;
         this->pixel = new uint32_t[w * h];
         for (uint32_t i = 0; i < w * h; i++) {
             pixel[i] = bitmap.pixel[i];
         }
     }
     Bitmap& operator=(const Bitmap& bitmap) {
         if (this == &bitmap) {
             return *this;
         }
         this->w = bitmap.w;
         this->h = bitmap.h;
         this->pixel = new uint32_t[w * h];
         for (uint32_t i = 0; i < w * h; i++) {
             pixel[i] = bitmap.pixel[i];
         }
         return *this;
     }
     ~Bitmap() {
         delete[]pixel;
     }
  void set(uint32_t x, uint32_t y, uint32_t color) { 
      pixel[y * w + x] = color; 
  }
  uint32_t& operator()(uint32_t x, uint32_t y) { 
      return pixel[y * w + x]; 
  }
  uint32_t operator()(uint32_t x, uint32_t y) const { 
      return pixel[y * w + x]; 
  }
  void horizLine(....) {
    set(x, y, color);
    (*this)(x, y) = color;
  }
  void write(const char filename[]) {
    stbi_write_png(filename, w, h, 4, pixel, 4 * w);
  }
};

int main() {
  Bitmap bm(640, 480, 0xFFFFFF00);  // set every pixel to be color FFFFFF
  bm.set(0, 0, 0x80808000);
  bm(3, 4) = 0x80808000;
  bm.horizLine(0, 500, 0, 0x0000FF00);  // x1= 0 x2= 500, y = 0 BLUE
  bm.vertLine(0, 100, 10, 0xFF000000);  // y1 = 0 y2 = 100, x = 10 RED
  bm.rect(300, 100, 50, 50, 0x00FF0000);
  ;  // x=300,y=100, w=50,h=50 GREEN
  bm.write("small.png");

  Bitmap bm2(1024, 1024, 0xFFFFFF00);    // set every pixel to be color 0
  bm2.horizLine(0, 500, 0, 0x0000FF00);  // x1= 0 x2= 500, y = 0 BLUE
  bm2.vertLine(0, 100, 10, 0xFF000000);  // y1 = 0 y2 = 100, x = 10 RED
  bm2.rect(300, 100, 50, 50, 0x00FF0000);
  ;  // left=300,top=100, w=50,h=50 GREEN
  bm2.write("big.png");

  Bitmap bm3 = bm2;  // copy constructor

  bm3 = bm3;  // operator =
}