#include<bits/stdc++.h>
using namespace std;
vector < int > v;
void LPSArray(string pat,int *lps)
{
    lps[0] = 0; 
    int len=0,i = 1;
    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0)	 len = lps[len-1];
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string pat, string txt)
{
    int lps[pat.size()];
    LPSArray(pat,lps);
    
    int i = 0,j=0;  
    while (i < txt.size())
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == pat.size())
        {
            v.push_back(i-j);
            j = lps[j-1];
        }
        
        else if (i < txt.size() && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
int main()
{
    string txt,pat1,pat2; 
    cin>>pat1>>pat2>>txt;
    
	v.clear();
    int l1,l2,i,j,k;
    KMPSearch(pat1, txt);
	int P1[v.size()];
	for(l1=0;l1<v.size();l1++)	P1[l1]=v[l1];
    v.clear();
    KMPSearch(pat2, txt);
	int P2[v.size()];
	for(l2=0;l2<v.size();l2++)	P2[l2]=v[l2];
	
	i=j=0;
	int ans = 0,t1,t2;
	for(k=0;k<txt.size() && i<l1 && j<l2 ;k++)
	{
		t1 = P1[i] + pat1.size() -1;
		t2 = P2[j] + pat2.size() -1;
		
		ans+= txt.size()-max(t1,t2);
		
		if(P1[i]<=k)	i++;
		if(P2[j]<=k)	j++;
		
	}
	cout<<ans<<endl;
	return 0;
}
