#include<bits/stdc++.h>
using namespace std;

#define NBIT 30

struct node{
    struct node *children[30];
    bool isEnd;
};

struct node *getNode()
{
    struct node  *pNode = new node;
    pNode->isEnd = false;
    for(int i = 0; i < NBIT; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct node *root, int key)
{
    struct node *pCrawl = root;
    for(int i = 0; i < NBIT; i++)
    {
        int index = key;
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        
    }
}

int main()
{
    // cout<<log2(1000000000);
    // uses 30 bit
    long Q;cin>>Q;
    vector<long> x;
    x.push_back(0);
    for(long q = 0; q < Q; q++)
    {

    }
    return 0;
}