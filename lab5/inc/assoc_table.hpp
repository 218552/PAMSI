#ifndef ASSOC_TABLE_HPP
#define ASSOC_TABLE_HPP

class IAssoc_table
{
public:
  virtual void operator()(string key, int value)=0;
  virtual void operator[](string key)=0;
  virtual int hash(string key)=0;
};

class Assoc_table:public IAssoc_table
{
  int buckets_amount;
  Hash_table* table;
public:
  Assoc_table(int amount){buckets_amount=amount;table=new Hash_table[buckets_amount];};
  void operator()(string key, int value);
  void operator[](string key);
  int hash(string key);
};

#endif
