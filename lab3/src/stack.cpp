#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"
#include "/home/piotr/PAMSI/lab3/inc/stack.hpp"

using namespace std;

void Stack::push(int value)
{
  Node *tmp;
  tmp=new Node;
  tmp->data=value;
  tmp->next=top;
  top=tmp;
  stack_size++;
}

int Stack::pop()
{
  if(top!=NULL)
    {
      Node *tmp=top;
      top=top->next;
      stack_size--;
      cout<<"Zdjeto element"<<endl;
      return tmp->data;
      delete tmp;  
    }
  else 
    {
      string exception="Pusty stos";
      throw exception;
    }
}
int Stack::size()
{
  return stack_size;
}

void Stack::display()
{
  Node *tmp=top;
  while(tmp!=NULL)
    {
      cout<<tmp->data<<endl;
      tmp=tmp->next; 
    }
}

Stack::~Stack()
{
  while(top!=NULL)
    {
      Node *tmp=top;
      top=top->next;
      delete tmp;
    }
}
