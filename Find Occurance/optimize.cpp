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
  vector<int> array={5,7,7,8,8,9};
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
  int first_occurance = binary_search(array, 0, array.size()-1, target,true);	//	Finds the first occurance of the targeted number
  int last_occurance = binary_search(array, first_occurance, array.size()-1, target,false);		//	Finds the last occurance of the targeted number

  if(first_occurance == -1 && last_occurance == -1)     return 0;  //	If there is no target value then return 0

  return (last_occurance-first_occurance+1);	//	Returns the number of occurance of the targeted number

}

/*******        Binary Search Function         *******/
int binary_search(vector<int> array,int l,int r, int target,bool left){
  int mid;
  int last_occurance = -1 ;

  while(l <= r){

    mid = (l+r)/2;
    
    if(array[mid] == target){	//	If the targeted number is found 
      if(left)      r = mid - 1;	//	If we are searchinging for the first occuarance then search the from left pointer to last occurance of target   
      else      l = mid + 1;	//	If we are searching last occurance then change the left pointer the  
      last_occurance = mid;		//	Always remember where the last occurance of the targeted number was
    }
     
    else if(target < array[mid]){	//	If the there is no occurrence and target number is less than the number in middle then only search the numbers form the left to the middle
      r = mid - 1;
    }
    else{	//	Else if the number is greater than the number in the middle then only search the numbers form the middle to end of the array
      l = mid + 1;
    }
  }
  return last_occurance;	//	Return the last_occurance
}

