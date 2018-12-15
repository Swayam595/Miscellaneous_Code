#include<iostream>
#include<vector>
#include<math.h>        //      Contains the power and square root function
#include<algorithm>     //      Contains the sort function

using namespace std;

/***    Function to find the distance between two points***/
double dist(vector<int> x1,vector<int> x2){
  return sqrt(pow(x2[0]-x1[0],2)+pow(x2[1]-x1[1],2));
}

/***    Function to convert a array of points to distance between two points***/
vector<double> convert(vector<vector<int>> x){
  vector<double>   result;
  if(x.size()==0)       return result;
  double a;
  
  for(int i=0;i<x.size();i++){
    for(int j=0;j<x.size();j++){
      if(i!=j){
        a=dist(x[i],x[j]);
        result.push_back(a);
      }
    }
  }
  return result;
}


/****   Function to find pythagorus triplet     ****/
bool check(vector<double> x){
  for(int i=0;i<x.size();i++){          //  Find the square of each element of the vector and store it into the vector
    x[i]=pow(x[i],2);
  }

  sort(x.begin(),x.begin()+x.size());   //      Sort the vector in ascending order

  int l,r;      //      Two varaiables to store the left most and right most element of the subarray
  double RHS;   //      store the RHS of the pythagorus therorem
  
  for(int a=x.size()-1;a>=0;a--){       //      Take the right most elemnt as the LHS of the pythagorus theorem
    l=0;        //      Take the left element index of the subarray array
    r=a-1;      //      Take right elemnt index of the subarray
    while(l<r){         //      While l < r
      RHS=x[l]+x[r];    //      Finds and stores the RHS of the pythagorus theorem
      if(x[a]==RHS){    //      If LHS == RHS then print the pythagorus triplet
        cout<<"("<<sqrt(x[l])<<","<<sqrt(x[r])<<","<<sqrt(x[a])<<")"<<endl;     
        return true;
      }
      else if(RHS < x[a]){      //      If the RHS is less than the LHS then increment l
        l++;
      }
      else{     //      Else decrement r
        r--;    
      }
    }
  }
  return false; //      Return false if there are no pythagorus triplet 
}



int main()
{
  vector<vector<int>> x={{0,0},{9,21},{11,31},{4,21},{0,8},{4,3},{200,3},{400,1},{3,0},{6,213,},{0,4}};
  vector<vector<int>> y={{0,0},{0,4},{3,0}};
  //cout<<x[0][0]<<endl;
  vector<double> k=convert(y);
  vector<double> z={5,12,13};
  cout<<check(z)<<endl;
}
