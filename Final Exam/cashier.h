#ifndef CASHIER_H
#define CASHIER_H

#include<iostream>
#include"customer.h"

using namespace std;

class CashierType{
  public:
    customerType current_customer;
    string status;
    int transaction_time;

    CashierType();
};


#endif
