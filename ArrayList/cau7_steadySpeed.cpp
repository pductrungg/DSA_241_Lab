int steadySpeed(vector<int>& positions) {
    int n = positions.size();
    if (n < 2) return n; 
    int maxLength = 1; 
    int currentLength = 1; 
    int currentSpeed = positions[1] - positions[0]; 

    for (int i = 1; i < n - 1; i++) {
        int speed = positions[i + 1] - positions[i]; 
        
        if (speed == currentSpeed) {
            currentLength++; 
        } else {
            maxLength = max(maxLength, currentLength + 1); 
            currentLength = 1; 
            currentSpeed = speed; 
        }
    }
    
    maxLength = max(maxLength, currentLength + 1);

    return maxLength;
}