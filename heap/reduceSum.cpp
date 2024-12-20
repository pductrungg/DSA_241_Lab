struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};
int reduceSum(vector<int>& nums) {
    // STUDENT ANSWER
    priority_queue<int,vector<int>,cmp> pq;
    for(unsigned int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }
    int sum=0;
    //return 1;
    while(pq.size()!=1){
        int t1=pq.top();
        pq.pop();
        int t2=pq.top();
        pq.pop();
        sum=sum+t1+t2;
        pq.push(t1+t2);
    }
    return sum;
    
}
