#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"

using namespace std;

void List::add(int value,int i)
{
   list_size++;
}

void List::remove(int i)
{
  list_size--;
}

int List::size()
{
  return list_size;
}

void List::display()
{

}
