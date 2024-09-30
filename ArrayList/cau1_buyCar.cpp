int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);

    int count = 0; // Counter to keep track of how many cars we can buy
    int totalCost = 0; // Sum of the car prices we've bought so far

    // Step 2: Buy cars while we have enough money
    for (int i = 0; i < length; i++) {
        if (totalCost + nums[i] <= k) { 
            totalCost += nums[i]; // Add the price of the car to the total cost
            count++; // Increase the count of cars bought
        } else {
            break; // Stop if we can't afford the next car
        }
    }

    return count;
}