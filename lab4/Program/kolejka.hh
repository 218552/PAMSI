#ifndef kolejka_hh
#define kolejka_hh
#include "interfejsk.h"
#include "lista.hh"
class kolejka: public interfejsk{
lista l;
public:
virtual void dodajelement(int element);
virtual int usunelement();
virtual int wyswietlelement(int pozycja);
virtual int zwrocrozmiar();
virtual int wyjmijelement();
virtual void wyswietl();
virtual void wypelnij(int ilosc);
virtual int get_data(int pozycja);
virtual void change_data(int wartosc, int pozycja);
};
#endif
