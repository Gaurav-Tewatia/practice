#include<iostream>
#include<algorithm>
using namespace std;

// A linked list is a collection of nodes 
// A node contains some data in it and a pointer which stores the address of the next node
// In a doubly linked list node also stores the address of the previous node 


//class to make a node 

class node{
    public:
    int data;
    node *next;
    node*prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};


//this is the funciton to insert at the start of a singly linked list

void insertathead(node*&head,int d){
    if(head==NULL){                //this to handle the case when list is empty
        head=new node(d);
        return;
    }

    node*temp=new node(d);
    temp->next=head;
    head=temp;
}



// this it to insert at the end of the singly linked list

void insertatend(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(d);

}


// this function tells you the number of elementes in the singly linked list

int size(node*head){
    int count=1;
    while(head->next!=NULL){
        head=head->next;
        count++;
    }
    return count;
}


// This function is used to insert at any random position inside the singly linked list

void insertatmiddle(node*&head,int d, int pos){
    if(head==NULL){
        head=new node(d);
        return;
    }
    if(pos==1){
        insertathead(head,d);
        return;
    }
    if(pos>=size(head)){
        insertatend(head,d);
        return;
    }
   
    node*temp=head;
    int cur=1;
    while(cur<pos-1){
        temp=temp->next;
        cur++;
    }
    node*n=new node(d);
    n->next=temp->next;
    temp->next=n;

    

}

// It is used to delete at the head of the singly linked list

void deleteathead(node*&head){
    if(head==NULL)
    return;

    node*temp=head->next;
    delete head;
    head=temp;
    
    return;
}



// this is used to delete at the tail of singly linked list


void deleteattail(node*&head){

    node*temp=head;
    
    node*prev=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=NULL;

    return;
}


//this is used to delete at the middle of the singly linked list

void deleteatmiddle(node*&head,int pos){
    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    if(pos>=size(head)){
        deleteattail(head);
        return;
    }
    int cur=1;
    node*temp=head;
    node*prev=head;
    
    while(cur<pos-1){
        temp=temp->next;
        prev=prev->next;
        cur++;
    }
    temp=temp->next;
    prev->next=temp->next;
    delete temp;


    return;
}



// this function returns a bollean value of true/false if the element is found in the singly linked list or not respectively

bool searchdata(node*head,int d){

    if(head->data==d)
    return true;

    while(head->next!=NULL){
        head=head->next;
        if(head->data==d)
        return true;
        
    }
    if(head->data==d)
    return true;
    else
    return false;

}

// This function search for the value at a particular position in the singly linked list

void searchposition(node*head,int pos){
    int cur=1;
    if(pos>size(head)){
        cout<<"out of bounds";
        return;
    }
    
    while(cur<pos){
        head=head->next;
        cur++;
    }
    cout<<head->data;
}


// It is used to print the singly and doubly linked list

void print(node*head){
    
    while(head->next!=NULL){
        cout<<head->data<<",";
        head=head->next;
    }
    cout<<head->data;
}


// It is used to make a singly linked list
// Just keep isnerting the elements till you want to insert at least provide -1 to terminate insertion


node* input(){
    int n;
    
    cout<<"enter the numbers in the list";
    node*head=NULL;
    cin>>n;
    while(n!=-1){
        insertatend(head,n);
        cin>>n;
        
    }
    return head;
}


// this is operator overloading so that cout<< can work as we know it works

ostream & operator <<(ostream& os,node* head){
    print(head);
    return os;
}


// Similarly this for the proper and normal functioning of cin>> operator

istream & operator >>(istream& is, node* &head){
    head=input();
    return is;
}


// this function will reverse your singly linked list

void reverselist(node*& head){
    node*n;;
    node*curr=head;
    node*prev=NULL;
    while(curr!=NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    head=prev;
}


// this will also reverse your singly linked list but using recursion


node* recursivereverse(node*& head){
    if(head->next==NULL or head==NULL)
     return head;

    node*temp=head;
    node*shead=recursivereverse(head->next);
    temp->next->next=head;
    head->next=NULL;

    return shead;

}


// This is used to find the middle element of the list

node* middlepoint(node*head){
    if(head==NULL or head->next==NULL)
    return head;

    node*slow=head;
    node*fast=head->next;
    while(fast and fast->next){  
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


// this is used to join two sorted singly linked list into one sorted list

node* join(node*head,node*oyo){
    if(head==NULL){
        return oyo;
    }
    if(oyo==NULL){
        return head;
    }
    node*n;

    if(head->data<=oyo->data){
        n=head;
       n->next= join(head->next, oyo);
    }
    else{
        n=oyo;
       n->next= join(head,oyo->next);
    }

    return n;
}


//this is to mergeosrt to list in order for the list to be sorted in ascending order

node* mergesort(node*head){
    if(head==NULL or head->next==NULL)
    return head;

    node*middle=middlepoint(head);
    node*b=middle->next;
    middle->next=NULL;
    
    head=mergesort(head);
    b=mergesort(b);

    node*c=join(head,b);
    return c;
}


// This is to find the kith node from the last of the list

int kthnode(node*head,int k){
    node*slow=head;
    while(k){
        head=head->next;
        k--;
    }
    while(head->next!=NULL){
        slow=slow->next;
        head=head->next;
    }
    return slow->data;
}


// this is to make a cycle inside the singly linked list

void makecycle(node*&head,int k){
    if(head==NULL or head->next==NULL)
    return ;

    node*temp=head;
    while(k){
        temp=temp->next;
        k--;
    }

    node*c=head;
    while(c->next!=NULL){
        c=c->next;
    }
    c->next=temp;



}


// This is to detect wether the cycle exist or not withing the list

bool detectcycle(node*head){
    node*slow=head,*fast=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }

    return false;
}

// if the cycle exist this function can be used to remove that cycle in the list

void removecycle(node*&head){
    node*slow=head,*fast=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            break;
        }
    }

    while(slow->next!=fast){
        slow=slow->next;
    }
    slow->next=NULL;

}


// this is to create a doubly linked list

void doubllylist(node*&head){
    if(head==NULL)
    cin>>head;

    node*pre=NULL;
    node*temp=head;
    while(temp->next){
        temp->prev=pre;
        pre=temp;
        temp=temp->next;
    }
    temp->prev=pre;
    
}


// insertion at head of the doubly linked list

void insertatheaddouble(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}


// insertion at the tail of the doubly linked list

void insertattaildouble(node*&head, int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*temp=new node(d);
    node*n=head;
    while(n->next){
        n=n->next;
    }
    n->next=temp;
    temp->prev=n;
}


//insertion at some random position of the list(doubly)

void insertatmiddledouble(node*&head,int d, int pos){
    if(head==NULL)
    head=new node(d);
    else if(pos==1)
    insertatheaddouble(head,d);
    else if(pos>size(head))
    insertattaildouble(head,d);

    node*temp=head;

    while(pos){
        temp=temp->next;
        pos--;
    }
    temp=temp->prev;
    node*n=new node(d);
    n->next=temp;
    n->prev=temp->prev;
    temp->prev=n;
    temp=temp->prev->prev;
    temp->next=n;

}


// this is to delete at the head of the doubly linked list

void deleteatheaddouble(node*&head){
    node*temp=head;
    temp=temp->next;
    delete head;
    head=temp;
    head->prev=NULL;
}


// deletion at the tail of the doubly linked list

void deleteattaildouble(node*&head){
    node*temp=head;
    node*pre=NULL;
    while(temp->next){
        pre=temp;
        temp=temp->next;
    }
    delete temp;
    pre->next=NULL;
    

}


//delettion at some ransom position inside the doubly linked list


void deleteatmiddledouble(node*&head,int pos){
    if(pos>=size(head)){
        deleteattaildouble(head);
        return;
    }
    if(pos==1){
        deleteatheaddouble(head);
        return;
    }
    
    node*n=head->next;
    node*pre=NULL;
    node*cur=head;
    pos--;
    while(pos){
        pre=cur;
        cur=n;
        n=n->next;
        pos--;
    }
    pre->next=cur->next;
    n->prev=cur->prev;
    delete cur;
}


// this is to create a circular doubly linked list

void circularlist(node*&head){
    if(head==NULL){
        doubllylist(head);
    }
    

    node*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
}


//insertion at the head of circular doubly linked list

void insertatheadcircular(node*&head,int d){
    if(head==NULL){
    head=new node(d);
    head->next=head;
    head->prev=head;
    return;}

    node*n=new node(d);
    node*temp=head->prev;
    

    temp->next=n;
    n->prev=temp;
    n->next=head;
    head->prev=n;
    head=n;


}


// insertion at the tail of circular doubly linked list

void insertattailcircularl(node*&head,int d){
    if(head==NULL)
    {head=new node(d);
    head->next=head;
    head->prev=head;
    return;
    }

    node*n=head->prev;
    

    node*temp=new node(d);
    temp->next=head;
    temp->prev=n;
    n->next=temp;
    head->prev=temp;

}


// this function is used to calculate the size of the circualar doubly linked list


int sizecircular(node*head){
    node*temp=head;
    int count=1;
    while(temp->next!=head){
        temp=temp->next;
        count++;
    }
    
    return count;
}


//insertion at the middle of circular doubly linked list


void insertatmiddlecircular(node*&head,int d, int pos){
    pos=pos%sizecircular(head);
    if(pos==sizecircular(head)){
        insertattailcircularl(head,d);
        return;
    }
    if(pos==1){
        insertatheadcircular(head,d);
        return;
    }

    pos--;
    node*pre=NULL;
    node*temp=head;
    while(pos){
        pre=temp;
        temp=temp->next;
        pos--;
    }
    node*n=new node(d);
    n->next=temp;
    n->prev=pre;
    pre->next=n;
    temp->prev=n;

    
}


// this function is used to print the circular doubly linked list


void printcircular(node*head){
    node*temp=head;
    while(head->next!=temp)
    {
        cout<<head->data<<",";
        head=head->next;
    }
    cout<<head->data;
}


//deletion at the head of circular doubly linked list


void deleteatheadcircular(node*&head){
    if(head==NULL)
    return;

    node*temp=head->next;
    head->next->prev=head->prev;
    head->prev->next=head->next;
    delete head;
    head=temp;

}


//deletion at the tail of circular doubly linked list


void deleteattailcircular(node*&head){
    if(head==NULL)
    return;

    node*temp=head->prev;
    temp->prev->next=head;
    head->prev=temp->prev;
    delete temp;
}


//deletion at the middle of the circular doubly linked list

void deleteatmiddlecircular(node*&head,int pos){
    pos=pos%sizecircular(head);
    if(pos==sizecircular(head))
    deleteattailcircular(head);
    else if(pos==1)
    deleteatheadcircular(head);
    else{
        --pos;
        node*temp=head;

        while(pos){
            temp=temp->next;
            pos--;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;

    }
}



// this is your main function 

int main()
{
    node*head=NULL;

    char ch='Y';
    
    int choice;
    do{cout<<"choose your choice "<<endl;
    cout<<"1. insert into list in one shot"<<endl;
    cout<<"2. insert at head"<<endl;
    cout<<"3. insert at the end"<<endl;
    cout<<"4. insert at the middle"<<endl;
    cout<<"5. delete at the head"<<endl;
    cout<<"6. delete at the middel"<<endl;
    cout<<"7. delete at the tail"<<endl;


    cout<<"8. search according to the data"<<endl;
    cout<<"9. search according the position"<<endl;
    cout<<"10. print the list"<<endl;
    cout<<"11. find the size of the list"<<endl;
    cout<<"12. reverse the list"<<endl;
    cout<<"13. recursive reverse "<<endl;
    cout<<"14. middle point of the list"<<endl;
    cout<<"15. kth node from the end"<<endl;
    cout<<"16. join two sorted list"<<endl;
    cout<<"17. merge sort linked list"<<endl;

    cout<<"18. make a floyd cycle"<<endl;
    cout<<"19. floyd cycle detection"<<endl;
    cout<<"20. Remove floyd cycle"<<endl;


    cout<<"21. create doubly linked list"<<endl;
    cout<<"22. insert at head of double list"<<endl;
    cout<<"23. insert at tail of double list"<<endl;
    cout<<"24. insert at the middle of double list"<<endl;
    cout<<"25. delete at head of the double list"<<endl;
    cout<<"26. delete at the tail of the double lsit"<<endl;
    cout<<"27. delete at the middle of the double lsit"<<endl;


    cout<<"28. create circular linked list"<<endl;
    cout<<"29. insert at head of circular list"<<endl;
    cout<<"30. insert at the tail of circular list"<<endl;
    cout<<"31. insert at the middle of the circular list"<<endl;
    cout<<"32. delete at head of circular list"<<endl;
    cout<<"33. delete at the tail of circular list"<<endl;
    cout<<"34. delete at the middle of circular list"<<endl;




    cout<<endl;
    
    cin>>choice;
    switch(choice){
        case1: cin>>head;
                 break;
        case 2: cout<<"insert the data ";
                int d;
                cin>>d;
                insertathead(head,d);
                break;
        
        case 3: cout<<"insert the data ";
                
                cin>>d;
                insertatend(head,d);
                break;

        case 4: cout<<"insert the data ";
                
                cin>>d;
                cout<<"inser the position ";
                int pos;
                cin>>pos;
                insertatmiddle(head,d,pos);
                break;

        case 5: deleteathead(head);
                break;
                
        case 6: cout<<"enter the position ";
                
                cin>>pos;
                deleteatmiddle(head,pos);
                break;

        case 7: deleteattail(head);
                break;







        case 8: cout<<"enter the data";
                
                cin>>d;
                if(searchdata(head,d))
                cout<<"data found in list";
                else
                cout<<"data not found in list";
                break;

        case 9: cout<<"enter the position";
                
                cin>>pos;
                searchposition(head,pos);
                break;
            
        case 10: cout<<head;
                break;

        case 11: cout<<"the size of the linked list is "<<size(head);
                break;

        case 12: reverselist(head);
                    break;

        case 13: head=recursivereverse(head);
                    cout<<head;
                    break;

        case 14:    {node*middle=middlepoint(head);
                    cout<<middle->data;
                    break;
                    }

        case 15: cout<<"enter the ktih node";
                    int k;
                    cin>>k;
                    cout<<kthnode(head,k);
                    break;

        case 16: cout<<"enter the second list to be merged"<<endl;
                    node*oyo;
                    cin>>oyo;
                    mergesort(head);
                    mergesort(oyo);
                    head=join(head,oyo);
                    cout<<head;
                    break;

        case 17: head=mergesort(head);
                    cout<<head;
                    break;







        case 18:    {
                    cout<<"at what positiion you wnat to start the cycle";
                    int k;
                    cin>>k;
                    makecycle(head,k);
                    break;
                 } 
        
        case 19:    if(detectcycle(head))
                    cout<<"cycle detected";
                    else
                    cout<<"cycle is not present";
                    break;
                
        case 20:    removecycle(head);
                    cout<<endl;
                    if(detectcycle(head))
                    cout<<"cycle is detected";
                    else
                    cout<<"cycle is not present";
                    break;
                    
                    





        case 21:    doubllylist(head);
                    cout<<head;
                    break;

        case 22: cout<<"enter the data to be inserted ";
                    cin>>d;
                    insertatheaddouble(head,d);
                    cout<<head;
                    break;

        case 23: cout<<"enter the dat to be insert at tail ";
                    cin>>d;
                    insertattaildouble(head,d);
                    cout<<head;
                    break;

        case 24: cout<<"at what position you want to enter ?";
                    
                    cin>>pos;
                    cout<<"enter the data";
                    
                    cin>>d;
                    insertatmiddledouble(head,d,pos);
                    cout<<head;
                    break;

        case 25:  deleteatheaddouble(head);
                    cout<<head;
                    break;

        case 26:  deleteattaildouble(head);
                    cout<<head;
                    break;

        case 27:  cout<<"which position you want to delete at ? ";
                    cin>>pos;
                    deleteatmiddledouble(head,pos);
                    cout<<head;
                    break;

        





        case 28:   circularlist(head);
                    printcircular(head);
                    break;

        case 29:  cout<<"enter the data ";
                    cin>>d;
                    insertatheadcircular(head,d);
                    printcircular(head);
                    break;

        case 30:  cout<<"enter the data ";
                    cin>>d;
                    insertattailcircularl(head,d);
                    printcircular(head);
                    break;

        case 31:  cout<<"enter the position at which data will enter "<<endl;
                    cin>>pos;
                    cout<<"enter the data ";
                    cin>>d;
                    insertatmiddlecircular(head,d,pos);
                    printcircular(head);
                    break;


        case 32:  deleteatheadcircular(head);
                    printcircular(head);
                    break;


        case 33:  deleteattailcircular(head);
                    printcircular(head);
                    break;


        case 34:  cout<<"enter the position you want to delete element ";
                    cin>>pos;
                    deleteatmiddlecircular(head,pos);
                    printcircular(head);
                    break;





        default: cout<<"wrong choice entered";
    }

        cout<<endl;
    cout<<"do you want to continue Y/N  ?";
    char newch;
    cin>>newch;
    ch=newch;

    }while(ch=='y');
    

    
   
    
    return 0;
}
