int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> numCountMap;
        numCountMap[0] = 1;
        int runningSum = 0;
        int numToFind;
        
        for(int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            numToFind = runningSum-k;
            
            if (numCountMap.count(numToFind) > 0) {
                count += numCountMap[numToFind];
            }
            
            numCountMap[runningSum]++;
        }
        
        return count;
    }
