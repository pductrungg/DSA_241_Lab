void reduceDuplicate(Node* root)
{
        if(root == NULL) return;
    Node* str = root;
    while(str->getNext() != NULL) {
            Node* check = str->getNext();
            if(str->getData() == check->getData()) {
                check = check->getNext();
                free(str->getNext());
                str->setNext(check);
            } else str = str->getNext();
    }
}