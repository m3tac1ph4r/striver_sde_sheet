#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

int repeatedStringMatch(string a,string b)
{
    /*
    a -> pattern
    b -> text
    */
    int p=31;
    int pat_len=a.length();
    int text_len=b.length();
    vector<long long> power(text_len+1);
    vector<long long> hash_text(text_len+1,0);
    long long pattern_hash=0;
    power[0]=1;
    for(int i=1;i<text_len+1;i++)
    {
        power[i]=(power[i-1]*p)%M;
    }
    for(int i=0;i<text_len;i++)
    {
        hash_text[i+1]=(hash_text[i]+(b[i]-'a'+1)*power[i])%M;
    }

    // for finding hash of pattern_text
    for(int i=0;i<pat_len;i++)
    {
        pattern_hash=(pattern_hash+(a[i]-'a'+1)*power[i])%M;
    }

    // Now searching the pattern in text
    int count=0;
    for(int i=0;i+pat_len-1<text_len;i++)
    {
        long long current_hash=(hash_text[i+pat_len]-hash_text[i]+M)%M;
        if(current_hash==(pattern_hash*power[i])%M)
            count++;
    }
    return count;
    
}
int main()
{
    string text,pattern;
    cin>>text;
    cin>>pattern;
    cout<<repeatedStringMatch(pattern,text);
    return 0;
}