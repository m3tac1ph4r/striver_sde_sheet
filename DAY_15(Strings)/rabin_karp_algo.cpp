#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void repeatedStringMatch(string pat,string text)
{
    /*
    a -> pattern
    b -> text
    */
    int p=31;
    int pat_len=pat.length();
    int text_len=text.length();
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
        hash_text[i+1]=(hash_text[i]+(text[i]-'a'+1)*power[i])%M;
    }

    // for finding hash of pattern_text
    for(int i=0;i<pat_len;i++)
    {
        pattern_hash=(pattern_hash+(pat[i]-'a'+1)*power[i])%M;
    }

    // Now searching the pattern in text
    for(int i=0;i+pat_len-1<text_len;i++)
    {
        long long current_hash=(hash_text[i+pat_len]-hash_text[i]+M)%M;
        if(current_hash==(pattern_hash*power[i])%M)
            cout<<"Found at index ("<<i<<","<<i+pat_len-1<<")"<<"\n";
    }
    
}
int main()
{
    string text,pattern;
    cin>>text;
    cin>>pattern;
    repeatedStringMatch(pattern,text);
    return 0;
}

/*
Time Complexity :
Worst Case -> O(mn)
Best and Average Case -> O(m+n)

Space Complexity -> O(1)
*/
/*
https://www.youtube.com/watch?v=-WdkLyTeZ3Q&ab_channel=ApnaCollege

Must Do Dry For better understanding
*/