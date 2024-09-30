int maxSum(int* nums, int n, int k) {
    int* dp = new int[n + 1](); 

    for (int i = 1; i <= n; i++) {
        int maxElem = 0; 
        
        for (int j = 1; j <= k && (i - j) >= 0; j++) {
            maxElem = max(maxElem, nums[i - j]); 
            int size = j;
            int currentSValue = maxElem * size; 
            
            dp[i] = max(dp[i], dp[i - j] + currentSValue);
        }
    }

    int result = dp[n];
    delete[] dp; 
    return result;
}