#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
#include <iostream>
#include <cstring>
using namespace std;
struct Node {
    int roll;
    int marks;
    char name[20];
    Node *pointer;
};

Node* create(){
    Node *node;
    int roll,marks;
    char name[20];
    cout<<"\nEnter details =>\n";
    cout<<"Roll number :";
    cin>>roll;
    cout<<"Marks :";
    cin>>marks;
    cout<<"Name :";
    cin>>name;
    cout<<"\n";
    node = new Node;
    node->roll = roll;
    node->marks = marks;
    strcpy(node->name,name);
    node->pointer = NULL;
    return node;
}
void beautify(){
    cout<<"------------------------------------------------------------------------"<<endl;
}

void display(Node *head){
    Node *node = head;
    int i = 1;
    cout<<"Serial Number         Roll Number       Name                     Marks"<<endl;
    beautify();
    while(node != NULL){
        cout<<"\t"<<i<<"\t\t"<<node->roll<<"\t\t"<<node->name<<"\t\t\t  "<<node->marks<<endl;
        beautify();
        node = node->pointer;
        i++;
    }
}

Node* insertEnd(Node *head){
    Node *node,*p = head;
    node = create();
    while(p->pointer != NULL){
        p = p->pointer;
    }
    p->pointer = node;
    return head;
}
Node* insertBeg(Node *head){
    Node *node,*p = head;
    node = create();
    node->pointer = p;
    return node;
}
Node* insertBet(Node *head,int position){
    Node *node,*p,*q;
    int count = 1,prevCount = 0;
    node = create();
    p = head;
    q = head;
    while(count < position){
        p = p->pointer;
        if(count > 1){
            q = q->pointer;
            prevCount++;
        }
        count++;
    }
    node->pointer = p;
    q->pointer = node;
    return head;
}
Node* deleteNode(Node *head, int position){
    Node *node = head,*prev = head;
    int count = 1,prevCount = 0;
    while(count < position){
        node = node->pointer;
        if(count > 1 ){
            prev = prev->pointer;
            prevCount++;
        }
        count++;
    }
    if (node == NULL){
        cout<<"Position does not exist!\n";
        cout<<"Please try again.\n";
    }
    else{
        prev->pointer = node->pointer;
        delete(node);
    }
    return head;

}

void searchRoll(Node *head, int roll){
    Node *p = head;
    int i = 1;
    cout<<"Serial Number         Roll Number       Name                     Marks"<<endl;
    while(p != NULL){
        if (p->roll == roll){
            beautify();
            cout<<"\t"<<i<<"\t\t"<<p->roll<<"\t\t"<<p->name<<"\t\t\t  "<<p->marks<<endl;
        }
        i++;
        p = p->pointer;
    }
}
void searchMarks(Node *head, int marks){
    Node *p = head;
    int i = 1;
    cout<<"Serial Number         Roll Number       Name                     Marks"<<endl;
    while(p != NULL){
        if (p->marks == marks){
            beautify();
            cout<<"\t"<<i<<"\t\t"<<p->roll<<"\t\t"<<p->name<<"\t\t\t  "<<p->marks<<endl;
        }
        i++;
        p = p->pointer;
    }
}

Node* reverse(Node *head){
    Node *p = head,*sub1,*sub2;
    sub1 = p->pointer;
    p->pointer = NULL;
    while(sub1 != NULL && sub2 != NULL){
        sub2 = sub1->pointer;
        sub1->pointer = p;
        p = sub1;
        if (sub2 != NULL){
            sub1 = sub2->pointer;
            sub2->pointer = p;
            p = sub2;
        }
    }
    return p;
}

int main(){
    Node *head;
    head = create();
    beautify();
    int input = -1;
    while( input != 0){
        cout<<"\n0. Exit";
        cout<<"\n1. Insert\n";
        cout<<"2. Display\n";
        cout<<"3. Delete\n";
        cout<<"4. Search\n";
        cout<<"5. Reverse\n\nEnter the choice code :";
        cin>>input;
        beautify();
        switch(input){
            case 1:
                int in2;
                cout<<"\n1. Insert at beginning\n";
                cout<<"2. Insert in between\n";
                cout<<"3. Insert at end\n";
                cin>>in2;
                beautify();
                switch(in2){
                    case 1:
                        head = insertBeg(head);
                        break;
                    case 2:
                        int position;
                        cout<<"Enter the position at which the record should be inserted :";
                        cin>>position;
                        head = insertBet(head,position);
                        break;
                    case 3:
                        head = insertEnd(head);
                        break;
                }
                break;
            case 2 :
                display(head);
                break;
            case 0:
                break;
            case 3:
                int position;
                cout<<"Enter the position to be deleted :";
                cin>>position;
                deleteNode(head,position);
                break;
            case 4:
                int num;
                cout<<"Search by \n1.Roll Number \n2.Marks\n";
                cin>>num;
                switch(num){
                    case 1:
                        int roll;
                        cout<<"Enter the roll number to be searched :\n";
                        cin>>roll;
                        searchRoll(head,roll);
                        beautify();
                        break;
                    case 2:
                        int marks;
                        cout<<"Enter the marks to be searched :\n";
                        cin>>marks;
                        searchMarks(head,marks);
                        beautify();
                        break;
                }

                break;
            case 5:
                head = reverse(head);
        }
    }
    return 0;
}

#pragma clang diagnostic pop