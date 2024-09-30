int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
        if (words.empty()) {
        return 0;
    }

    int maxLength = 1; 
    int currentLength = 1; 

    for (int i = 1; i < words.size(); i++) {
        // Compare 
        if (words[i][0] == words[i - 1][0]) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }

    maxLength = max(maxLength, currentLength);

    return maxLength;
}