#ifndef interfejsk_hh
#define interfejsk_hh
class interfejsk {
public:
virtual void dodajelement(int)=0;
virtual int usunelement()=0;
virtual int wyjmijelement()=0;
virtual int zwrocrozmiar()=0;
virtual int wyswietlelement(int)=0;
virtual void wyswietl()=0;
virtual void wypelnij(int)=0;
virtual int get_data(int)=0;
};
#endif
