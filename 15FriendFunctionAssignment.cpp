#include <iostream>
using namespace std;

class Rectangle {
  private:
    double length;
    double width;
    double height;
  public:
    Rectangle(double len, double wid, double hei) {
      length = len;
      width = wid;
      height = hei;
    }
    double getArea() {
      return length * width;
    }
    double getPerimeter() {
      return (length*2) + (width*2);
    }
    friend bool isEqual(Rectangle r1, Rectangle r2) {
      return r1.getArea() == r2.getArea();  
    }
    double getVolume() {
      return length * width * height;
    }
    friend bool isEqualVol(Rectangle r1, Rectangle r2) {
      return r1.getVolume() == r2.getVolume();
    }
};

int main(){
  Rectangle r1(3, 11, 46);
  Rectangle r2(56, 9, 12);

  cout << "Area of Rectangle 1 is: " << r1.getArea() << endl;
  cout << "Area of Rectangle 2 is: " << r2.getArea() << endl;

  cout << endl;

  cout << "Perimeter of Rectangle 1 is: " << r1.getPerimeter() << endl;
  cout << "Perimeter of Rectangle 2 is: " << r2.getPerimeter() << endl;

  cout << endl;

  if (isEqual(r1, r2)) {
    cout << "The Rectangles have an equal area" << endl;
  } else {
    cout << "The Rectangles do not have an equal area" << endl;
  }

  cout << endl;

  cout << "The Volume of Rectangle 1 is: " << r1.getVolume() << endl;
  cout << "The Volume of Rectangle 2 is: " << r2.getVolume() << endl;

  cout << endl;

  if (isEqualVol(r1, r2)) {
    cout << "The Rectangles have an equal area" << endl;
  } else {
    cout << "The Rectangles do not have an equal area" << endl;
  }
  
  return 0;
}
