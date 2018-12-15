#include<iostream>

#include"simulation.h"

using namespace std;


int main()
{
  SimulationType sim1;
  
  string file_name;
  int choice;

  cout << "Eneter Text File to satrt the simulation: ";
  cin >> file_name;            

  cout << "\n\nFOR CONVIENCE A TEXT COPY WILL BE MADE\n\n";

  sim1.runSimulation(file_name);
  

  while(1){
    cout << "\n\nType 1 to start simulation again with a new text file\n";
    cout << "Type 2 to statr simulation again with old text file\n";
    cout << "Type 0 to EXIT\n";
    
    cout<< "\n\nEnter your choice: ";
    cin >> choice;

    if(choice == 1){
      string new_file;
      
      cout << "Eneter Text File to satrt the simulation: ";
      cin >> new_file;
      cout<<endl;

      sim1.runSimulation(new_file);
    }
    else if(choice == 2){
      sim1.runSimulation(file_name);
    }
    else if(choice == 0){
      break;
    }
    else{
      cout<<"Enter Valid Choice";
    }
  }

  return 0; 
}


