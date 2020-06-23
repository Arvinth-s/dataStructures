//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

struct node{
    node* front, *next;
    int val;
};

void enqueue(node** head, int n);
void dequeue(node** head);
void reverseUtil(node** head);
void reverse(node** head);
inline void swap(node** ptr);
void printList(struct node* head);

int main()
{
    int arr[] = {1, 4, 15, 5 , 3, 6, 15};
    int s=sizeof(arr)/sizeof(arr[0]);
    node* head=NULL;
    for(int i=0; i<s; i++)
    {
        enqueue(&head, arr[i]);
    }
    reverse(&head);
    return 0;
}

void enqueue(node** head, int val)
{
    if(*head==NULL)
    {
        *head=new node;
        (*head)->front=(*head)->next=*head;
        (*head)->val=val;
        return;
    }
    node *Node=new node;
    Node->val=val;
    Node->front=(*head);
    Node->next=(*head)->next;
    (*head)->next=Node;
    (Node->next)->front=Node;
    *head=Node;
    return;
}

void dequeue(node** head)
{
    if(*head==NULL)
    {
        cout<<"The list is already empty.\n";
        return;
    }
    if((*head)->next==*head)
    {
        *head=NULL;
        return;
    }
    ((*head)->next)->front=(*head)->front;
    ((*head)->front)->next=(*head)->next;
    node* temp=(*head);
    *head=(*head)->next;
    free(temp);
    return;
}

void reverse(node** head)
{
    cout<<"Original list: ";
    printList(*head);
    reverseUtil(head);
    cout<<"Reversed list: ";
    printList(*head);
    return;
}

void reverseUtil(node** head)
{
    if(*head==NULL)
    {
        return;
    }
    node *buf=*head;
    swap(&buf);
    buf=buf->front;
    while(buf != *head)
    {
        swap(&buf);
        buf=buf->front;
    }
    return;
}

inline void swap(node** ptr)
{
    node* temp=(*ptr)->next;
    (*ptr)->next=(*ptr)->front;
    (*ptr)->front=temp;
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