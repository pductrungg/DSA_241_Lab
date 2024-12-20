class PrinterQueue
{
public:
    // your attributes
    class Node{
        public:
        Node*next;
        int pri;
        string s;
        Node(Node*next,int pri,string s){
            this->next=next;
            this->pri=pri;
            this->s=s;
        }
    };
    Node*root;
    PrinterQueue(){
        root=nullptr;
    }
public:
    // your methods
    void addNewRequest(int priority, string fileName)
    {
        if(root==nullptr) {
            root=new Node(nullptr,priority,fileName);
            return ;
        }
        Node*temp=root;
        Node*prev=nullptr;
        while(temp!=nullptr&&temp->pri>=priority){
            prev=temp;
            temp=temp->next;
        }
        if(prev==nullptr){
            Node* newroot=new Node(nullptr,priority,fileName);
            newroot->next=root;
            root=newroot;
        }
        else{
            Node *newnode=new Node(prev->next,priority,fileName);
            prev->next=newnode;
        }
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        //cout<<pq.size()<<endl;
        if (root==nullptr) {
            cout << "No file to print" << endl;
            return;
        }
        cout<<root->s<<endl;
        Node*temp=root->next;
        delete root;
        root=temp;
    }
};