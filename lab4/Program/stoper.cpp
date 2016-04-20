#include "stoper.h"
#include <iostream>
#include <ctime>
using namespace std;

void stoper::start(){
    t=clock();
    }
void stoper::stop(){
    czas=(clock()-t )/(double) CLOCKS_PER_SEC;
    cout<<"Czas: "<< czas <<'\n';
    }
