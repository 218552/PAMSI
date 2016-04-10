#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"
#include "/home/piotr/PAMSI/lab3/inc/stack.hpp"
#include "/home/piotr/PAMSI/lab3/inc/queue.hpp"

using namespace std;

int main()
{
  Queue list;
  
  char choose;
  int value;

  do
  {
    cout<<"1 - add"<<endl;
    cout<<"2 - remove"<<endl;
    cout<<"3 - size"<<endl;
    cout<<"4 - display"<<endl;
    cout<<"q - quit"<<endl<<endl;
    cin>>choose;
    switch(choose)
      {
      case '1':
	{
	  cout<<"Podaj wartosc: ";
	  cin>>value;
	  list.push(value);
	}
	break;
      case '2': 
	{
	  list.pop();
	}
	break;
      case '3':
	{
	  cout<<endl<<"Rozmiar kolejki: "<<list.size()<<endl<<endl;
	}
	break;
      case '4':
	{
	  list.display();
	}
	break;
      }
  } while(choose!='q');
}
