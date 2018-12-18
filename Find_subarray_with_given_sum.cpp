bool split(vector<int> array, int target){
    int sum = 0;
    int i = 0;      //  Slow counter
    int j = 0;      //  Fast counter
    
    while(i != array.size() - 1){         //  Iterate till the end of the array
        sum = sum + array[j];             //  Variable storing the sum of the subarray
        j++;
        
        if(target == sum){                //  Subarray sum is equal to the length then return true
            return true;
        }
        else if(sum > target){            //  If sum is greater than target then increment i 
            i++;
            sum = 0;                      //  Make sum as zero 
            j = i;                        //  Make j value as i
        }
    }
    return false;
}
