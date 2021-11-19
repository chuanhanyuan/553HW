
#include <iostream>
using namespace std;

int main() {
  int n = 0;
  cout << "Please enter a positive integer: ";
  cin >> n;
  while (n != 1) {
    if (n % 2 == 0)
      ;
    {cout << n / 2};
    else(n % 2 == 1);
    { cout << (n * 3) + 1; }
  }
  return 0;
}
