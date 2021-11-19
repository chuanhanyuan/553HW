#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  const int n = 60;
  const int m = -45;
  for (int16_t i = 5; i <= n; i += 5) {
    for (int16_t j = 40; j >= m; j -= 5)
      cout << setprecision(2) << setw(6)
           << ceil(35.74 + (j * 0.6215) - (35.75 * pow(i, 0.16)) +
                   0.4275 * j * pow(i, 0.16));
    cout << "\n";
  }
}