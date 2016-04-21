#include <iostream>
#include <cstring>

#include "node.hpp"
#include "list.hpp"
#include "hash_table.hpp"


using namespace std;

void Hash_table::insert(int value)
{
  list.add(value,1);
}

int* Hash_table::get_data()
{
  int* tab=new int[list.size()];
  for(int i=0;i<list.size();i++)
    tab[i]=list.get_data(i+1);
  return tab;
  delete [] tab;
}

