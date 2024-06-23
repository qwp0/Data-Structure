#ifndef STOCK_H
#define STOCK_H

#include <queue>
#include "transaction.h"

class StockTrade{
private:  
  std::queue<Transaction> transaction; 
  int totalQuantity;
  int totalCapitalGain;
public:
   StockTrade():totalCapitalGain(0),totalQuantity(0){}
   int getTotalGain();
   void buy(const Transaction& t);
   void sell(const Transaction& t);
};

class SellMoreSharesException{
private:
  int insufficientQuantity;
public:
  SellMoreSharesException(int insufficientQuantity):insufficientQuantity(insufficientQuantity){}
  int getInsufficientQuantity()const {return insufficientQuantity;}  
}; 

#endif