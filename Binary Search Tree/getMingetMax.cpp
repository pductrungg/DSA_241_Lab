// STUDENT ANSWER BEGIN
T getMin() {
    Node* tmp = root;
    while(tmp->pLeft){
        tmp = tmp->pLeft;
    }
    return tmp->value;
    
}

T getMax() {
     Node* tmp = root;
    while(tmp->pRight){
        tmp = tmp->pRight;
    }
    return tmp->value;   //TODO: return the maximum values of nodes in the tree.
    
}