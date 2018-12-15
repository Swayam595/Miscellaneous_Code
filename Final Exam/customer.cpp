#include<iostream>
#include"customer.h"
using namespace std;

/******* Constructor the create customer ********/
customerType::customerType(int customer_number, int arriaval_time, int wait_time, int transaction_time){
  this->customer_number = customer_number;
  this->arrival_time = arrival_time;
  this->wait_time = wait_time;
  this->transaction_time = transaction_time;
}

/***** Ostream Operator Overloading *****/
ostream& operator << (ostream& out, customerType& customer){
  out << "[#" << customer.customer_number << " arival time = " << customer.arrival_time << " transaction time = " << customer.transaction_time << "Wait time = " << customer.wait_time<<" ]\n";
  return out;
}

/******* Istream Operator Overloading ********/
istream& operator >> (istream& in, customerType& customer){
  in >> customer.customer_number >> customer.arrival_time >> customer.transaction_time;
  return in;
}




