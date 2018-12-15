/******************************************
 **      Blue Print of Customer Queue    **
 ******************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include<queue>
#include"customer.h"

class CustomerQueueType
{
  public:
    queue<customerType>* front_of_q;
   
    CustomerQueueType();
   
    void updateWaitingQueue(int);

    bool empty();
    customerType front();
    void push(customerType);
    void pop();

    ~CustomerQueueType();
};

#endif
