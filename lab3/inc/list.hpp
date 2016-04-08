#ifndef LIST_HPP
#define LIST_HPP

class List
{
  int list_size;
public:
  List(){list_size=0;};
  void add(int value, int i);
  void remove(int i);
  int size();
  void display();
  ~List(){};
};

#endif
