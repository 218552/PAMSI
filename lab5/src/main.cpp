#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "node.hpp"
#include "list.hpp"
#include "hash_table.hpp"
#include "assoc_table.hpp"
#include "stoper.hpp"

using namespace std;

int main()
{
  srand (time(NULL));
  fstream plik;
  Stoper stoper;
  int buckets_amount=50;
 
  Assoc_table tab(buckets_amount);
  string str;
  int size=100000;

  plik.open("dane",ios::app|ios::out);

  stoper.measure_time(1);
  for(int i=0;i<size;i++)
    {
      str=rand()%26+97;
      tab(str,rand()%11);
    }
  for(int i=0;i<buckets_amount;i++)
    {
      str=i;
      tab[str];
      cout<<endl;
    }
  plik<<stoper.measure_time(0);
  plik<<"\n";
  
  return 0;
}
