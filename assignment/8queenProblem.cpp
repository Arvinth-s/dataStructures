//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int nQueenProblem(int n)
{
    vector<int> row;
    row.pb(0);
    vector<vector<int> > all;
    while(row.size() <= n && !row.empty())
    {
        bool change=true;
        while(row.back() < n && change)
        {
            int l=row.size();
            int ele=row[l-1], i;
            for(i=0; i< l-1; i++)
            {
                if(row[i]==ele|| (abs(row[i]-ele)==abs(l-i-1)))
                {
                    row.back()++;
                    break;
                }
            }   
            if(i==l-1)change=false;
        }
        if(row.back()==n)
        {
            row.pop_back();
            row.back()+=1;
        }
        else
        {
            row.pb(0);
        }
        if(row.size()>n)
        {
            row.pop_back();
            all.pb(row);
            row.back()++;
            if(row.back()==n)
            {
                row.pop_back();
                row.back()++;
            }
        }
    }
    // row.clear();
    int temp=0;
    int s=all.size();
    for(int k=0; k<0; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j==all[k][i])
                {
                    cout<<".";
                }
                else
                {
                    cout<<"*";
                }
            }
            cout<<endl;
        }
        cout<<"--------\n";
    }
    // int temp;
    // // all.clear();
    // row.pb(0);
    // all.pb(row);
    return s;
}
int main()
{
    int n;
    // cin>>n;
    for(n=4; n<20; n++)
    {
        int ans=nQueenProblem(n);
        cout<<n<<":"<<ans<<endl;
    }
    return 0;
}