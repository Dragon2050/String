#include<bits/stdc++.h>

using namespace std;

string text,pattern;

int failure[100001];

void failure_function()
{
    failure[0] = 0;
    int k=1,len=0,lenp=pattern.size();
    while(k<lenp)
    {
        if(pattern[k] == pattern[len])
        {
            failure[k++]=++len;
        }
        else{
            if(len)
            {
                len=failure[len-1];
            }
            else{
                failure[k++]=0;
            }
        }
    }
}

int KMP_match()
{
    int i=0,j=0,ret=-1;
    int lent=text.size();
    while(i<lent)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
            if(j==pattern.size())
            {
                ret=i-pattern.size();
                j=failure[j-1];
            }
        }
        else{
            if(j)
            {
                j=failure[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return ret;
}

int main()
{
    cin>>text>>pattern;
    failure_function();
    int res=KMP_match();
    if(res == -1)
    {
        cout<<"THE STRING IS NOT FOUND"<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}
