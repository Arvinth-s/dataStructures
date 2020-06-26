//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    static int size;
    node *next;
    node *left, *right, *parent;
    node(int val, node *next=NULL){this->val=val;this->next=next;left=right=parent=NULL;}
};

int node::size=0;

void swapLeft(node *a, node *b);
void swapRight(node *a, node *b);
void nodeAt(node **buf);
void printHeap(node *anc);
void printList(node *head);
void heapifyInsert(node **anc, node *p);
void insert(node **head, node **anc, int val);
inline int Max(node *anc);
void heapifyPop(node **anc, node *p);
void Pop(node **head, node **anc);


int main()
{
    int arr[]={13, 123, 51, 12, 1, 13, 52};
    int s=sizeof(arr)/sizeof(arr[0]);
    node *head=NULL, *anc=NULL;
    node::size=0;
    for(int i=0; i<s; i++)
    {
        insert(&head, &anc, arr[i]);
        printList(head);
        printHeap(anc);
    }
    return 0;
}

void heapifyInsert(node **anc, node *p)
{
    node *ptemp=p->parent;
    while(ptemp != NULL && p->val > ptemp->val)
    {
        if(ptemp->left == p)
        {
            // node* temp=ptemp->right;
            // ptemp->right=p->right;
            // p->right=temp;
            // //p->right; ptemp->right
            // ptemp->left=p->left;
            // p->left=ptemp;
            // assert(p->left != p);
            // //ptemp->left; p->left
            // p->parent=ptemp->parent;
            // //p parent; ptemp->parent;
            // if(ptemp->parent!=NULL && (ptemp->parent)->left==ptemp)
            // {
            //     (ptemp->parent)->left=p;
            // }
            // else if(ptemp->parent!=NULL)
            // {
            //     assert((ptemp->parent)->right=ptemp);
            //     (ptemp->parent)->right=p;
            // }
            // ptemp->parent=p;
            // //parent of ptemp
            // if(ptemp->left != NULL)(ptemp->left)->parent=ptemp;
            // if(ptemp->right!= NULL)(ptemp->right)->parent=ptemp;
            // //children of p
            // assert(ptemp->left != ptemp);
            // assert(ptemp->right != ptemp);
            // assert(ptemp->parent != ptemp);
            // assert(p->left != p);
            // assert(p->right != p);
            // assert(p->parent != p);
            swapLeft(ptemp, p);
        }
        else
        {
            // node* temp=ptemp->left;
            // ptemp->left=p->left;
            // p->left=temp;
            // //p->left; ptemp->left
            // ptemp->right=p->right;
            // p->right=ptemp;
            // //ptemp->right; p->right
            // p->parent=ptemp->parent;
            // //p parent; ptemp->parent;
            // if(ptemp->parent!=NULL && (ptemp->parent)->left==ptemp)
            // {
            //     (ptemp->parent)->left=p;
            // }
            // else if(ptemp->parent!=NULL)
            // {
            //     assert((ptemp->parent)->right=ptemp);
            //     (ptemp->parent)->right=p;
            // }
            // ptemp->parent=p;
            // //parent of ptemp
            // if(ptemp->left != NULL)(ptemp->left)->parent=ptemp;
            // if(ptemp->right!= NULL)(ptemp->right)->parent=ptemp;
            // //children of p
            swapRight(ptemp, p);
        }
        ptemp=p->parent;
        if(ptemp == NULL){assert((*anc)->parent != NULL); (*anc)=p; return;}
    }
    return;
}

void insert(node **head, node **anc, int val)
{
    node::size++;
    if(*head==NULL)
    {
        assert(*anc==NULL);
        *head=new node(val);
        *anc=*head;
        return;
    }
    else
    {
        node* Node=new node(val);
        int s=node::size, h=log2(node::size);
        int ptr=1<<h;
        ptr=ptr>>1;
        node *buf=*anc;
        for(int i=0; i < h-1; i++)
        {
            assert(buf != NULL);
            if(ptr&s)
            {
                buf=buf->right;
            }
            else
            {
                buf=buf->left;
            }
            ptr=ptr>>1;
        }
        if(ptr&s){buf->right=Node;}
        else {buf->left=Node;}
        Node->parent=buf;
        node* temp=*head;
        while(temp->next != NULL)temp=temp->next;
        temp->next=Node;
        heapifyInsert(anc, Node);
        return;
    }
}

void heapifyPop(node **anc, node *p)
{
    if(node::size==1){*anc=NULL;return;}
    int s=node::size, h=log2(node::size);
    int ptr=1<<h;
    ptr=ptr>>1;
    node *buf=*anc;
    for(int i=0; i < h; i++)
    {
        assert(buf != NULL);
        if(ptr&s)
        {
            buf=buf->right;
        }
        else
        {
            buf=buf->left;
        }
        ptr=ptr>>1;
    }
    assert(buf->left==NULL && buf->right==NULL);
    if(buf->parent != NULL && (buf->parent)->left==buf)
    {
        assert((buf->parent)->right==NULL);
        (buf->parent)->left=NULL;
    }
    else
    {
        assert((buf->parent)->left != NULL && (buf->parent)->right==buf);
        (buf->parent)->right=NULL;
    }
    buf->parent=p->parent;
    buf->left=p->left;
    buf->right=p->right;
    if(buf->parent != NULL && (buf->parent)->left==p)(buf->parent)->left=buf;
    else if(buf->parent != NULL)
    {
        assert((buf->parent)->right==p);
        (buf->parent)->right=buf;
    }
    int lval=INT_MIN/2, rval=INT_MIN/2;
    if(buf->left!=NULL)
    {
        lval=(buf->left)->val;
    }
    if(buf->right!=NULL)
    {
        rval=(buf->right)->val;
    }
    if(lval==rval && lval == INT_MIN/2)return;
    // if(lval < rval)
    // {
    //     buf
    // }
}

inline int Max(node *anc)
{
    if(anc==NULL)
    {
        cout<<"The queue is empty.\n";
        return -1;
    }
    return(anc->val);
}

void printHeap(node *top)
{
    printf("heap:\n");
    if(top==NULL)return;
    queue<node *> q;
    q.push(top);
    while(!q.empty())
    {
        node *ele=q.front();
        cout<<ele->val<<" ";
        q.pop();
        if(ele->left != NULL)q.push(ele->left);
        if(ele->right!= NULL)q.push(ele->right);
    }
    cout<<endl;
    return;
}

void printList(node *head)
{
    printf("queue:\n");
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}

void swapLeft(node *ptemp, node *p)
{
    node* temp=ptemp->right;
    ptemp->right=p->right;
    p->right=temp;
    //p->right; ptemp->right
    ptemp->left=p->left;
    p->left=ptemp;
    assert(p->left != p);
    //ptemp->left; p->left
    p->parent=ptemp->parent;
    //p parent; ptemp->parent;
    if(ptemp->parent!=NULL && (ptemp->parent)->left==ptemp)
    {
        (ptemp->parent)->left=p;
    }
    else if(ptemp->parent!=NULL)
    {
        assert((ptemp->parent)->right=ptemp);
        (ptemp->parent)->right=p;
    }
    ptemp->parent=p;
    //parent of ptemp
    if(ptemp->left != NULL)(ptemp->left)->parent=ptemp;
    if(ptemp->right!= NULL)(ptemp->right)->parent=ptemp;
    //children of p
    assert(ptemp->left != ptemp);
    assert(ptemp->right != ptemp);
    assert(ptemp->parent != ptemp);
    assert(p->left != p);
    assert(p->right != p);
    assert(p->parent != p);
}

void swapRight(node *ptemp, node *p)
{
    node* temp=ptemp->left;
    ptemp->left=p->left;
    p->left=temp;
    //p->left; ptemp->left
    ptemp->right=p->right;
    p->right=ptemp;
    //ptemp->right; p->right
    p->parent=ptemp->parent;
    //p parent; ptemp->parent;
    if(ptemp->parent!=NULL && (ptemp->parent)->left==ptemp)
    {
        (ptemp->parent)->left=p;
    }
    else if(ptemp->parent!=NULL)
    {
        assert((ptemp->parent)->right=ptemp);
        (ptemp->parent)->right=p;
    }
    ptemp->parent=p;
    //parent of ptemp
    if(ptemp->left != NULL)(ptemp->left)->parent=ptemp;
    if(ptemp->right!= NULL)(ptemp->right)->parent=ptemp;
    //children of p
}