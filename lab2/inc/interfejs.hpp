#ifndef INTERFEJS_HPP
#define INTERFEJS_HPP

class Interfejs
{
public:
  virtual double stoper(bool flag)=0;
};

class Interfejs2
  :public Interfejs
{
  clock_t start;
public:
  double stoper(bool flag);
  bool *zmien_rozmiar(bool *tab,int n,int zwieksz);
};

#endif
