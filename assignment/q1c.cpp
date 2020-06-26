//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

//O(n) solution

struct node{
    string s;
    node* next;
    node(string s, node *next=NULL){this->s=s;this->next=next;}
};

bool check(string s1, string s2);
bool palan(node **a, node *b);
void insert(node **head, string s);
bool checkPalan(node *head);

int main()
{
    node *head=NULL;
    insert(&head, "life");
    insert(&head, "is");
    insert(&head, "an");
    insert(&head, "opportunity");
    insert(&head, "opportunity1");
    insert(&head, "opportunity");
    insert(&head, "an");
    insert(&head, "is");
    insert(&head, "life");
    if(checkPalan(head))cout<<"Palandrome.\n";
    else cout<<"Not a palandrome.\n";
    return 0;
}

void insert(node **head, string s)
{
    if(*head==NULL)
    {
        *head=new node(s);
        return;
    }
    node *Node=new node(s, *head);
    *head=Node;
    return;
}

bool checkPalan(node *head)
{
    if(head==NULL)
    {
        cout<<"The list is empty.\n";
        return true;
    }
    if(head->next==NULL)
    {
        return true;
    }
    node *slow=head, *fast=head;
    while(fast->next != NULL && (fast->next)->next != NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
    }
    return palan(&head, slow);
}

bool palan(node **left, node *right)
{
    if(right->next==NULL)
    {
        return(check(right->s, (*left)->s));
    }
    else
    {
        if(palan(left, right->next))
        {
            *left=(*left)->next;
            return(check(right->s, (*left)->s));
        }
        else return false;
    }
}

inline bool check(string s1, string s2)
{
    // reverse(s1.begin(), s1.end());
    cout<<s1<<" "<<s2<<endl;
    bool ans=(s1==s2);
    // reverse(s1.begin(), s1.end());
    return ans;
}