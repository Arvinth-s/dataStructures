//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define mSize 10
using namespace std;
template <class T>
void Push(T arr[], T info, int &top);
template<class T>
void Pop(T arr[], int &top);
template<class T>
T Top(T arr[], int top);

int main()
{
    //assuming each operator or operand is exactly one character
    string s;
    getline(cin, s);
    stack<string> st;
    auto itr = s.end();
    itr--;
    st.push(string(1, *itr));
    itr--;
    itr--;
    st.push(string(1, *itr));
    itr--;
    itr--;
    while(itr != s.begin())
    {
        if(*itr <= 'Z' && *itr >= 'A')
        {
            string t(1, *itr);
            st.push(t);
        }
        else
        {
            string a=st.top();
            st.pop();
            string b=st.top();
            st.pop();
            string t(1, *itr);
            string temp = a+" "+b+" "+t;
            st.push(temp);
        }
        itr--;
        itr--;
    }
    if(*itr <= 'Z' && *itr >= 'A')
    {
        string t(1, *itr);
        st.push(t);
    }
    else
    {
        string a=st.top();
        st.pop();
        string b=st.top();
        st.pop();
        string t(1, *itr);
        string temp = a+" "+b+" "+t;
        st.push(temp);
    }
    string ans=st.top();
    st.pop();
    cout<<ans<<endl;
    unordered_map<char, int> umap;
    umap['A']=1;
    umap['B']=2;
    umap['C']=3;
    umap['D']=4;
    //exponent operator is not considered
    stack<int> stk;
    itr = ans.begin();
    stk.push(umap[*itr]);
    itr+=2;
    stk.push(umap[*itr]);
    itr+=2;
    while(*itr != '\0')
    {
        if(*itr <= 'Z' && *itr >= 'A')
        {
            stk.push(umap[*itr]);
        }
        else
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            if(*itr == '+')
            {
                stk.push(a+b);
            }
            else if(*itr == '-')
            {
                stk.push(a-b);
            }
            else if(*itr == '*')
            {
                stk.push(a*b);
            }
            else if(*itr == '/')
            {
                stk.push(a/b);
            }
            else
            {
                cout<<"only arithmetic operators are allowed.\n";
                exit(0);
            }
        }
        itr += 2;
    }
    cout<<stk.top()<<endl;
    stk.pop();
    assert(stk.empty());
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