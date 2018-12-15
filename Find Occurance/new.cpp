#include<iostream>
#include<vector>

using namespace std;
/********       Naive Approach prototype          ********/
//int linear_search(vector<int>, int);

/*******        Count the number of occurance        ********/
int count(vector<int>,int);

/*******        Binary Search           *******/
int binary_search(vector<int>, int, int, int, bool);


/********        Driver Function         ********/
int main()
{
  int target=0;
  vector<int> array={1,1,1,2,3,3,4,4,4,4,4,5,6,7,8};
  for(int z: array){
    cout<<z<<", ";
  }
  cout<<"\nEnter Target: ";
  cin>>target;
  cout<<endl;

  //cout<<"Number of counts of "<<target<<" : "<<linear_search(array,target)<<" (Linear Search) "<<endl;

  cout<<"Number of counts of "<<target<<" : "<<count(array,target)<<" (Binary Search) "<<endl;
}



/********       Naive Approach          ********
int linear_search(vector<int> array, int target=0){
  int occurance=0;

  for(int i=0;i< array.size();i++){
    if(array[i]  ==  target)    occurance++;
  }
  return occurance;
}*/



/******      Driver Function Count Number of Occurance       ******/
int count(vector<int> array, int target){
  int first_occurance = binary_search(array, 0, array.size()-1, target, true);
  int last_occurance = binary_search(array, first_occurance, array.size()-1, target,false)-1;

  if(first_occurance == -1 && last_occurance == -1)     return 0;
  

  return (last_occurance-first_occurance+1);

}

/*******        Binary Search Function         *******/
int binary_search(vector<int> array,int l,int r, int target, bool left){
  int mid;
  int last_occurance = -1 ;

  while(l <= r){

    mid = (l+r)/2;
    
    if(left && array[mid] == target){
      r = mid - 1;
      last_occurance = mid;
    }
     
    else if(target < array[mid]){
      r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return l;
}


