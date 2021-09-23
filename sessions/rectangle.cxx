#include <iostream>
using std::cout;
using std::endl;

class Point {
private:
  float x,y;
public:
  Point(float xx,float yy) 
    : x(xx),y(yy) {};
  float xcoord() { return x; };
  float ycoord() { return y; };
};

class Rectangle {
private:
  Point bottomleft; float width,height;
public:
  Rectangle( Point bbl,float ww,float hh ) 
    : bottomleft(bbl),width(ww),height(hh) {};
  // Syntax for member initializer list:
  // colon member-name ( init-data )
  // optionally: comma and more of those

  Rectangle( Point bbl,Point ttr )
    : bottomleft(bbl),width(?????), {};
  float area() { return width*height; };
  float right_edge_x() { return bottomleft.xcoord() + width; }; // not correct yet!
};

int main() {

  Point oneone(1,1),twothree(2,3);
  Rectangle portrait(oneone,2.5,4.);
  cout << "portrait has area " << portrait.area() << endl;

}

// emacs has `point' and `mark'. point = where you are (left side of the cursor)
// mark is something you can set: Ctrl-<space>
// Ctrl-w : scoop up everything between point and mark: the `region'
// Ctrl-y : insert
// C-c C-c : comment region
// ESC < : beginning of file
// ESC > : end of file

// ESC f : word forward
// C-u 6 ESC f : 6 words forward
