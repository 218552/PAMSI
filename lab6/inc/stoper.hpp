#ifndef STOPER_HPP
#define STOPER_HPP

#include <ctime>

class Stoper
{
  clock_t start;
public:
  double measure_time(bool on_off)
  {
    if(on_off==1)
      {
	start=clock();
	return 0;
      }
    else return double(clock()-start)/(double)CLOCKS_PER_SEC;
  }
};

#endif
