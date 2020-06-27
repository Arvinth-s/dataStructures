//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define mSize 10
using namespace std;
template <class T>
void Push(T arr[], T info, int &top);
void Pop(int &top);
template<class T>
T Top(T arr[], int top);

int main()
{
    //assuming each operator or operand is exactly one character
    string s;
    getline(cin, s);
    string st[mSize];
    auto itr = mSize;
    itr--;
    int top=-1;
    Push<string>(st, string(1, s[itr]), top);
    itr--;
    itr--;
    Push<string>(st, string(1, s[itr]), top);
    itr--;
    itr--;
    while(itr >= 0)
    {
        if(s[itr] <= 'Z' && s[itr] >= 'A')
        {
            Push<string>(st, string(1, s[itr]), top);
        }
        else
        {
            string b=Top<string>(st, top);
            Pop(top);
            string a=Top<string>(st, top);
            Pop(top);
            string t2(1, s[itr]);
            string temp = b+" "+a+" "+t2;
           Push<string>(st, temp, top);
        }
        itr--;
        itr--;
    }
    string ans=Top<string>(st, top);;
    Pop(top);
    cout<<ans<<endl;
    unordered_map<char, int> umap;
    umap['A']=1;
    umap['B']=2;
    umap['C']=3;
    umap['D']=4;
    //exponent operator is not considered
    int stk[mSize];
    itr = 0;
    top=0;
    Push<int>(stk, umap[stk[itr]], top);
    itr+=2;
    Push<int>(stk, umap[stk[itr]], top);
    itr+=2;
    while(stk[itr] != '\0' && itr < s.size())
    {
        if(s[itr] <= 'Z' && s[itr] >= 'A')
        {
            Push<int>(stk, umap[stk[itr]], top);
        }
        else
        {
            int b=Top<int>(stk, top);
            Pop(top);
            int a=Top<int>(stk, top);
            Pop(top);
            if(s[itr] == '+')
            {
                Push<int>(stk, a+b, top);
            }
            else if(s[itr] == '-')
            {
                Push<int>(stk, a-b, top);
            }
            else if(s[itr] == '*')
            {
                Push<int>(stk, a*b, top);
            }
            else if(s[itr] == '/')
            {
                Push<int>(stk, a/b, top);
            }
            else
            {
                cout<<"only arithmetic operators are allowed.\n";
                exit(0);
            }
        }
        itr += 2;
    }
    cout<<Top<int>(stk, top)<<endl;
    Pop(top);
    assert(top==-1);
    return 0;
}

template <class T>
void Push(T arr[], T val, int &top)
{
    if(top == mSize-1)
    {
        cout<<"The stack is full.\n";
        return;
    }
    top++;
    arr[top]=val;
    return;
}

void Pop(int &top)
{
    if(top==-1)
    {
        cout<<"The stack is already empty.\n";
        return;
    }
    top=top--;
}

template <class T>
T Top(T arr[], int top)
{
    T temp;
    if(top==-1)
    {
        cout<<"The stack is empty.\n";
        return temp;
    }
    return arr[top];
}
