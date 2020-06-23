//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
};

void enqueue(struct node **head, int val);
void dequeue(struct node **head);
int removepUtil(struct node** p);
void removep(struct node** p, struct node* head, int n);
void printList(struct node* head);

int main()
{
    node* head=NULL, *p;
    int arr[]={1, 4, 5, 2, 6, 7, 2};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<s; i++)
    {
        enqueue(&head, arr[i]);
    }
    srand(time(0));
    int choice=rand()%s;
    p=head;
    for(int i=0; i<choice+1; i++)
    {
        p=p->next;
    }
    removep(&p, head, choice);
}

void enqueue(struct node **head, int val)
{
    if(*head==NULL)
    {
        (*head)=new node;
        (*head)->val=val;
        (*head)->next=(*head);
        return;
    }
    node *Node=new node;
    Node->next=(*head)->next;
    Node->val=val;
    (*head)->next=Node;
    (*head)=Node;
    return;
}

void dequeue(struct node **head)
{
    if(*head==NULL)
    {
        cout<<"The list is empty(). Can't delete.\n";
        return;
    }
    node* Node=(*head)->next;
    (*head)->next=((*head)->next)->next;
    free(Node);
    return;
}

void removep(struct node** p, struct node* head, int n)
{
    cout<<"p at index: "<<n+1<<" with value "<<(*p)->val<<endl;
    cout<<"before removing: ";
    printList(head);
    removepUtil(p);
    cout<<"after removing:  ";
    printList(head);
    return;
}

int removepUtil(struct node** p)
{
    if((*p)->next==*p)
    {
        *p=NULL;
        return 0;
    }
    node* Node= *p;
    while((*p)->next!=Node)
    {
       (*p)=(*p)->next;
    }
    (*p)->next=((*p)->next)->next;
    return 0;
}

void printList(struct node* head)
{
    if(head==NULL)
    {
        cout<<"no elements in the list.\n";
        return;
    }
    cout<<(head->next)->val<<" ";
    node* ptr=(head->next)->next;
    while(ptr!=head->next)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    return;
}