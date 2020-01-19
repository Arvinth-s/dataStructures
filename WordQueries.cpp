//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

#define L 26

struct node{
    struct node* children[L];
    bool end;
    long count;
};

struct node* getNode()
{
    struct node* pNode = new node;
    for(int i = 0; i < L; i++)pNode->children[i] = NULL;
    pNode->end = false;
    pNode->count = 0;
    return pNode;
}

void insert(struct node* root, string key)
{
    struct node* pNode = root;
    for(int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!pNode->children[index])pNode->children[index] = getNode();
        pNode->count++;
        pNode = pNode->children[index];
        pNode->end = false;
    }
    pNode->count++;
    pNode->end = true;
    return;
}

long count_prefix(struct node* root, string pre)
{
    struct node* pNode = root;
    for(int i = 0; i < pre.size();i++)
    {
        int index = pre[i] - 'a';
        if(!pNode->children[index])return 0;
        pNode = pNode->children[index];
    }
    return pNode->count;
    return 0;
}

int main()
{
    long N, Q;cin>>N>>Q;
    struct node*root = getNode();
    string str;
    for(long n = 0; n < N; n++){cin>>str;insert(root, str);}
    for(long q = 0; q < Q; q++){cin>>str;cout<<count_prefix(root, str)<<'\n';}
    return 0;
}
