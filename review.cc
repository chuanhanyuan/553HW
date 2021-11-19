#include <iostream>
using namespace std;

void stats(double x[], int size, double min, double max, double mean) {
  max = 0;
  min = 0;
  mean = 0;
  double sum = 0;
  for (i = 0; i < x.size(); i++) {
    if (x[i] >= max) {
      x[i] = max;
    }
    if (x[i] <= min) {
      x[i] = min;
    }
  }
  sum += x[i];
};

int main() {
  double x[] = {1, 2, 3, 5.5, -1.2345, 99.28, 1.2345e3};
  double min, max, mean;
  stats(x, sizeof(x) / sizeof(double), min, max, mean);

  // stats(x, sizeof(x) / sizeof(double), &min, &max, &mean);
}

class shape {
 public:
  virtual double area() const = 0;

} class circle : public shape {
 private:
  double radius;

 public:
  circle(double radius) : radius(radius) {}
  double area() const override { return 3.14 * radius; }
}

class something {
 private:
  int n;
  int* p;

 public:
   something(int n): p(new int[n]),n(n)){
     for (i = 0; i <= n; i++) {
       p[i] = n;
     }
   }
   ~something() { delete[] p; }

   something(const something& orig) : p(new int[orig.n]), n(orig.n) {
     for (i = 0; i <= n; i++) {
       p[i] = orig.p[i];
     }
   }
   something& operator=(const something& orig) {
     n = orig.n;
     p = new int[n];
     for (int i = 0; i <= n; i++) {
       p[i] = orig.p[i];
     }
     return *this;
   }
   something& operator=(something copy) {
     n = copy.n;
     swap(p, copy.p);
     return *this;
   }
};
