#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<ctime>

#include"customer.h"
#include"cashier.h"
#include"cashierList.h"
#include"queue.h"
#include"simulation.h"

using namespace std;

SimulationType :: SimulationType(){
  ofstream tofile;
  tofile.open("Result.txt");
  tofile << "My name is MISHRA, SWAYAM SWAROOP MISHRA, last 4 digit of the ID is 5595\n";
  tofile.close();
}

/****           Function to start the simulation              ****/
void SimulationType :: runSimulation(string file_name){

  int simulationTime = 0;
  int numberOfCashiers = 0;
  double transaction_time = 0;
  int time_between_customer_arrival = 0;

  int custNumber = 0;
  int totalCust = 0;

  int total_wait_time_served_customers = 0;
  int totalWaitTime = 0;
  int numberOfCustomerServed = 0;
  int customersLeftInServer = 0;
  int clock = 0;
  int CashierID = 0;

  CustomerQueueType Queue;              //      Creates a Queue for Customer
  customerType customer, cust;          //      Creates customer

  ifstream fin;                 //      Input File Stream Object to read form the file give by user
  fin.open(file_name);          //      Opens the file
  if( !fin.is_open() ){           //      If invalid file then through an error and exit
    cout<<endl<<"ERROR: Enter a valid file name\n";
    exit(EXIT_FAILURE);
  }

  while( fin >> cust ){           //   Reads the input from the file and store into the queue   
    transaction_time = transaction_time + cust.transaction_time;        //Finds the total transaction time
    time_between_customer_arrival = cust.arrival_time - time_between_customer_arrival;  //      Finds the total displacement between two consecutive customer arrival
    totalCust++;                //      Finds total number of customers
    Queue.push(cust);
  }
  fin.close();


  setSimulationParameter(simulationTime, numberOfCashiers);     // Sets the Simulation Paramenter 
  
  CashierListType cashierList(numberOfCashiers);                // Creates an array of CashierListType object

  ofstream tofile;              //      Create a Output File Stream Object to write to the output file

  time_t tt;
  struct tm * ti;
  time (&tt);
  ti = localtime(&tt); 
    
  tofile.open("Result.txt",ios_base::app);                      //      Writes the output to Result.txt  
  tofile << "************   Begin Simulation   ***********\n";
  tofile << "Simulation Began at =  " << asctime(ti)<<endl;
  tofile.close();

  cout << "\n************   Begin Simulation   ***********\n\n";
  cout << "Simulation Began at =  " << asctime(ti)<<endl;

  for( clock = 1 ; clock <= simulationTime ; clock++){          //      Going to serve customers till the end of the Simulation
    cashierList.updateCashier("Result.txt");                        
  
    if(!Queue.empty()){
      Queue.updateWaitingQueue(clock);
    }

      CashierID = cashierList.getFreeCashierID();               //      Finds the any free cashier

      if(CashierID != -1 && !Queue.empty()){                    //      If free cashier is present then send customer in the fornt of the queue to the cashier
        custNumber++;                                           //      Counts the number of customers served
        customer = Queue.front();                              
        Queue.pop();
        total_wait_time_served_customers = total_wait_time_served_customers + customer.wait_time;       //      Calculates the total waiting time of the served customer
        cashierList.setCashierBusy(CashierID, customer);        //      Makes the cashier unavailabe or busy
      }
    }

  cout << endl;
  
  tofile.close();
  tofile << "Simulation Ran for " << simulationTime << " Time units" <<endl;
  tofile << "Number of Cashiers: " << numberOfCashiers << endl;
  tofile << "Average transaction time: " << transaction_time/custNumber << endl;
  tofile << "Average arrival time difference between customers: " << time_between_customer_arrival/totalCust << endl<<endl;

  cout << "Simulation Ran for " << simulationTime << " Time units" <<endl;
  cout << "Number of Cashiers: " << numberOfCashiers << endl;
  cout << "Average transaction time: " << transaction_time/custNumber << endl;
  cout << "Average arrival time difference between customers: " << time_between_customer_arrival/totalCust << endl<<endl;

  tofile.close();

  generateStatistics(cashierList, Queue, totalCust, total_wait_time_served_customers);          //      Call for generating statistics
}

/*******        Sets Simulation Parameter       *********/
void SimulationType :: setSimulationParameter(int& simTime, int& num_of_cashiers){
  cout<< "Enter simulation time: ";
  cin >> simTime;

  cout<< "Enter Number of Cashiers: ";
  cin >> num_of_cashiers;

}

/********       Generates Statistics    for the given set of input      *********/
void SimulationType :: generateStatistics(CashierListType& cashierList, CustomerQueueType& Queue, int numOfCustArrived, int waitTimeServedCustomers){
  int customerLeftInQueue = 0;
  int totalWaitTime = waitTimeServedCustomers;

  customerType customer;
  
  while(!Queue.empty()){                         //     If customers are present in the queue then find there witing time and count there number      
    customer = Queue.front();
    Queue.pop();
    totalWaitTime = totalWaitTime + customer.wait_time;
    customerLeftInQueue++;
  }

  int customerLeftInServers = cashierList.getNumberOfBusyCashier();                                     //      Finds the number of cashiers are still busy or total numbers customers still doing transcation

  int numberOfCustomerServed = numOfCustArrived - customerLeftInServers - customerLeftInQueue;          //      Finds the total number of customers served

  double averageWaitTime = 0;           

  ofstream tofile;                               //      Writes the statistics into the Result.txt
  tofile.open("Result.txt",ios::app);

  tofile << "Total wait time: " << totalWaitTime <<endl;
  tofile << "The number of customers who completed a transaction: " << numberOfCustomerServed << endl;
  tofile << "The number of customers still at cashier counter: " << customerLeftInServers << endl;
  tofile << "The number of customers left the queue: " << customerLeftInQueue << endl << endl;

  cout << "Total wait time: " << totalWaitTime <<endl;
  cout << "The number of customers who completed a transaction: " << numberOfCustomerServed << endl;
  cout << "The number of customers still at cashier counter: " << customerLeftInServers << endl;
  cout << "The number of customers left the queue: " << customerLeftInQueue << endl << endl;

  if(numOfCustArrived > 0){
    averageWaitTime = (static_cast<double>(totalWaitTime)) / numOfCustArrived;
  }

  time_t tt;
  struct tm * ti;
  time (&tt);
  ti = localtime(&tt); 
    
  tofile << fixed << showpoint;
  tofile << setprecision(2);
  tofile << "Average wait time: " <<averageWaitTime << endl << endl;
  tofile << "Simulation Ended at = " << asctime(ti)<<endl;
  tofile << "********* End Simulation **********" << endl; 

  cout << fixed << showpoint;
  cout << setprecision(2);
  cout << "Average wait time: " <<averageWaitTime << endl << endl;
  cout << "Simulation Ended at = " << asctime(ti)<<endl;
  cout << "********* End Simulation **********" << endl; 

  tofile.close(); 
}
