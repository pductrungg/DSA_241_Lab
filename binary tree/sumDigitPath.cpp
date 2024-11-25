int sumPath(BTNode* root, int sum){
    if(root ==  nullptr) return 0;
 sum = sum*10 + root->val;
    if(root->left == nullptr && root->right == nullptr){
        return sum;
    }
    return sumPath(root->left,sum) + sumPath(root->right,sum);
}

int sumDigitPath(BTNode* root) {
    return sumPath(root,0);
}