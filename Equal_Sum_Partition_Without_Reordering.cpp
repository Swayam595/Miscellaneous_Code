int split(vector<int> array){
    int templ = array[0], tempr = 0;
    int i = 1, j = 0;
    
    while(j != array.size()-1){
        tempr = array[i] + tempr;     //  Stores the right subarray sum
        i++;
        
        if(templ == tempr){           //  If the the sum of both the sub array are same return the index of maximum amount of left subarray
            return j;
        }
        else if(i == array.size()){   //  If the i counter is eqaual to array size then increment j value
            j++;
            i=j+1;                    //  Assign i value to j + 1
            templ = templ + array[j];   //  Stores the sum of left subarray
        
            tempr = 0;                //  Make the right subarray to 0
        }
        
    }
    return -1;                        //  Return -1 if there is no subarray
}
