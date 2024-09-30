int sumLessThanTarget(vector<int>& nums, int target) {
    // STUDENT ANSWER    
    int left = 0;
    int right = nums.size() - 1;
    int maxSum = 0; // Initialize maximum sum found

    while (left < right) {
        int currentSum = nums[left] + nums[right];

        if (currentSum < target) {
            maxSum = max(maxSum, currentSum);
            left++; // Move the left pointer to the right
        } else {
            right--;
        }
    }
    
    return maxSum;
}