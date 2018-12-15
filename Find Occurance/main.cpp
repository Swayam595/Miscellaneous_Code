#include<iostream>
#include<vector>

using namespace std;
/********       Naive Approach prototype          ********/
//int linear_search(vector<int>, int);

/*******        Binary Search           *******/
int binary_search(vector<int>, int);


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

  cout<<"Number of counts of "<<target<<" : "<<binary_search(array,target)<<" (Binary Search) "<<endl;
}



/********       Naive Approach          ********
int linear_search(vector<int> array, int target=0){
  int occurance=0;

  for(int i=0;i< array.size();i++){
    if(array[i]  ==  target)    occurance++;
  }
  return occurance;
}*/

/*******        Binary Search           *******/
int binary_search(vector<int> array,int target = 0){
  int l = 0;
  int r = array.size()-1;
  int mid;
  int first_occurance = 0;
  int last_occurance;
  int count = 0;

  while(l <= r){
    mid = (l+r)/2;
    if(array[mid] == target){
      if(first_occurance == 0)      first_occurance = mid;
      //last_occurance = mid;
    }
     
    if(target < array[mid]){
      r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  


  //cout<<first_occurance<<"   "<<last_occurance<<endl; 
  //for(int i = first_occurance; i <= last_occurance ; i++ )         count++;
  
  for(int i = first_occurance ; i >= 0 && array[i] == target ; i--)    count++;
  for(int j = first_occurance + 1 ; j<= array.size() -1 && array[j] == target ; j++ ) count++;

  return count;
}
