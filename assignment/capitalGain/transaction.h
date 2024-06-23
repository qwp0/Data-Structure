#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction{
private:
  int quantity;
  int price;
public:
  Transaction(int quantity, int price):quantity(quantity),price(price){}
  int getQuantity() const{return quantity;}
  int getPrice() const{return price;}
};

#endif