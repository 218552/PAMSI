#include "lista.hh"
#include "stoper.h"
#include "iostream"
using namespace std;
void lista::dodajelement(int elem, int pozycja){
wezel *temp = new wezel;
temp->element=elem;
if(pozycja==0){     /*dodawanie na tyl listy*/
if(rozmiar_listy==0){
temp->nastepny=przod;
przod=temp;
tyl=temp;
}
else{
tyl->nastepny=temp;
temp->nastepny=NULL;
tyl=temp;
}
}
else if(pozycja==rozmiar_listy && rozmiar_listy!=0){/*dodawanie na przod*/
temp->nastepny=przod;
przod=temp;
}
else if(pozycja<rozmiar_listy){
wezel *temp2=new wezel;
wezel *temp3=new wezel;
temp2=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+2));i++){ /*pozycja +2, bo szukamy wezla poprzedzajcego*/
cout << "3.1" << endl;
temp2=temp2->nastepny;
}
temp3=temp2->nastepny;
temp2->nastepny=temp;
temp->nastepny=temp3->nastepny;
}
else{
cout << "Poza zakresem" << endl;
rozmiar_listy--;
}
rozmiar_listy++;
}

int lista::usunelement(int pozycja){        /*usuwa element*/
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(1);
}
wezel *temp;
wezel *temp2;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+2)); i++){
temp=temp->nastepny;
}
if(pozycja==rozmiar_listy-1){
przod=temp->nastepny;
rozmiar_listy--;
return(temp->element);
}
temp2=temp->nastepny;
temp->nastepny=temp2->nastepny;
rozmiar_listy--;
delete temp2;
return(temp2->element);
}

lista::lista(){
przod=NULL;
tyl=NULL;
rozmiar_listy=0;
}

int lista::zwrocrozmiar(){
  return rozmiar_listy;
};

int lista::wyswietlelement(int pozycja){
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(1);
}
wezel *temp;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++){
temp=temp->nastepny;
}
cout << "Element na pozycji "<< pozycja << " ma wartosc " << temp->element << endl;
return(0);
}

void lista::wyswietl(){
for(int i=0; i<(rozmiar_listy); i++){
wyswietlelement(i);}
}

int lista::wyjmijelement(int pozycja){
if (wyswietlelement(pozycja)!=1){
return(usunelement(pozycja));}
return(0);
}

void lista::wypelnij(int ilosc){
for(int i=0; i<ilosc; i++){
dodajelement(0, 0);
}
}

void lista::przeszukajizmierz(int pozycja){
stoper s;
s.start();
wyswietlelement(pozycja);
s.stop();
}

int lista::get_data(int pozycja)
{
  wezel *tmp=przod;
  for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++)
    tmp=tmp->nastepny;
  return tmp->element;
}

void lista::change_data(int wartosc,int pozycja)
{
  wezel *tmp=przod;
  for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++)
    tmp=tmp->nastepny;
  tmp->element=wartosc;
}
