//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define maxSize 10
using namespace std;

char reff[]={"hi"};

struct node{
    protected:
    char *val;
    public:
    node* next;
    node(char *val){this->val=val;}
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
    inode(int val):node(reff){this->val=val;}
    void print()
    {
        cout<<val<<endl;
    }
};

bool checkNum(char *c);

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
            char *c = new char[20];
            cin.getline(c, maxSize);
            cin.getline(c, maxSize);
            bool isInt=checkNum(c);
            if(isInt)
            {
                int it;
                sscanf(c, "%d", &it);
                inode* Node=new inode(it); 
                push(Node);
            }
            else
            {
                node* Node=new node(c);
                push(Node);
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

bool checkNum(char *c)
{
    int i=0;
    while(c[i] !='\0')
    {
        if(c[i] < '0' || c[i++] > '9')
            return false;
    }
    return true;
}