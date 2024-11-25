// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int countHelper(Node* root){
    if(root==nullptr) return 0;
    int count = 0;
    if(root->pLeft != nullptr && root->pRight!=nullptr){
        count++;
    }
    count += countHelper(root->pLeft);
    count += countHelper(root->pRight);
    return count;
}

int countTwoChildrenNode()
{
    return countHelper(this->root);
}
// STUDENT ANSWER END