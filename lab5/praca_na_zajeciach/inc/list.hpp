#ifndef LIST_HPP
#define LIST_HPP

// Interfejs Listy
class IList
{
public:
  virtual int add(int value, int position)=0;
  virtual Node remove(int position)=0;
  virtual int size()=0; 
  virtual void display()=0;
};

class List : public IList
{
  int list_size;
  Node *head;				      
  Node *tail;
public:
  List();
  int add(int value, int position);
  Node remove(int position);
  int size();
  void display();
  int search(int number);
  int get_data(int position);
};

#endif
