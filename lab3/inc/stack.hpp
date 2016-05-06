#ifndef STACK_HPP
#define STACK_HPP

class IStack
{
public:
  virtual int push(int value)=0;
  virtual Node pop()=0;
  virtual int size()=0;
  virtual void display()=0;
};

class Stack:public List
{
public:
  int push(int value);
  Node pop();
  int size();
  void display();
};


#endif
