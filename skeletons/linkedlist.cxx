#include <iostream>
#include <memory>
using namespace std;

class Node {
 private:
  int datavalue{0};
  shared_ptr<Node> tail_ptr{nullptr}; 
public:
  Node() {};
  Node(int value)
    : datavalue(value) {};
  void set_tail( shared_ptr<Node> tailvalue ) {
    tail_ptr = tailvalue;
  };
  int list_length() {
    if (tail_ptr==nullptr)
      return 1;
    else 
      return 1 + tail_ptr->list_length();
  };
  int append( shared_ptr<Node> newtail ) {
    if (tail_ptr==nullptr)
      set_tail(newtail);
    else 
      tail_ptr->append(newtail);
  };
  int value() { return datavalue; };
  bool has_next() {
    return tail_ptr!=nullptr; };
};

int main() {
  auto
    first = make_shared<Node>(23),
    second = make_shared<Node>(45),
    third = make_shared<Node(67);
  first->append(second);
  first->append(third);
  cout << "List length: "
       << first->list_length() << endl; 
  // first->print();

  return 0;
}
