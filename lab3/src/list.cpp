#include <iostream>

#include "/home/piotr/PAMSI/lab3/inc/node.hpp"
#include "/home/piotr/PAMSI/lab3/inc/list.hpp"

using namespace std;
/* Konstruktor */
List::List()
{
  head=NULL;
  tail=NULL;
  list_size=0;
}

/* Metoda tworzy nowy element listy na okreslonej pozycji */
int List::add(int value,int position)
{
  Node *tmp=new Node;
  
  if(position==1) //Jesli dodawany element jest na pierwszej pozycji
    {
      if(list_size==0)    //do pustej listy
	{
	  tmp->next=head;
	  tmp->data=value;
	  head=tmp;
	  tail=tmp;
	  list_size++;
	  return 0;
	}
      else                //do wypelnionej listy
	{
	  tail->next=tmp;
	  tmp->next=NULL;
	  tmp->data=value;
	  tail=tmp;
	  list_size++;
	  return 0;
	}
    }
  else
    {
      if(position==(list_size+1)) //Dodawanie elementu na koniec listy
	{
	  tmp->next=head;
	  tmp->data=value;
	  head=tmp;
	  list_size++;
	  return 0;
	}
      else
	{
	  if(position<=list_size) //Dodawanie elementu w srodek listy
	    {
	      Node *save=new Node;
	      save=head;
	      for(int i=0;i<(list_size-position);i++)
		save=save->next;
	      tmp->data=value;
	      tmp->next=save->next;
	      save->next=tmp;
	      list_size++;
	      delete save;
	      return 0;
	    }
	  else                     //Blad, pozycja poza zakresem
	    {
	      cout<<"Pozycja poza zakresem"<<endl<<endl;
	      return 1;
	    }
	}
    }
  delete tmp;
}

/* Metoda usuwa dany element listy */
Node List::remove(int position)
{
  if(position>list_size)
    {
      Node *nul=new Node;
      nul->next=NULL;
      cout<<"Pozycja poza zakresem"<<endl<<endl;
      return *nul;
    }
  else
    {
      Node *tmp=new Node;
      Node *save=new Node;
      tmp=head;
      save=tmp;
      if(position==list_size)
	{
	  head=tmp->next;
	}
      else
	{
	  for(int i=0;i<(list_size-position);i++)
	    {
	      save=tmp;
	      tmp=tmp->next;
	    }
	  save->next=tmp->next;
	}
      list_size--;
      return *tmp;
      delete tmp;
    }
}

/* Metoda wzraca liczbe elementow listy */
int List::size()
{
  return list_size;
}

/* Metoda wyswietla zawartosc listy */
void List::display()
{
  Node *tmp=head;
  cout<<endl<<"Elementy listy: "<<endl;
  for(int i=0;i<list_size;i++)
    {
     cout<<tmp->data<<endl;
     tmp=tmp->next;
    }
  cout<<endl;
}

/* Metoda wyszukuje z listy dana liczbe i zwraca ilosc znalezionych liczb */
int List::search(int number)
{
  Node *tmp=head;
  int counter=0;
  for(int i=0;i<list_size;i++)
    {
      if(tmp->data==number)
	counter++;
      tmp=tmp->next;
    }
  return counter;
}
