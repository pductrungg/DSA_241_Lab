void LinkedList::partition(int k) {
    Node*head1=nullptr,*head2=nullptr,*head3=nullptr,*tail1,*tail2,*tail3,*temp;
    for(temp=head;temp!=nullptr;temp=temp->next){
        if(temp->value<k){
            if(head1==nullptr){
                head1 = temp;
                tail1=head1;
                //head=head1;
            }
            else{
                tail1->next=temp;
                tail1=tail1->next;
                //temp=temp->next;
            }
            //temp=temp->next;
        }
        if(temp->value==k){
            if(head2==nullptr){
                head2 = temp;
                tail2=head2;
                //if(head1){
                //    head=head2;
                //}
            }
            else{
                tail2->next=temp;
                tail2=tail2->next;
                //temp=temp->next;
            }
            //temp=temp->next;
        }
        if(temp->value>k){
            if(head3==nullptr){
                head3 = temp;
                tail3=head3;
            }
            else{
                tail3->next=temp;
                tail3=tail3->next;
                //temp=temp->next;
            }
            //temp=temp->next;
        }

    }
    if(head1!=nullptr&&head2!=nullptr&&head3!=nullptr){
    head=head1;
    tail1->next=head2;
    tail2->next=head3;
    tail=tail3;
    tail->next=nullptr;
    }
    if(head1!=nullptr&&head2!=nullptr&&head3==nullptr){
        head=head1;
        tail1->next=head2;
        tail=tail2;
        tail->next=nullptr;
    }
    if(head1!=nullptr&&head2==nullptr&&head3!=nullptr){
        head=head1;
        tail1->next=head3;
        tail=tail3;
        tail->next=nullptr;
        
    }
    if(head1&&!head2&&!head3){
        head=head1;
        tail=tail1;
        tail->next=nullptr;
    }
    if(head1==nullptr&&head2!=nullptr&&head3!=nullptr){
        head=head2;
        tail2->next=head3;
        tail=tail3;
        tail->next=nullptr;
    }
    if(!head1&&head2&&!head3){
        head=head2;
        //tail2->next=head3;
        tail=tail2;
        tail->next=nullptr;
    }
    if(!head1&&!head2&&head3){
        head=head3;
        tail=tail3;
        tail->next=nullptr;
    }
    if(!head1&&!head2&&!head3){
        return ;
    }
    
    
}

void LinkedList::replace(LinkedList* linked_list, int low, int high) {
    Node* temp = head;
    Node* hold = nullptr;
    if (low < 0) {
        low = 0;
    }
    if (high >= size) {
        high = size-1;
    }
    for (int i = 0; i < low; i++) {
        if (i == (low - 1)) { hold = temp; }// giữ lại để lát nối với chuỗi
        temp = temp->next;
    }
    Node* delete_node = temp;//delete các node 
    //cout << high << endl;
    for (int i = low; i <= high; i++) {
        //cout << i << endl;
        temp = temp->next;//dời note trc khi xóa
        delete delete_node;
        delete_node = temp;
    }
    if (linked_list != nullptr&&linked_list->head!=nullptr) {
        if (hold != nullptr)hold->next = linked_list->head;//nối chuỗi 
        else head = linked_list->head;//nếu ko có hold tức là xóa từ head trở đi nên ta sẽ cho head=linked_list->head
        linked_list->tail->next = temp;//nối phần đuôi linked_list với phần còn lại node
        if(linked_list->tail->next==nullptr){
            tail=linked_list->tail;//update cái tail
        }
        else{
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            tail=temp;//update cái tail
        }
    }
    else {//nếu linked_list là nullptr hoặc linked_head là nullptr thì chạy phần này 
        if (hold != nullptr) hold->next = temp;
        else head = temp;
    }
}