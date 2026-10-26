#include <iostream>

using namespace std;
//i am just playing around with classes
class Area {
public:
  double sideLength;

  double computeArea() {
    double area = sideLength * sideLength;
    return area;
  }
};


int main() {

  Area object;

  object.sideLength = 10.4;

  cout << "Side Length is: " << object.sideLength << "\n";
  cout << "Area is: " << object.computeArea();
  

  return 0;
}
