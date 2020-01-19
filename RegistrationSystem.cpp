//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

#define L 36

struct node{
    struct node* children[L];
};

struct node* getNode()
{
    struct node* pNode = new node;
    for(int i = 0; i < L; i++)
        pNode->children[i] = NULL;
    return pNode;
}

string insert(struct node* root, string key)
{
    struct node* pNode = root;
    bool flag = false;
    for(int i = 0; i < key.size(); i++)
    {
        int index = 0;
        if(key[i] - '0' <= 9)index = key[i] - '0';
        else index = key[i] - 'a' + 10;
        if(!pNode->children[index]){flag = true; pNode->children[index] = getNode();}
        pNode = pNode->children[index];
    }
    string ret;
    if(!flag)
    {
        if(key[key.size()-1] - '0' < 9){char temp = key[key.size()-1] + 1; key.pop_back();ret = key + temp;return ret;}
        else if(key[key.size() -1 ] - '0' == 9){key.pop_back();key += "10";return key;}
        else {key += "0";return key;}
    }
    else
        return key;
}

int main()
{
    long N;cin>>N;
    string str;
    struct node* root = getNode();
    for(long n = 0; n < N; n++)
    {
        cin>>str;
        cout<<insert(root, str)<<'\n';
    }
    return 0;
}
