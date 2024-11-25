// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS()
{
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(q.size()){
        Node* temp = q.front();
        q.pop();
        
        cout << temp->value << " ";
        if(temp->pLeft){
            q.push(temp->pLeft);
        }
        if(temp->pRight){
            q.push(temp->pRight);
        }
    }
}
// STUDENT ANSWER END