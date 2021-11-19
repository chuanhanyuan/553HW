#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class robot {
 private:
  string name, name2;
  double x, y;

 public:
  robot(string name, string name2, double x = 0, double y = 0)
      : name(name), name2(name2), x(x), y(y) {}
};

class beacon {
 private:
  string name, name2;
  double x, y;

 public:
  beacon(string name, string name2, double x = 0, double y = 0)
      : name(name), name2(name2), x(x), y(y) {}
};
int main() {
  ifstream f("rsim.conf");
  char buffer[4096];
  char name[20];
  char name2[20];
  double x;
  double y;
  while (f.getline(buffer, sizeof(buffer))) {
    istringstream line(buffer);
    line >> name >> name2 >> x >> y;
    cout << name << name2 << x << y << '\n';
  }
  vector<robot> robots;
  vector<beacon> beacon;
  string robotname = "robot";
  string beaconname = "beacon";
  if (name == robotname) {
    robots.emplace_back(name, name2, x, y);
  } else if (name == beaconname) {
    beacon.emplace_back(name, name2, x, y);
  }
  for (int i = 0; i < 100; i++) robots.push_back(i);
}
