//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

#define L 26

long count_words = 0;

struct node
{
    struct node* children[L];
    bool end;
};

struct node* getNode()
{
    count_words++;
    struct node* pNode = new node;
    for(int i = 0; i < L; i++)
        pNode->children[i] = NULL;
    pNode->end = false;
    return pNode;
}

void insert(struct node* root, string key)
{
    struct node* pNode = root;
    for(int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!pNode->children[index])
        {
            pNode->children[index] = getNode();
        }
        pNode = pNode->children[index];
    }
    pNode->end = true;

}

bool search(struct node* root, string key)
{
    struct node* pNode = root;
    for(int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!pNode->children[index])return false;
        pNode = pNode->children[index];
    }
    return true;
}


int main() 
{ 
    long N;cin>>N;
    string str;
    struct node* root = getNode();
    for(int n = 0; n < N; n++)
    {
        cin>>str;
        insert(root, str);
    }
    cout<<count_words;
    return 0; 
} 