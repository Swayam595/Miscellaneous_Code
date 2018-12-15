#include<queue>
#include"queue.h"
#include"customer.h"

/*****  Constructor to allocate the queue dynamically *****/
CustomerQueueType :: CustomerQueueType(){
  this->front_of_q = new queue<customerType>;
}

/****** If the customer is waiting then increment his waiting time ******/
void CustomerQueueType :: updateWaitingQueue(int clock){
  customerType cust;
  int i = 0;
  
  while(i != this->front_of_q->size()){         //      Iterate only once over all the coustmoer only once in each clock cycle 
    
    cust = this->front_of_q->front();
    this->front_of_q->pop();

    i++;
    if(cust.arrival_time <= clock){             //      Increment those customers whose arrival time is less than the current clock
      cust.wait_time++;
    }
    this->front_of_q->push(cust);
  }
}

/*****  Push Customer into the queue  *****/
void CustomerQueueType :: push(customerType cust){
  this->front_of_q->push(cust);
}

/*****  Finds if the queue is empty or not  *****/
bool CustomerQueueType :: empty(){
  return this->front_of_q->empty();
}

/*****  Returns the Front customer *****/
customerType CustomerQueueType :: front(){
  return this->front_of_q->front();
}

/*****  Removes the front customer form the queue *****/
void CustomerQueueType :: pop(){
  this->front_of_q->pop();
}

/*****  Destructor to dealocate the dynamically allocated queue*****/
CustomerQueueType :: ~CustomerQueueType(){
  delete this->front_of_q;
}
