#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
  Node *top;
  int stack_size;
public:
  Stack(){top=NULL;stack_size=0;}
  void push(int value);
  int pop();
  int size();
  void display();
  ~Stack();
};


#endif
