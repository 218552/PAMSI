#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"
#include "/home/piotr/PAMSI/lab3/inc/stack.hpp"

using namespace std;

int Stack::push(int value)
{
  return List::add(value,List::size()+1);
}

Node Stack::pop()
{
  return List::remove(List::size());
}

int Stack::size()
{
  return List::size();
}

void Stack::display()
{
  List::display();
}

/*
Stack::~Stack()
{
  while(top!=NULL)
    {
      Node *tmp=top;
      top=top->next;
      delete tmp;
    }
}
*/
