#include <iostream>

#include<vector>



using namespace std;

/****	Produces the Base 7 number ****/
vector<int> b7(int n){
    
	int a=0;
    
	vector<int> ans,temp;	//	When BASE 7 number is produced it is in reverse oreder so temp is 
				// 	store and the ans is used to store the value in proper order    
	
	while(n>0){
       //	Iterate till the number is greater than 0
		a=n%7;
        //	Find the reminder when the number is divided by 7
		temp.push_back(a);
        //	Push the reminder into temp vector
		n=n/7;
    	//	Divide the number by 7
	}
    
    
	
	for(int i=temp.size()-1;i>=0;i--){
  	//	Start from the end of the temp vector and     
		ans.push_back(temp[i]);
    	//	Push the last element of temp into ans vector 
	}
    
	
	return ans;

}

int main()

{
    
    
	vector<int> x=b7(49);
  
	  for(int a:x){
        
		cout<<a<<" ";
    
	}
    
	return 0;

}
