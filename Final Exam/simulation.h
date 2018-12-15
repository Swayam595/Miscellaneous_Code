/*************************************************
 **     Blue Print of Simulation of the input   **
 *************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>

#include"customer.h"
#include"cashier.h"
#include"cashierList.h"
#include"queue.h"

using namespace std;

class SimulationType{
  private:
    void setSimulationParameter(int&, int&);
    void generateStatistics(CashierListType&, CustomerQueueType&, int, int);

  public:
    SimulationType();
    void runSimulation(string);
};

#endif
