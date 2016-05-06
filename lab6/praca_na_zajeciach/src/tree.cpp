#include <iostream>

#include "tree_node.hpp"
#include "tree.hpp"

using namespace std;

void Tree::add(int value)
{
  if(first==NULL) //Jezeli drzewo jeszcze nie istnieje
    {
      first=new Tree_node;
      first->value=value;
      first->left=NULL;
      first->right=NULL;
      first->father=NULL;
      first->color=1; //1 - czarny, 0 - czerwony
      delete first;
    }
  else            //Dodanie nowego wezla
    {
      Tree_node *tmp=new Tree_node;
      tmp->color=0;
      tmp->value=value;
      delete tmp;
    }

}

int Tree::find()
{
  return 0;
}
