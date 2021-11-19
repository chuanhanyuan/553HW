#include <iostream>

using namespace std;

int main() {
  while (1) {
    double a = -1.0;
    cout << "Please enter a positive number:";
    cin >> a;
    cout << "User enters in " << a << endl;
    if (a < 0) {
      cout << "No! Enter a POSITIVE number" << endl;
    } else if (a - (int)a != 0) {
      cout << "No! Enter a whole number" << endl;
    } else {
      long long ans = 1;
      int i = 1;
      for (; i <= a; i++) {
        ans *= i;
      }
      cout << (int)a << "! = " << ans << endl;
      break;
    }
  }
  return 0;
}