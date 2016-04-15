#include <iostream>
#include <cstring>

#include "node.hpp"
#include "list.hpp"

using namespace std;

int hash(string str)
{
  int index=0;

  return index;
}

List *zmien_rozmiar(List *tab,int n,int zwieksz)
{
  List *tmp=new List[n];
  
  for(int i=0;i<n;i++)
    tmp[i]=tab[i];
  
  delete[] tab;
  tab=new List[n+zwieksz];

  for(int i=0;i<n;i++)
    tab[i]=tmp[i];

  delete[] tmp;
  return tab; 
}

int main()
{
  List *tab=new List[1]; 
  char chose;
  int value;
  int n=0;
  do
    {
      cout<<"a - dodaj element listy"<<endl;
      cout<<"d - wyswietl element tablicy"<<endl;
      cout<<"Twoj wybor: ";
      cin>>chose;
      switch(chose)
	{
	case 'a':
	  {
	    cout<<"Podaj wartosc elementu: ";
	    cin>>value;
	    tab[n].add(value,1);
	    n++;
	    tab=zmien_rozmiar(tab,n,1);
	  }
	  break;
	case 'd':
	  {
	    cout<<"Ktory element tablicy chcesz wyswietlic: ";
	    cin>>value;
	    tab[value].display();
	  }
	  break;
	}
    }
  while(chose!='q');
  delete [] tab;
  return 0;
}
