#ifndef interfejs_hh
#define interfejs_hh
class interfejs {
public:
virtual void dodajelement(int, int)=0;
virtual int usunelement(int)=0;
virtual int wyjmijelement(int)=0;
virtual int zwrocrozmiar()=0;
virtual int wyswietlelement(int)=0;
virtual void wyswietl()=0;
virtual void wypelnij(int)=0;
virtual void przeszukajizmierz(int)=0;
virtual int get_data(int)=0;
virtual void change_data(int, int)=0;
};
#endif
