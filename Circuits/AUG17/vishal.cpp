#include<bits/stdc++.h>
using namespace std;
int main()
{
        int t=1;
        //cin>>t;
        while(t--)
        {
                string s;
                cin>>s;
                int i,n=s.size(),k;
                cin>>k;
                set<char> myset;
                for(i=0;i<n;i++)
                {
                        myset.insert(s[i]);
                }
                int l=myset.size();
                int rem=26-l;
                if(k>26 || k>n )        cout<<"impossible\n";
                else
                {
                        if((k-l)>26)    cout<<"impossible\n";
                        cout<<k-l<<endl;
                }
        }

}
