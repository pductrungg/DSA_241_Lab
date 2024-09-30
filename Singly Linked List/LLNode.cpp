LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
        LLNode* dummy = new LLNode(); // Dummy node to simplify result list creation
    LLNode* current = dummy;      // Pointer to build the new list
    int carry = 0;                // Variable to store carry during addition

    while (l0 != nullptr || l1 != nullptr || carry > 0) {
        int sum = carry; // Start with carry value

        // Add value from l0 if available
        if (l0 != nullptr) {
            sum += l0->val;
            l0 = l0->next;
        }

        // Add value from l1 if available
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Calculate the new digit and the new carry
        carry = sum / 10;
        sum = sum % 10;

        // Create a new node for the resulting digit
        current->next = new LLNode(sum, nullptr);
        current = current->next;
    }

    // Return the head of the resulting list (next of dummy node)
    return dummy->next;
}

LLNode* foldLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if(head==nullptr) return nullptr;
    LLNode* temp=head;
    int length=0;
    while(temp!=nullptr){
        length++;
        temp=temp->next;
    }
    temp=head;
    int *arr=new int[length];
    for(int i=0;temp!=nullptr;i++){
        arr[i]=temp->val;
        temp=temp->next;
    }
    int firsthalf,secondhalf;
    if(length%2==0){
        firsthalf=length/2-1;
        secondhalf=length/2;
    }
    else{
        firsthalf=length/2-1;
        secondhalf=length/2+1;
    }
    LLNode*ret_head=new LLNode();
    temp=ret_head;
    while(firsthalf>=0){
        temp->val=arr[firsthalf]+arr[secondhalf];
        if(firsthalf!=0){
            temp->next = new LLNode();
            temp=temp->next;
        }
        firsthalf--;
        secondhalf++;
    }
    if(length%2==0){
    }
    else{
        temp= new LLNode();
        temp->next=ret_head;
        temp->val=arr[length/2];
        ret_head=temp;
        
    }
    return ret_head;
}

LLNode* replaceFirstGreater(LLNode* head) {
    // STUDENT ANSWER
    LLNode* temp1=head,*temp2;
    while(temp1!=nullptr){
        bool changed=0;
        temp2=temp1->next;
        while(temp2!=nullptr){
            if(temp1->val<temp2->val){
                temp1->val=temp2->val;
                changed=1;
                break;
            }
            temp2=temp2->next;
        }
        if(!changed){
            temp1->val=0;
        }
        temp1=temp1->next;
    }
    return head;
}

LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if(head==nullptr) return nullptr;
    LLNode*prev=nullptr;
    LLNode*current=head;
    LLNode*next=nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
    
}

LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        LLNode* ret=new LLNode(head->val,nullptr);
        return ret;
    }
    int length=0;
    LLNode*temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        length++;
    }
    temp=head;
    k=k%length;
    LLNode*tail_part=nullptr,*temp_tail=nullptr;
    for(int i=0;i<length-k;i++){
        if(i==0){
            tail_part=new LLNode(temp->val,temp->next);
            temp_tail=tail_part;
        }
        else{
        temp_tail->next=new LLNode(temp->val,nullptr);
        temp_tail=temp_tail->next;
        }
        temp=temp->next;
    }
    LLNode*head_part,*temp_head;
    head_part=new LLNode(temp->val,nullptr);
    temp_head=head_part;
    temp=temp->next;
    //int cnt=0;
    while(temp!=nullptr){
       temp_head->next=new LLNode(temp->val,nullptr);
       //temp_head->next->val=temp_head->val=temp->val;
       temp=temp->next;
       //if(temp!=nullptr) 
       temp_head=temp_head->next;
       //cnt++;
    }
    temp_head->next=tail_part;
    return head_part;
}