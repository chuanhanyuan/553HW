#include <iostream>

using namespace std;

int main() {
  int a = -1;
  cout << "Please enter a positive number:";
  cin >> a;
  while (a != 1) {
    if (a % 2 == 1) {
      a *= 3;
      a++;
    } else {
      a /= 2;
    }
    cout << a << ' ';
  }
  return 0;
}