#include <iostream>
#include <cstring>

#include "node.hpp"
#include "list.hpp"
#include "hash_table.hpp"
#include "assoc_table.hpp"

using namespace std;

void Assoc_table::operator()(string key, int value)
{
  table[hash(key)].insert(value);
}

void Assoc_table::operator[](string key)
{
  if(table[hash(key)].get_size()==0)
    cout<<"Brak elementow przypisanych do danego klucza";
  else
    {
      int *tmp=new int[table[hash(key)].get_size()];
      tmp=table[hash(key)].get_data();
      for(int i=0;i<table[hash(key)].get_size();i++)
	cout<<tmp[i]<<" ";
      delete [] tmp;
    }

}

int Assoc_table::hash(string key)
{
  return key[0]%buckets_amount;
}
