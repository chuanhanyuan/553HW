#include <cmath>
#include <iostream>
using namespace std;

class vec_3d {
 private:
  double vec1, vec2, vec3;

 public:
  vec_3d(double x = 0.0, double y = 0.0, double z = 0.0)
      : vec1(x), vec2(y), vec3(z) {}
  friend vec_3d operator+(vec_3d a, vec_3d b) {
    return vec_3d(a.vec1 + b.vec1, a.vec2 + b.vec2, a.vec3 + b.vec3);
  }
  friend vec_3d operator-(vec_3d a, vec_3d b) {
    return vec_3d(a.vec1 - b.vec1, a.vec2 - b.vec2, a.vec3 - b.vec3);
  }
  friend vec_3d operator-(vec_3d a) {
    return vec_3d(-a.vec1, -a.vec2, -a.vec3);
  }
  friend ostream& operator<<(ostream& s, vec_3d c) {
    return s << "(" << c.vec1 << ',' << c.vec2 << ',' << c.vec3 << ")";
  }
  friend vec_3d dot(vec_3d a, vec_3d b) {
    return d = (a.vec1 * b.vec1) + (a.vec2 * b.vec2) + (a.vec3 * b.vec3);
  }
  friend istream& operator>>(istream& s, vec_3d c) {
    return s >> c.vec1 >> c.vec2 >> c.vec3;
  }
  friend vec_3d mag(vec_3d a) {
    double ans = (a.vec1 * a.vec1) + (a.vec2 * a.vec2) + (a.vec3 * a.vec3);
    return sqrt(ans);
  }
  friend vec_3d magsq(vec_3d a) {
    return (a.vec1 * a.vec1) + (a.vec2 * a.vec2) + (a.vec3 * a.vec3);
  }
};
int main() {
  vec_3d v1(1.5, 2.2, -3.1);  // x=1.5 y=2.2 z-3.1
  vec_3d v2(-2.2, 1.2);       // z = 0
  vec_3d v3(5.6);             // y = z = 0
  vec_3d v4;                  // x = y = z = 0

  vec_3d v5 = v1 + v2;
  vec_3d v6 = v1 - v3;
  vec_3d v7 = -v2;         // negation
  double d = dot(v1, v5);  // dot product
  cout << v1 << '\n';
  cout << v2 << '\n';
  cout << v3 << '\n';
  cout << v4 << '\n';
  cout << v5 << '\n';
  cout << v6 << '\n';
  cout << v7 << '\n';
  // cin >> v1;                   // read in x, y, z from keyboard
  // cout << v1.mag() << '\n';    // magnitude (abs)
  // cout << v1.magsq() << '\n';  // magnitude squared  x*x+y*y+z*z
}