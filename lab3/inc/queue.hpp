#ifndef QUEUE_HPP
#define QUEUE_HPP

class IQueue
{
public:
  virtual int push(int value)=0;
  virtual Node pop()=0;
  virtual int size()=0;
  virtual void display()=0;
};

class Queue:public List
{
public:
  int push(int value);
  Node pop();
  int size();
  void display();
  int get_data();
};

#endif
