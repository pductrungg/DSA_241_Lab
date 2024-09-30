vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
        int n = nums.size();
    vector<int> diff(n + 1, 0); // Difference array of size n + 1

    // Apply operations to the difference array
    for (const auto& op : operations) {
        int L = op[0];
        int R = op[1];
        int X = op[2];

        diff[L] += X; // Start adding X from index L
        if (R + 1 < n) {
            diff[R + 1] -= X; // Stop adding X after index R
        }
    }

    // Calculate the final values
    int currentAdd = 0; // To keep track of cumulative sum from the difference array
    for (int i = 0; i < n; i++) {
        currentAdd += diff[i]; // Update the cumulative sum
        nums[i] += currentAdd; // Apply the cumulative sum to nums
    }

    return nums;
}