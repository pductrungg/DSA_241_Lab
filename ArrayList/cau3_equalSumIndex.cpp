int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
        int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    
    int leftSum = 0; // Initialize left 
    
    for (int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i];
        
        if (leftSum == rightSum) {
            return i; // Return the index if equal
        }
        
        leftSum += nums[i];
    }
    
    return -1;
}