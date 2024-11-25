//Helping functions
int sum_leaf(Node* root){
    if(root == nullptr) return 0;
    
    int sum = 0;
    
    if(root->pLeft == nullptr && root->pRight == 0){
        sum += root->value;
    }
    sum += sum_leaf(root->pRight);
    sum += sum_leaf(root->pLeft);
    
    return sum;
}
int sumOfLeafs(){
    //TODO
    return sum_leaf(root);
}