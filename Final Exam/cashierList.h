/**********************************************************         
 **              Blueprint of CashierList                **
 **             Going to store a array of cashiers       **
 **********************************************************/

#ifndef CASHIERLISTTYPE_H
#define CASHIERLISTTYPE_H

#include<iostream>
#include"cashier.h"

using namespace std;

class CashierListType{
  public:
    int num_of_cashier;
    CashierType* list;

    CashierListType(int num_of_cashier = 1);
    
    int getFreeCashierID();
    int getNumberOfBusyCashier();
    void setCashierBusy(int, customerType, int);
    void setCashierBusy(int, customerType);
    void updateCashier(string);

    ~CashierListType();

};

#endif
