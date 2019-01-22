#include <iostream>
#include <vector>

using namespace std;


class Node{
public:
    int data;
    Node *next;

    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};
void print(Node* head);
Node *delNode(Node *head, int pos);
Node *reverse(Node *head);
Node *insert(Node *head , int data ,int position);




int main() {

    Node *a= new Node(10);
    // cout<<a<<"a"<<endl;
    Node *b= new Node(5);
    // cout<<b<<"b"<<endl;
    Node *c= new Node(15);
    // cout<<c<<"c"<<endl;
    Node *d= new Node(20);
    // cout<<d<<"d"<<endl;
    Node *e= new Node(32);
    // cout<<e<<"e"<<endl;
    Node *f = new Node(21);
    // cout<<f<<"f"<<endl;



    Node *root=a;
    Node *tail=f;

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=NULL;

    print(root);
    cout<<endl;
    Node *n= insert(root,100,6);
    print(n);//call by value



//    Node *n = delNode(root,0);
//    cout<<"----"<<endl;
//    print(n);

}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node *delNode(Node *head, int pos){
    if(pos==0){
        return head->next;
    }
    Node *toReturn=head;
    Node *curr=head;
    Node *prev=head;
    int count=0;
    while(curr!=NULL){
        prev=curr;
        curr=curr->next;
        count=count+1;
        if(count==pos) {
            prev->next = curr->next;
            curr->next = NULL;
            cout << count << "count" << endl;
            cout << prev->next << "prevnext" << endl;
            cout << curr->next << "currnext" << endl;
            return toReturn;
        }
    }
}


Node *reverse(Node *head) {
    Node *it=head;
    Node *changer=head;
    Node *temp;
    int check=0;
    Node *arr[1000];
    int secondcount=0;
    int i = 0;
    int count =0;
    while (head != NULL) {
        arr[i] = head;
        i = i + 1;
        head = head->next;
    }

    for(int i=0 ; i<10 ;i++){
        cout<<arr[i]<<i<<endl;
    }
    while(it!=NULL){
        it=it->next;
        temp=changer->next;
        //cout<<temp<<"temp"<<endl;
        if(count==0){
            changer->next=NULL;
            changer=temp;
            count=count+1;
        }
        else{
            changer->next=arr[secondcount];
            changer=temp;
            secondcount=secondcount+1;
        }
    }

    head=arr[(secondcount+count)-1];
    return head;
}


Node *insert(Node *head , int data ,int position){

    if(position==0) {
        Node *newNode = new Node(data);
        Node *temp = head;
        head = newNode;
        newNode->next = temp;
        return head;
    }
    else{
        int count=1;
        Node *it = head;
        Node *temp;
        Node *newNode = new Node(data);
        while(head!=NULL){
            if(count==position){
                temp=head->next;
                head->next=newNode;
                newNode->next=temp;
                return it;
            }
            head=head->next;
            count=count+1;
        }

    }
}





