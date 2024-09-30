template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    this->pList = pList;
    if (begin == true)
    {
        if (this->pList != nullptr)
        {
            this->current = pList->head;
            this->index = 0;
        }
        else
        {
            this->current = nullptr;
            this->index = -1;
        }
    }
    else
    {
        this->current = nullptr;
        this->index = (pList != nullptr? pList->size() : 0);
    }
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    if (current == nullptr)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    pList->removeAt(index);
    index -= 1;
    if (index == -1)
    {
        current = nullptr;
    }
    else
    {
        int i = 0;
        Node* x = pList->head;
        while (x != nullptr)
        {
            if (i == index)
            {
                break;
            }
            i++;
            x = x->next;
        }
        current = x;
    }
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    if (current == nullptr)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    current->data = e;
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    if (current == nullptr)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    return current->data;
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    return (current == iterator.current && index == iterator.index? false : true);

    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    if (index == pList->size())
    {
        throw std::out_of_range("Segmentation fault!");
    }
    index++;
    if (index == 0)
    {
        current = pList->head;
    }
    else
    {
        current = current->next;
    }
    return *this;
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    if (index == pList->size())
    {
        throw std::out_of_range("Segmentation fault!");
    }
    Iterator temp = *this;
    ++*this;
    return temp;
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
}

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
        Node* newNode = new Node(e, nullptr); // Create a new node with the data

    if (head == nullptr) { // If the list is empty
        head = newNode;    // Set head to the new node
        tail = newNode;    // Set tail to the new node
    } else {
        tail->next = newNode; // Link the new node to the last node
        tail = newNode;        // Update the tail to the new node
    }

    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
     if (index < 0 || index > count) {
        throw std::out_of_range("Index out of bounds"); // Handle invalid index
    }

    Node* newNode = new Node(e, nullptr); // Create a new node with the data

    if (index == 0) { // Insertion at the head
        newNode->next = head; // Link the new node to the current head
        head = newNode;       // Update head to the new node
        if (tail == nullptr) { // If the list was empty, update tail
            tail = newNode;
        }
    } else { // Insertion elsewhere
        Node* current = head;
        for (int i = 0; i < index - 1; i++) { // Traverse to the node before the insertion point
            current = current->next;
        }
        newNode->next = current->next; // Link the new node to the next node
        current->next = newNode;        // Link the previous node to the new node
        if (newNode->next == nullptr) { // If inserted at the end, update tail
            tail = newNode;
        }
    }

    count++; 
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index>=count||index<0) throw out_of_range("");
    Node * temp = head;
    while (index>=1)
    {
        temp = temp->next;
        index--;
    }
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index>=count||index<0) throw out_of_range("");
    Node * temp = head;
    while (index>=1)
    {
        temp = temp->next;
        index--;
    }
    temp->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (count>0) return 0;
    else return 1;
    
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node * temp = head;
    int index = 0;
    while (temp!=nullptr)
    {
        if (temp->data==item) return index;
        else{
        temp = temp->next;
        index++;
        }
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node * temp = head;
    while (temp!=nullptr)
    {
        if (temp->data==item) return 1;
        else{
        temp = temp->next;
        }
    }
    return 0;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    
    T result;
    Node *fhead = head;
    
    if (index == 0)
    {
        result = head->data;
        Node *tmp = head->next;
        Node *k = head; 
        head = tmp;
        delete k;
    }
    else if ((index < count - 1) && (index > 0))
    {
        for (int i = 1; i < index; i++)
            fhead = fhead->next;  
        result = fhead->next->data;
        Node *tmp = fhead->next;
        fhead->next = fhead->next->next;
        
        delete tmp;
        
    } else if (index == (count - 1))
    {
        result = tail->data;
        
        for (int i = 1; i < count - 1; i++)
            fhead = fhead->next;
        
        Node *tmp = tail;
        fhead->next = nullptr;
        
        delete tmp;
        tail = fhead;
    }
    count--;
    return result;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node* fhead = head;
    int index = 0;
    bool isFound = false;
    
    while(fhead)
    {
        if (fhead->data == item)
        {
            isFound = true;
            break;
        }
        index++;
        fhead = fhead->next;
    }
    
    if (!isFound) return false;
    
    fhead = head;
    
    if (index == 0)
    {
        Node *tmp = head->next;
        Node *k = head; 
        head = tmp;
        delete k;
    }
    else if ((index < count - 1) && (index > 0))
    {
        for (int i = 1; i < index; i++)
            fhead = fhead->next;  
            
        Node *tmp = fhead->next;
        fhead->next = fhead->next->next;
        
        delete tmp;
    } else if (index == (count - 1))
    {
        for (int i = 1; i < count - 1; i++)
            fhead = fhead->next;
        
        Node *tmp = tail;
        fhead->next = nullptr;
        
        delete tmp;
        tail = fhead;
    }
    
    count --;
    return true;
       
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    
    Node* current = head;
    
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
   }
   head = nullptr;
   tail = nullptr;
   count = 0;
}