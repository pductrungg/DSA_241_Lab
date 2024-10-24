ListNode* reverse(ListNode* head, int a, int b) {
    if(head==nullptr){
        return head;
    }
    ListNode*temp=head;
    int i;
    for(i=1;i<a;i++){
        temp=temp->right;
    }
    ListNode*head_rev_start=temp;
    ListNode*start_part=temp->left;
    int delta =b-a;
    while(delta>=0){
        ListNode*dummy = temp->right;
        temp->right=temp->left;
        temp->left=dummy;
        if(delta!=0){
            temp=dummy;
        }
        delta--;
    }
    ListNode*end_part=temp->left;
    // link the start the rev and the end
    if(start_part!=nullptr){
        start_part->right=temp;
        temp->left=start_part;
    }
    else{
        head=temp;
        temp->left=nullptr;
    }
    if(end_part!=nullptr){
        end_part->left=head_rev_start;
        head_rev_start->right=end_part;
    }
    else {
        head_rev_start->right=nullptr;
    }
    return head;
}