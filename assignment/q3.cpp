//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

struct node{
    node* front, *next;
    int val;
};

void enqueue(node** head, int n);
void dequeue(node** head);
void insertAfterheadUtil(node** head, int n);
void insertBeforeheadUtil(node** head, int n);
void insertafterpUtil(node** head, node* p, int n);
void deletepUtil(node** head, node*p);
void deleteBeforeheadUtil(node** head);
void deleteAfterheadUtil(node** head);
void reverseUtil(node** head);
void insertAfterhead(node** head, int n);
void insertBeforehead(node** head, int n);
void insertafterp(node** head, node* p, int n);
void deletep(node** head, node*p);
void deleteBeforehead(node** head);
void deleteAfterhead(node** head);
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
    insertAfterhead(&head, 16);
    insertBeforehead(&head, 17);
    insertafterp(&head, head->next, 18);
    deletep(&head, head->next);
    deleteBeforehead(&head);
    insertAfterhead(&head, 20);
    deleteBeforehead(&head);
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
    node* temp=(*head)->front;
    (*head)->front=((*head)->front)->front;
    ((*head)->front)->next=*head;
    free(temp);
    return;
}

void deleteAfterhead(node** head)
{
    cout<<"before deleteAfterhead:";
    printList(*head);
    deleteAfterheadUtil(head);
    cout<<"after deleteAfterhead: ";
    printList(*head);
}

void deleteAfterheadUtil(node** head)
{
    if(head==NULL)
    {
        cout<<"Already empty. Can't delete.\n";
        return;
    }
    node* p=((*head)->next)->next;
    dequeue(&p);
}

void deleteBeforehead(node** head)
{
    cout<<"before deleteBeforehead:";
    printList(*head);
    deleteAfterheadUtil(head);
    cout<<"after deleteBeforehead: ";
    printList(*head);
}

void deleteBeforeheadUtil(node** head)
{
    if(head==NULL)
    {
        cout<<"Already empty. Can't delete.\n";
        return;
    }
    node*p =*head;
    dequeue(&p);
}

void insertAfterhead(node** head, int n)
{
    cout<<"inserting "<<n<<" after head.\n";
    cout<<"before inserting: \t";
    printList(*head);
    insertAfterheadUtil(head, n);
    cout<<"after inserting: \t";
    printList(*head);
}

void insertAfterheadUtil(node** head, int n)
{
    enqueue(head, n);
    *head=(*head)->front;
    return;
}

void insertBeforehead(node** head, int n)
{
    cout<<"inserting "<<n<<" before head.\n";
    cout<<"before inserting: \t";
    printList(*head);
    insertBeforeheadUtil(head, n);
    cout<<"after inserting: \t";
    printList(*head);
}

void insertBeforeheadUtil(node** head, int n)
{
    if(*head==NULL)
    {
        cout<<"The list is empty. Can't insert.\n";
        return;
    }
    *head=(*head)->front;
    enqueue(head, n);
    *head=(*head)->next;
    return;
}

void reverse(node** head)
{
    cout<<"Original list: \t\t";
    printList(*head);
    reverseUtil(head);
    cout<<"Reversed list: \t\t";
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

void insertafterp(node** head, node*p, int n)
{
    if(p==NULL)
    {
        cout<<"p is NULL.\n";
        return;
    }
    cout<<"inserting "<<n<<" after "<<p->val<<endl;
    cout<<"before inserting: \t";
    printList(*head);
    insertafterpUtil(head, p, n);
    cout<<"after inserting: \t";
    printList(*head);
    return;
}

void insertafterpUtil(node** head, node* p, int n)
{
    if(*head==NULL)
    {
        if(*head==NULL)
        {
            enqueue(head, n);
        }
        else
        {
            cout<<"p not found.\n";
        }
        return;
    }
    if(*head==p)
    {
        enqueue(head, n);
        return;
    }
    node* temp=(*head)->next;
    while(temp!=*head)
    {
        if(temp==p)
        {
            enqueue(&p, n);
            p=p->front;
            return;
        }
        temp=temp->next;
    }
    cout<<"p not found.\n";
    return;
}

void deletep(node** head, node* p)
{
    if(p==NULL)
    {
        cout<<"p is empty.\n";
        return;
    }
    cout<<"deleting "<<p->val<<endl;
    cout<<"before deleting: \t";
    printList(*head);
    deletepUtil(head, p);
    cout<<"after deleting: \t";
    printList(*head);
    return;
}

void deletepUtil(node** head, node* p)
{
    if(*head==NULL)
    {
        cout<<"list is already empty.\n";
        return;
    }
    if(*head==p)
    {
        *head=(*head)->next;
        dequeue(head);
        return;
    }
    node* temp=(*head)->next;
    while(temp!=*head)
    {
        if(temp==p)
        {
            temp=temp->next;
            dequeue(&temp);
            return;
        }
    }
    cout<<"p not found.\n";
    return;
}