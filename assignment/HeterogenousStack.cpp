//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define maxSize 10
using namespace std;

struct node{
    protected:
    char val;
    public:
    node* next;
    node(char val){this->val=val;}
    virtual void print()
    {
        cout<<val<<endl;
    }
};

struct inode:node{
    private:
    int val;
    public:
    node* next;
    inode(int val):node('o'){this->val=val;}
    void print()
    {
        cout<<val<<endl;
    }
};

node *top=NULL;
int size=0;

void push(node* ele)
{
    if(size==maxSize)
    {
        cout<<"stack full. Cannot push.\n";
        return;
    }
    ele->next=top;
    top=ele;
    size++;
    return;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"can't pop. Stack is empty.\n";
        return;
    }
    size--;
    node* temp=top;
    top=top->next;
    free(temp);
    return;
}

int main()
{
    while(1)
    {
        
        cout<<"1.push\n2.pop\n3.top\n";
        int op;
        cin>>op;
        if(op==1)
        {
            int ch;
            cout<<"1.integer\n2.char\n";
            cin>>ch;
            if(ch==1)
            {
                cout<<"enter int: ";
                int ele;
                cin>>ele;
                inode* Node=new inode(ele); 
                push(Node);
            }
            if(ch==2)
            {
                cout<<"enter char: ";
                char ele;
                cin>>ele;
                node* Node=new node(ele);
                push(Node);
            }
            if(ch<1||ch>2)
            {
                exit(0);
            }
        }
        if(op==2)
        {
            pop();
        }
        if(op==3)
        {
            if(top==NULL)
            {
                cout<<"Stack is empty.\n";
                continue;
            }
            top->print();
        }
        if(op<1 || op>3)
        {
            exit(0);
        }
    }
    return 0;
}