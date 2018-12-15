/**************************************************
 **      Blue print of the customer type         **
 **************************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
using namespace std;

class customerType{
  friend ostream& operator<< (ostream& , const customerType& );
  friend istream& operator>> ( istream& , customerType& );

  public:
    int customer_number;
    int arrival_time;
    int wait_time;
    int transaction_time;
    
    customerType(int customer_number = 0, int arrival_time = 0, int wait_time = 0, int transaction_time = 0);
   
};

#endif



