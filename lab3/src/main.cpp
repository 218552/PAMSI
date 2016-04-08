#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"
#include "/home/piotr/PAMSI/lab3/inc/stack.hpp"

using namespace std;

int main()
{
  Stack stos;
  int wybor;
  int wartosc;
  while(1)
    {
      cout<<"1 - push"<<endl;
      cout<<"2 - pop"<<endl;
      cout<<"3 - size"<<endl;
      cout<<"4 - display"<<endl;
      cout<<"Wybierz opcje: ";
      cin>>wybor;
      cout<<endl;
    switch(wybor)
      {
      case 1:
	{
	  cout<<"Podaj wartosc: ";
	  cin>>wartosc;
	  stos.push(wartosc);
	}
	break;
      case 2:
      {
	cout<<"Zwrocono element stosu o wartosci: "<<stos.pop()<<endl;
      }
      break;
      case 3:
	{
	  cout<<"Rozmiar stosu: "<<stos.size()<<endl<<endl;
	}
	break;
      case 4:
	{
	  stos.display();
	}
	break;
      }
    }
}
