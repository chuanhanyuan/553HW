#include <iostream>
#include <string>

using namespace std;

class Person {
 private:
  // instance variables
  string first;
  string last;
  int age;

 public:
  // constructor
  Person(string first, string last, int age) {
    this->first = first;
    this->last = last;
    this->age = age;
  }

  // overloading '<<' operator
  friend ostream &operator<<(ostream &output, const Person &p) {
    output << "Firstname=" << p.first << endl;
    output << "Lastname=" << p.last << endl;
    output << "Age=" << p.age << endl;
    return output;
  }
};

// testing the class
int main() {
  Person p("a", "b", 25);
  cout << p;
}
