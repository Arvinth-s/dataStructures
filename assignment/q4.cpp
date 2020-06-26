//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

//taking value as priority
struct node{
    int val;
    node *front, *next;
};

void print(node *head);
void append(node** head, int n);
void pop(node** head);
void swap(node**head, node *a, node* b);
void swapkUtil(node **head, int k, int n);
void swapk(node** head, int k);
void sortUtil(node **head);
void sort(node **head);

int main()
{
    int arr[]={1, 12, 13, 2, 6, 3, 4, 5, 6};
    int s=sizeof(arr)/sizeof(arr[0]);
    node *head=NULL;
    for(int i=0; i<s; i++)
    {
        append(&head, arr[i]);
    }
    srand(time(0));
    int choice=rand()%(s/2);
    swapk(&head, choice);
    sort(&head);
    return 0;
}

void append(node **head, int val)
{
    if(*head==NULL)
    {
        *head=new node;
        (*head)->val=val;
        (*head)->next=(*head)->front=NULL;
        return;
    }
    node* Node=new node;
    (*head)->next=Node;
    Node->val=val;
    Node->front=*head;
    Node->next=NULL;
    *head=Node;
    return;
}

void pop(node **head)
{
    if(*head==NULL)
    {
        cout<<"List is already empty.\n";
        return;
    }
    node* temp=*head;
    ((*head)->front)->next=NULL;
    *head=(*head)->front;
    free(temp);
    return;
}

void swapk(node **head, int k)
{
    int n=0;
    node* ptr=*head;
    while(ptr != NULL)
    {
        n++;
        ptr=ptr->front;
    }
    if(n==0)
    {
        cout<<"The list is empty.\n";
        return;
    }
    if(n < k)
    {
        cout<<"The size of list is less than k. Can't swap.\n";
        return;
    }
    if(k==0)
    {
        k=1;
    }
    cout<<"swapping "<<k<<"th element with " << n-k <<"th element.\n";
    cout<<"before swapping:";
    print(*head);
    swapkUtil(head, k, n);
    cout<<"after swapping: ";
    print(*head);
    return;
}

void swapkUtil(node **head, int k, int n)
{
    node* iptr=*head, *jptr=*head;
    for(int i=0; i<k-1; i++)
    {
        jptr=jptr->front;
    }
    for(int i=0; i<n-k; i++)
    {
        iptr=iptr->front;
    }
    if(k==1)
    {
        assert(iptr->front==NULL && jptr->next==NULL);
        iptr->front=jptr->front;
        jptr->next=iptr->next;
        iptr->next=NULL;
        jptr->front=NULL;
        if((jptr)->next != NULL){((jptr)->next)->front=(jptr);}
        if((iptr)->next != NULL){((iptr)->next)->front=(iptr);}
        if((jptr)->front != NULL){((jptr)->front)->next=(jptr);}
        if((iptr)->front != NULL){((iptr)->front)->next=(iptr);}
        (*head)=iptr;
        return;
    }
    swap(head, iptr, jptr);
    return;
}

void swap(node** head, node *iptr, node *jptr)
{
    if((iptr)->next==jptr)
    {
        node* temp=iptr;
        iptr=jptr;
        jptr=temp;
    }
    if((iptr)->front==(jptr))
    {
        node* temp= (iptr)->next;
        (iptr)->next=jptr;
        (jptr)->next=temp;
        temp=(jptr)->front;
        (jptr)->front=iptr;
        (iptr)->front=temp;
    }
    else
    {
        node* temp;
        temp=(iptr)->next;
        (iptr)->next=(jptr)->next;
        (jptr)->next=temp;
        temp=(iptr)->front;
        (iptr)->front=(jptr)->front;
        (jptr)->front=temp;
    }
    if((jptr)->next != NULL){((jptr)->next)->front=(jptr);}
    if((iptr)->next != NULL){((iptr)->next)->front=(iptr);}
    if((jptr)->front != NULL){((jptr)->front)->next=(jptr);}
    if((iptr)->front != NULL){((iptr)->front)->next=(iptr);}
    return;
}

void print(node* head)
{
    node* ptr= head;
    while(ptr->front!=NULL)
    {
        ptr=ptr->front;
    }
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    return;
}

void sort(node **head)
{
    if(*head==NULL)
    {
        cout<<"List is empty.\n";
        return;
    }
    cout<<"before sort: \t";
    print(*head);
    sortUtil(head);
    cout<<"after sort: \t";
    print(*head);    
}

void sortUtil(node **head)
{
    // cout<<"sortingUtil\n";
    bool sorted=false;
    // print(*head);
    while(!sorted)
    {
        sorted=true;
        node* ptr=*head;
        while(ptr->front != NULL)
        {
            if(ptr->val > (ptr->front)->val)
            {
                // printf("before swaping ptr->val: %d ptr->front->val: %d ptr->next->val: %d\n", ptr->val, (ptr->front!=NULL)?(ptr->front)->val:-1, (ptr->next!= NULL)?(ptr->next)->val:-1);
                sorted=false;
                swap(head, ptr, (ptr->front));
                // printf("After swaping ptr->val: %d ptr->front->val: %d ptr->next->val: %d\n", ptr->val, (ptr->front!=NULL)?(ptr->front)->val:-1, (ptr->next!= NULL)?(ptr->next)->val:-1);
            }
            else
            {
                ptr=ptr->front;
            }
            // cout<<"ptr: "<<ptr->val<<endl;
            assert(ptr->val >= (ptr->next)->val);
            // print(*head);
        }
        // print(*head);
    }
    return;
}