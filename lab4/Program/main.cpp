#include <iostream>
#include <cstdlib>
#include <ctime>

#include "lista.hh"
#include "kolejka.hh"
#include "stoper.h"
#include "sort.hpp"

using namespace std;

int main()
{
  srand(time(NULL));
  kolejka k;
  stoper s;
  int zachowaj;
  k.dodajelement(10);
  k.dodajelement(100);
  k.dodajelement(1000);
  k.dodajelement(1000000);
  k.dodajelement(100000000);
  cout<<endl<<k.zwrocrozmiar()<<endl<<endl;

  for(int i=0;i<k.zwrocrozmiar()+4;i++)
    {
      zachowaj=k.usunelement();
      int *tab=new int[zachowaj];
      for(int i=0;i<zachowaj;i++)
	{
	  tab[i]=rand()%1001;
	}
      s.start();
      quicksort(tab,0,zachowaj);
      s.stop();
      delete [] tab;
    }
 
  return 0;
}

