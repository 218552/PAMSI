#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"
#include "/home/piotr/PAMSI/lab3/inc/queue.hpp"

using namespace std;

int Queue::push(int value)
{
  return List::add(value,1);
}

Node Queue::pop()
{
  return List::remove(List::size());
}

int Queue::size()
{
  return List::size();
}

void Queue::display()
{
  List::display();
}

int Queue::get_data()
{
  return List::get_data(List::size());
}
