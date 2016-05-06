#include <iostream>
#include <iomanip>

#include "tree_node.hpp"
#include "tree.hpp"


using namespace std;

void Tree::add(int value)
{
  Tree_node *node=new Tree_node;
  Tree_node *b=sentinel;
  Tree_node *a=root;
  node->value=value;
  while(a!=sentinel)
  {
    b=a;
    if(node->value < a->value)
      a=a->left;
    else
      a=a->right;
  }
  node->father=b;
  if(b==sentinel)
    root=node;
  else
  {
    if(node->value < b->value)
      b->left=node;
    else
      b->right=node;
  }
  node->left=sentinel;
  node->right=sentinel;
  node->color='R';
  fixup(node);
}

int Tree::find(int value)
{
  Tree_node *node=root;
  while(node!=sentinel)
  {
    if(node->value==value)
      return 0;
    else
    {
      if(value < node->value)
        node=node->left;
      else
        node=node->right;
    }
  }
  return 1;
}

void Tree::display(Tree_node* node,int indent)
{
  if(node != sentinel)
  {
      if(node->right)
        display(node->right, indent+4);
      if (indent)
        cout<<setw(indent)<<' ';
      if (node->right)
        cout<<"  /\n"<<setw(indent)<<' ';
      cout<<node->value<<"\n ";
      if(node->left) {
          cout<<setw(indent)<<' '<<" \\\n";
        display(node->left, indent+4);
      }
  }
}

void Tree::rotate_left(Tree_node *x)
{
  Tree_node *y=x->right;
  x->right=y->left;
  if(y->left!=sentinel)
    y->left->father=x;
  y->father=x->father;
  if(x->father==sentinel)
    root=y;
  else
  {
    if(x==x->father->left)
      x->father->left=y;
    else
      x->father->right=y;
  }
  y->left=x;
  x->father=y;
}

void Tree::rotate_right(Tree_node *x)
{
  Tree_node *y=x->left;
  x->left=y->right;
  if(y->right!=sentinel)
    y->right->father=x;
  y->father=x->father;
  if(x->father==sentinel)
    root=y;
  else
  {
    if(x==x->father->right)
      x->father->right=y;
    else
      x->father->left=y;
  }
  y->right=x;
  x->father=y;
}

void Tree::fixup(Tree_node *node)
{
  Tree_node *tmp;
  while(node->father->color=='R')
  {
    if(node->father==node->father->father->left)
    {
      tmp=node->father->father->right;
      if(tmp->color=='R')
      {
        node->father->color='B';
        tmp->color='B';
        node->father->father->color='R';
        node=node->father->father;
      }
      else
      {
        if(node==node->father->right)
        {
          node=node->father;
          rotate_left(node);
        }
        node->father->color='B';
        node->father->father->color='R';
        rotate_right(node->father->father);
      }
    }
    else
    {
      tmp=node->father->father->left;
      if(tmp->color=='R')
      {
        node->father->color='B';
        tmp->color='B';
        node->father->father->color='R';
        node=node->father->father;
      }
      else
      {
        if(node==node->father->left)
        {
          node=node->father;
          rotate_right(node);
        }
        node->father->color='B';
        node->father->father->color='R';
        rotate_left(node->father->father);
      }
    }
  }
  root->color='B';
}
