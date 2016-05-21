#include <iostream>
#include <cstdlib>
#include <ctime>

#include "funkcje.hpp"

using namespace std;

int main()
{
  int n=10;              //poczatkowa ilosc elementow tablicy
  int liczba=1;          //liczba do przypisania wartosci elementom tablicy
  int zwieksz=2;         //ilosc elementow o jaka zwiekszana bedzie tablica
  clock_t start=clock(); //zmierzenie aktualnego czasu
  bool *tab=new bool[n];

  for(int i=0;i<100000000;i++)
    {
      if(i<n)
	{
	  tab[i]=liczba;
	}
      else
	{
	  tab=zmien_rozmiar(tab,n,zwieksz);
	  tab[i]=liczba;
	  n=n*zwieksz;
	}
    }

  delete[] tab;
  //Wyswietlenie czasu trwania algorytmu
  cout<<"Czas wykonania algorytmu: "<<double(clock()-start)/(double)CLOCKS_PER_SEC<<"s"<<endl;
}
