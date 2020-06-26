//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define MAX 1e9//maximum value of input
#define L 9//number of digits
#define Msize 20//size of string
using namespace std;

struct node{
    int val;
    node* next;
};
struct trie{
    int val;
    trie* children[10];
};

struct llist{
    char* str;
    llist* next;
};

trie* createTrie(void);
void insertTrie(struct trie** root, int n);
bool checkTrie(struct trie** root, int n);
void insert(struct node** head, int val);
void removeDuplicateUtil(struct node** head);
void removeDuplicate(struct node** head);
void printList(struct node* head);
void splitUtil(struct node* head, struct node** front, struct node** back);
void split(struct node* head, struct node** front, struct node** back);
void insertString(struct llist**head, char* str);


int main()
{
    node* head= NULL, *front = NULL, *back = NULL;
    int arr[]={1, 4, 2, 7, 2, 1, 3, 100, 134, 1542, 100};
    int l=sizeof(arr)/sizeof(arr[0]);
    for(int i=l-1; i>=0; i--)
    {
        insert(&head, arr[i]);
        if(head==NULL);
    }
    removeDuplicate(&head);
    split(head, &front, &back);
    insert(&head, 5);
    split(head, &front, &back);
    return 0;
}

void insert(node** head, int val)
{
    if(val >= MAX)
    {
        return;
    }
    node* Node=new node;
    Node->val=val;
    Node->next=*head;
    *head=Node;
}

void removeDuplicate(struct node** head)
{
    cout<<"original list: \t\t\t";
    printList(*head);
    removeDuplicateUtil(head);
    cout<<"after removing duplicates: \t";
    printList(*head);
}

void removeDuplicateUtil(struct node** head)
{
    if(*head==NULL)return;
    node* Node=new node;
    node* ptr=*head;
    trie* root=createTrie();
    insertTrie(&root, ptr->val);
    while((ptr->next)!=NULL)
    {
        if(checkTrie(&root, (ptr->next)->val))
        {
            ptr->next=(ptr->next)->next;
            if(ptr->next==NULL)break;
        }
        else
        {
            insertTrie(&root, (ptr->next)->val);
            ptr=ptr->next;
        }
    }
}

void printList(struct node* head)
{
    node* ptr=head;
    if(head==NULL)
    {
        cout<<"no elements in the list.\n";
        return;
    }
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    return;
}

trie* createTrie(void)
{
    trie* t= new  trie;
    t->val=-1;
    for(int i=0; i<10; i++)
    {
        t->children[i]=NULL;
    }
    return t;
}

void insertTrie(trie** root, int n)
{
    trie* itr=*root;
    assert(*root != NULL);
    int val=0;
    for(int i=0; i<L; i++)
    {
        int idx=n%10;
        n/=10;
        val*=10;
        val+=idx;
        assert(idx<10);
        if(itr->children[idx]==NULL)
        {
            itr->children[idx]=createTrie();
            (itr->children[idx])->val=val;
        }
        itr=itr->children[idx];
    }
    return;
}

bool checkTrie(trie** root, int n)
{
    trie* itr=*root;
    for(int i=0; i<L; i++)
    {
        int idx=n%10;
        n/=10;
        if(itr->children[idx]==NULL)
        {
            return false;
        }
        itr=itr->children[idx];
    }
    return true;
}

void split(node* head, node** front, node** back)
{
    cout<<"before spliting:\t\t";
    printList(head);
    cout<<"after spliting:\n";
    splitUtil(head, front, back);
    cout<<"front:\t\t\t\t";
    printList(*front);
    cout<<"back:\t\t\t\t";
    printList(*back);
}

void splitUtil(node* head, node** front, node** back)
{
    node* ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    *front=head;
    for(int i=0; i<(count-1)/2; i++)
    {
        ptr=ptr->next;
    }
    *back=ptr->next;
    ptr->next=NULL;
    return;
}
