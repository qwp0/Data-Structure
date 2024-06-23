#include "stock.h"

using namespace std;

int StockTrade::getTotalGain(){return totalCapitalGain;}

void StockTrade::buy(const Transaction& t){
  transaction.push(t);
  totalQuantity += t.getQuantity();
}

void StockTrade::sell(const Transaction& t){
  int sellPrice = t.getPrice();
  int sellQuantity = t.getQuantity();
  
  while(sellQuantity > 0){
    if(sellQuantity > totalQuantity){
      throw SellMoreSharesException(sellQuantity-totalQuantity);
    }
    
    int buyQuentity = transaction.front().getQuantity();
    int buyPrice = transaction.front().getPrice();
    int soldQuentity = min(sellQuantity,buyQuentity);
    totalCapitalGain+=(sellPrice-buyPrice)*soldQuentity;

    if(sellQuantity>buyQuentity){
      transaction.pop();
    }
    else{
      transaction.front() = Transaction(buyQuentity-sellQuantity,buyPrice);
    }

    totalQuantity-=soldQuentity;
    sellQuantity-=soldQuentity;
  }
}