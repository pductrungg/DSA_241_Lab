bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
        if (nums.empty()) {
        return true;
    }

    bool foundOne = false; 
    bool encounteredZeroAfterOne = false;

    for (int num : nums) {
        if (num == 1) {
            if (encounteredZeroAfterOne) {
                return false;
            }
            foundOne = true; 
        } else if (num == 0) {
            if (foundOne) {
                encounteredZeroAfterOne = true; 
            }
        }
    }

    return true;
}