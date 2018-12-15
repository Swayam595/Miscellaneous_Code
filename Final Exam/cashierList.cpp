#include<iostream>
#include<fstream>
#include"cashierList.h"

using namespace std;

/***    CashierListType Constructor     ***/
CashierListType :: CashierListType(int num_of_cashier){
  this->num_of_cashier = num_of_cashier;
  this->list = new CashierType[this->num_of_cashier];
}

/***    Finds the ID of the free cashier      ***/
int CashierListType :: getFreeCashierID(){
  int CashierID = -1;
   
  for(int i = 0 ; i < this->num_of_cashier ; i++){
    if( this->list[i].status == "free" ){
      CashierID = i;
      break;
    }
  }
  return CashierID;
}

/****   Finds the number of busy cashier      ****/
int CashierListType :: getNumberOfBusyCashier(){
  int busyCashiers = 0;

  for( int i = 0 ; i < this->num_of_cashier ; i++ ){
    if( this->list[i].status == "busy" ){
      busyCashiers++;
    }
  }

  return busyCashiers;
}

/*void CashierListType :: setCashierBusy(int CashierID, customerType cCustomer, int tTime){
  this->list[CashierID].status = "busy";
  this->list[CashierID].transaction_time = tTime;
  this->list[CashierID].current_customer = cCustomer;
}*/

/****   Sets a cashier busy if a customer comes for transaction     ***/
void CashierListType :: setCashierBusy(int CashierID, customerType cCustomer){
  this->list[CashierID].status = "busy";
  this->list[CashierID].transaction_time = cCustomer.transaction_time;
  this->list[CashierID].current_customer = cCustomer;
}

/****   If a cashier is busy then reduce its transaction time   ***/
void CashierListType :: updateCashier(string file_name){
  for( int i =0 ; i < this->num_of_cashier ; i++){
   if(this->list[i].status == "busy"){
      this->list[i].transaction_time--;
    
      if(this->list[i].transaction_time == 0){          //      If a customer is finsihed his transaction then store his/her information in the text file
        ofstream tofile;
        tofile.open(file_name,ios::app);
        tofile << "From cashier number " << (i+1)
                << " Customer number "
                << this->list[i].current_customer.customer_number
                << "\n departed at clock unit "
                << this->list[i].current_customer.arrival_time 
                + this->list[i].current_customer.wait_time
                + this->list[i].current_customer.transaction_time
               << endl<<endl;
        tofile.close();
        
        cout << "From cashier number " << (i+1)
                << " Customer number "
                << this->list[i].current_customer.customer_number
                << "\n departed at clock unit "
                << this->list[i].current_customer.arrival_time 
                + this->list[i].current_customer.wait_time
                + this->list[i].current_customer.transaction_time
               << endl<<endl;
        this->list[i].status = "free";
      }
    }
  }
}

CashierListType :: ~CashierListType(){
  delete [] this->list;
}
