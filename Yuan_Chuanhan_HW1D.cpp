#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
float sum1f = 0.0;
float sum2f = 0.0;
double sum1d = 0.0;
double sum2d = 0.0;
float n = 0;
float a = 0.0;
double k = 0.0;
double b = 0.0;
int main() {
  for (n = 1; n < 101; n++) {
    a = 1 / n;
    sum1f = sum1f + a;
  }
  for (n = 100; n > 0; n--) {
    a = 1 / n;
    sum2f = sum2f + a;
  }
  for (k = 1; k < 101; k++) {
    b = 1 / k;
    sum1d = sum1d + b;
  }
  for (k = 100; k > 0; k--) {
    b = 1 / k;
    sum2d = sum2d + b;
  }
  cout << setprecision(4) << "sum1F = " << sum1f << ", "
       << "sum2F =" << sum2f << endl;
  cout << "sum1D = " << sum1d << ", "
       << "sum2D =" << sum2d << endl;
  cout << "sum1F - sum2F = " << sum1f - sum2f << endl;
  cout << "sum1D - sum2D = " << sum1d - sum2d << endl;
}