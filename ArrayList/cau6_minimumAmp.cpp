int minimumAmplitude(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    if (n == 0 || k >= n) return 0; // No amplitude if removing all or more elements
    
    // Step 1: Calculate the initial maximum and minimum values
    int overallMax = INT_MIN;
    int overallMin = INT_MAX;

    for (int num : nums) {
        overallMax = max(overallMax, num);
        overallMin = min(overallMin, num);
    }

    // Step 2: Initialize the minimum amplitude with the overall amplitude
    int minAmplitude = overallMax - overallMin;

    // Step 3: Sliding window to find the minimum amplitude after removing sublists
    for (int i = 0; i <= n - k; i++) {
        // Determine the max and min of the remaining elements after removing nums[i] to nums[i + k - 1]
        int leftMax = INT_MIN;
        int leftMin = INT_MAX;

        int rightMax = INT_MIN;
        int rightMin = INT_MAX;

        // Find max and min for the left side
        for (int j = 0; j < i; j++) {
            leftMax = max(leftMax, nums[j]);
            leftMin = min(leftMin, nums[j]);
        }

        // Find max and min for the right side
        for (int j = i + k; j < n; j++) {
            rightMax = max(rightMax, nums[j]);
            rightMin = min(rightMin, nums[j]);
        }

        // Determine the new amplitude
        int newMax = max(leftMax, rightMax);
        int newMin = min(leftMin, rightMin);

        // Update the minimum amplitude
        if (newMax != INT_MIN && newMin != INT_MAX) {
            minAmplitude = min(minAmplitude, newMax - newMin);
        }
    }

    return minAmplitude;
}