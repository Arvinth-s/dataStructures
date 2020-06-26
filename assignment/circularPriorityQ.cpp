//OM NAMO NARAYANA

/*
TIME COMPLEXITY
1. insertion: O(logn)
2. deletion: O(logn)
3. max: O(logn)
*/

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

inline void details(node *a);
inline void swapLeft(node *a, node *b);
inline void swapRight(node *a, node *b);
void nodeAt(node **buf, node *anc, int s);
void printHeap(node *anc);
void printQ(node *head);
void heapifyPush(node **anc, node *p);
void Push(node **head, node **anc, int val);
inline int Max(node *anc);
void heapifyPop(node **anc, node *p);
void Pop(node **head, node **anc);


int main()
{
    node *head=NULL, *anc=NULL;
    int op=1;
    printf("1.push\n2.pop\n3.Max\n4.Content of queue\n5.Content of heap\n6.operations\n");
    while(op > 0 && op < 7)
    {
        cout<<("option: ");
        cin>>op;
        int val;
        switch(op)
        {
            case 1:cout<<"val: ";cin>>val;Push(&head, &anc, val);break;
            case 2:Pop(&head, &anc);break;
            case 3:cout<<Max(anc)<<endl;break;
            case 4:printQ(head);break;
            case 5:printHeap(anc);break;
            case 6:printf("1.push\n2.pop\n3.Max\n4.Content of queue\n5.Content of heap\n6.operations\n");break;
            default: exit(0);
        }
    }
    //test input. Comment the remaining main
    // int arr[]={13, 123, 51, 12, 1, 13, 52, 1243, 12365, 34, 1245, 12512};
    // int s=sizeof(arr)/sizeof(arr[0]);
    // node *head=NULL, *anc=NULL;
    // node::size=0;
    // for(int i=0; i<s; i++)
    // {
    //     Push(&head, &anc, arr[i]);
    //     printQ(head);
    //     printHeap(anc);
    // }
    // for(int i=0; i<s; i++)
    // {
    //     Pop(&head, &anc);
    //     printQ(head);
    //     printHeap(anc);
    // }
    return 0;
}

//O(logn)
void heapifyPush(node **anc, node *p)
{
    node *ptemp=p->parent;
    while(ptemp != NULL && p->val > ptemp->val)
    {
        //swap left child and parent
        if(ptemp->left == p)
        {
            swapLeft(ptemp, p);
        }
        else
        {
            //swap right child and parent
            swapRight(ptemp, p);
        }
        //p remains same
        //update ptemp
        ptemp=p->parent;
        if(ptemp == NULL){assert((*anc)->parent != NULL); (*anc)=p;break;}
    }
    return;
}

//O(logn)
void Push(node **head, node **anc, int val)
{
    node::size++;
    if(*head==NULL)
    {
        assert(*anc==NULL);
        *head=new node(val);
        (*head)->next=*head;
        *anc=*head;
        return;
    }
    else
    {
        node* Node=new node(val, (*head)->next);
        node *buf;
        //find the parent of the node to be inserted
        nodeAt(&buf, *anc, (node::size)/2);
        //find whether the node shoub be left child or right child
        if(1&(node::size)){buf->right=Node;}
        else {buf->left=Node;}
        Node->parent=buf;
        (*head)->next=Node;
        *head=Node;
        heapifyPush(anc, Node);
        return;
    }
}
//O(logn)
void heapifyPop(node **anc, node *p)
{
    if(node::size==1){*anc=NULL;return;}
    node *buf = NULL;
    nodeAt(&buf, *anc, node::size);
    //p is the last node 
    //p is one of leaf node
    if(buf==p)
    {
        //since buf size > 1
        assert(p->parent);
        if((p->parent)->left==p)(p->parent)->left=NULL;
        else
        {
            assert((p->parent)->right==p);
            (p->parent)->right=NULL;
        }
        free(p);
        return;
    }
    //since buf is a leaf node
    assert(!buf->left && !(buf->right));
    if(buf->parent && ((buf->parent)->left==buf))
    {
        //since buf is last node 
        //if buf is left child there can be no right child
        assert((buf->parent)->right==NULL);
        (buf->parent)->left=NULL;
    }
    else if(buf->parent)
    {
        //since buf is left child there should be a right child
        assert((buf->parent)->left);
        assert((buf->parent)->right==buf);
        (buf->parent)->right=NULL;
    }
    buf->parent=p->parent;
    if(p->left != buf)buf->left=p->left;
    if(buf->left)(buf->left)->parent=buf;
    //to avoid loop
    if(p->right != buf)buf->right=p->right;
    if(buf->right)(buf->right)->parent=buf;
    //top avoid loop
    if(buf->parent && (buf->parent)->left==p)(buf->parent)->left=buf;
    else if(buf->parent)
    {
        //check the edge case when the node to be removed is leaf node
        assert((buf->parent)->right==p);
        (buf->parent)->right=buf;
    }
    while(buf != NULL)
    {
        int lval=INT_MIN/2, rval=INT_MIN/2;
        if(buf->left!=NULL)
        {
            lval=(buf->left)->val;
        }
        if(buf->right!=NULL)
        {
            rval=(buf->right)->val;
        }
        if(lval==rval && lval == INT_MIN/2)break;
        if(max(rval, lval) < buf->val)break;
        if(rval <= lval)
        {
            //since left child is greater
            //parent should be swapped with left child
            swapLeft(buf, buf->left);
            
        }
        else
        {
            //parent to be swapped with right child
            swapRight(buf, buf->right);
        }
        //doubt
        // if(buf->parent)
        // {
        //     assert((buf->parent)->left==buf || (buf->parent)->left==buf);
        // }
        if(buf->right)assert((buf->right)->parent=buf);
        if(buf->left)assert((buf->left)->parent=buf);
    }
    //check whether we are deleting the top node
    assert(buf != NULL);
    if(p==*anc)
    {
        //the common ancestor of all the nodes is the topmost node
        *anc=buf;
        while((*anc)->parent!=NULL)
        {
            *anc=(*anc)->parent;
        }
    }
    free(p);
    return;
}

//O(logn)
void Pop(node **head, node **anc)
{
    if(*head==NULL)
    {
        assert(*anc==NULL);
        cout<<"The queue is already empty.\n";
        node::size=0;
        return;
    }
    if((*head)->next==*head)
    {
        *head=NULL;
        *anc=NULL;
        node::size=1;
        return;
    }
    node *p = (*head)->next;
    (*head)->next=((*head)->next)->next;
    heapifyPop(anc, p);
    node::size--;
    return;
}

//O(1)
//swap left child to parent
inline void swapLeft(node *ptemp, node *p)
{
    node* temp=p->right;
    p->right=ptemp->right;
    ptemp->right=temp;
    if(temp)temp->parent=ptemp;
    if(p->right)(p->right)->parent=p;
    ptemp->left=p->left;
    if(ptemp->left)(ptemp->left)->parent=ptemp;
    p->left=ptemp;
    p->parent=ptemp->parent;
    if(p->parent && (p->parent)->left == ptemp)(p->parent)->left=p;
    else if((p->parent)){assert((p->parent)->right != NULL); (p->parent)->right=p;}
    ptemp->parent=p;
    assert(ptemp->left != ptemp);
    assert(ptemp->right != ptemp);
    assert(ptemp->parent != ptemp);
    assert(p->left != p);
    assert(p->right != p);
    assert(p->parent != p);
}

//O(1)
//swap right child to parent
inline void swapRight(node *ptemp, node *p)
{
    node* temp=p->left;
    p->left=ptemp->left;
    ptemp->left=temp;
    if(temp)temp->parent=ptemp;
    if(p->left)(p->left)->parent=p;
    ptemp->right=p->right;
    if(ptemp->right)(ptemp->right)->parent=ptemp;
    p->right=ptemp;
    p->parent=ptemp->parent;
    if(p->parent && (p->parent)->right == ptemp)(p->parent)->right=p;
    else if((p->parent)){assert((p->parent)->left != NULL); (p->parent)->left=p;}
    ptemp->parent=p;
    assert(ptemp->right != ptemp);
    assert(ptemp->left != ptemp);
    assert(ptemp->parent != ptemp);
    assert(p->right != p);
    assert(p->left != p);
    assert(p->parent != p);
}

//O(logn)
void nodeAt(node **buf, node *anc, int s=node::size)
{
    int h=log2(s);
    int ptr=1<<h;
    ptr=ptr>>1;
    *buf=anc;
    for(int i=0; i < h; i++)
    {
        assert(*buf != NULL);
        if(ptr&s)
        {
            *buf=(*buf)->right;
        }
        else
        {
            *buf=(*buf)->left;
        }
        ptr=ptr>>1;
    }
    return;
}

//O(1)
inline int Max(node *anc)
{
    if(anc==NULL)
    {
        cout<<"The queue is empty.\n";
        return -1;
    }
    return(anc->val);
}


void printQ(node *head)
{
    if(head==NULL)
    {
        cout<<"The queue is empty.\n";
        return;
    }
    printf("queue:\n");
    node* ref= head;
    cout<<head->val<<" ";
    head=head->next;
    while(head != ref)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}

void printHeap(node *top)
{
    if(top==NULL)
    {
        cout<<"The heap is empty.\n";
        return;
    }
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

//for debugging purpose
inline void details(node *a)
{
    if(a==NULL)return;
    cout<<"a: "<<a->val<<endl;
    node* p=a->parent;
    if(!p)cout<<"a: parent doesn't exist.\n";
    else cout<<"parent: "<<p->val<<endl;
    if(p != NULL && p->left)cout<<"a->parent->left: "<<(p->left)->val<<endl;
    else if(p) cout<<"a: parent left child doesn't exist.\n";
    if(p != NULL && p->right)cout<<"a->parent->left: "<<(p->right)->val<<endl;
    else if(p)cout<<"a: parent right child doesn't exist.\n";
    node *l=a->left, *r=a->right;
    if(l!= NULL )cout<<"a->left: "<<l->val<<endl;
    if(r!= NULL )cout<<"a->right: "<<r->val<<endl;
    return;
}