#include <iostream>
#include <cstdlib>

#include "tree_node.hpp"
#include "tree.hpp"
#include "stoper.hpp"

using namespace std;

int main()
{
  srand (time(NULL));
  Stoper stoper;
  Tree tree[10];
  int size=10;


  for(int i=0;i<10;i++)
  {

    for(int j=0;j<size;j++)
      tree[i].add(rand()%size/4);
    stoper.measure_time(1);
    for(int k=0;k<10000;k++)
      tree[i].find(size);
    cout<<stoper.measure_time(0)<<endl;
  }
}
