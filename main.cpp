#include <iostream>
#include <cstdlib>

using namespace std;

class Element
{
public:
  Element *wskaznik_na_element;
  int dana;
};

class Lista
{
public:
  virtual int add(Element element,int pozycja)=0;
  virtual Element remove(int pozycja)=0;
  virtual int size()=0;
};

class Stos :public Lista
{
  Element wezel;
  int i;
public:
  
};

class Kolejka :public Lista
{
  Element wezel;
  int i;
public:
  
};

class Stos_bez_interfejsu
{
public:
  Element *wezel,*tmp;
  int i;
  Stos_bez_interfejsu(){i=0;};
  int push(int wartosc);
  Element *pop();
  int size(){return i;};
};

int Stos_bez_interfejsu::push(int wartosc)
{
  tmp=new Element;
  tmp->dana=wartosc;
  tmp->wskaznik_na_element=wezel;
  wezel=tmp;
  ++i;
  return 0;
}

Element *Stos_bez_interfejsu::pop()
{
  wezel=tmp->wskaznik_na_element;
  --i;
  return wezel;
}

int main()
{
  Stos_bez_interfejsu stos;
  stos.push(5);
  stos.push(10);
  stos.push(15);
  stos.pop();
  cout<<stos.wezel->dana<<endl;
}
