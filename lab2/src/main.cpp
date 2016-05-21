#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "interfejs.hpp"

using namespace std;

int main()
{
  Interfejs2 inter;
  fstream dane;
  dane.open("dane.txt",ios::app|ios::out);
  int n=10;              //poczatkowa ilosc elementow tablicy
  int liczba=1;          //liczba do przypisania wartosci elementom tablicy
  int zwieksz=100;         //ilosc elementow o jaka zwiekszana bedzie tablica
  bool *tab=new bool[n];
  inter.stoper(1);
  for(int i=0;i<100000;i++)
    {
      if(i<n)
	{
	  tab[i]=liczba;
	}
      else
	{
	  tab=inter.zmien_rozmiar(tab,n,zwieksz);
	  tab[i]=liczba;
	  n=n+zwieksz;
	}
    }
  dane<<inter.stoper(0);
  dane<<"\n";
  delete[] tab;
}
