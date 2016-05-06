#include "kolejka.hh"
#include "lista.hh"
void kolejka::dodajelement(int element){
l.dodajelement(element, 0);
}
int kolejka::usunelement(){
return(l.usunelement(l.rozmiar_listy-1));
}

int kolejka::wyswietlelement(int pozycja){
l.wyswietlelement(pozycja);
return(0);
}
int kolejka::zwrocrozmiar(){
  return l.zwrocrozmiar();
}
int kolejka::wyjmijelement(){
return(l.wyjmijelement(l.rozmiar_listy-1));
}
void kolejka::wyswietl(){
l.wyswietl();
}
void kolejka::wypelnij(int ilosc){
l.wypelnij(ilosc);
}

int kolejka::get_data(int pozycja)
{
  return l.get_data(pozycja);
}

void kolejka::change_data(int wartosc,int pozycja)
{
  l.change_data(wartosc,pozycja);
}
