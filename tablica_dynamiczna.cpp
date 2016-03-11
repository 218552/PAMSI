#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Funkcja zwieksza rozmiar tablicy o zadana wartosc           */
/* Parametry                                                   */
/* tab - tablica                                               */
/* n - rozmiar tablicy przed powiekszeniem                     */
/* zwieksz - ilosc elementow o jaka tablica zostanie zwiekszona*/
bool *zmien_rozmiar(bool *tab,int n,int zwieksz)
{
  bool *tmp=new bool[n];
  
  for(int i=0;i<n;i++)
    tmp[i]=tab[i];
  
  delete[] tab;
  tab=new bool[n+zwieksz];

  for(int i=0;i<n;i++)
    tab[i]=tmp[i];

  delete[] tmp;
  return tab; 
}


void wyswietl(bool *tab,int n)
{
  for(int i=0;i<n;i++)
    cout<<tab[i]<<endl;
}

int main()
{
  int n=10;              //poczatkowa ilosc elementow tablicy
  int liczba=1;          //liczba do przypisania wartosci elementom tablicy
  int zwieksz=1000000000; //ilosc elementow o jaka zwiekszana bedzie tablica
  clock_t start=clock(); //zmierzenie aktualnego czasu
  bool *tab=new bool[n];
  
  for(int i=0;i<1000000000;i++)
    {
      if(i<n)
	{
	  tab[i]=liczba;
	}
      else
	{
	  tab=zmien_rozmiar(tab,n,zwieksz);
	  tab[i]=liczba;
	  n=n+zwieksz;
	}
    }
  delete[] tab;
  //Wyswietlenie czasu trwania algorytmu
  cout<<"Czas wykonania algorytmu: "<<double(clock()-start)/(double)CLOCKS_PER_SEC<<"s"<<endl;

}
