int pairMatching(vector<int>& nums, int target) {
    int count=0;
    //vector<pair<int,bool>> v;
    sort(nums.begin(),nums.end());
    int start=0;
    int end=nums.size()-1;
    while(start<end){
        if(nums[start]+nums[end]>target){
            end--;
        }
        else if(nums[start]+nums[end]<target){
            start++;
        }
        else{
            count++;
            start++;
            end--;
        }
    }
    return count;
}