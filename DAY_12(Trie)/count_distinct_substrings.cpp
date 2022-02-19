#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
struct Node
{
    Node* links[26];
    bool flag=false;

    void put(char ch,Node* temp)
    {
        links[ch-'a']=temp;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
};


class Trie
{
    Node* root;
    public:
        Trie()
        {
            root=new Node();
        }
    int countDistinct(string s)
    {
        int count=1;
        for(int i=0;i<s.length();i++)
        {
            Node* temp=root;
            for(int j=i;j<s.length();j++)
            {
                if(!temp->containsKey(s[j]))
                {
                    temp->put(s[j],new Node());
                    count++;
                }
                temp=temp->get(s[j]);
            }
        }
        return count;
    }
};
int countDistinctSubstrings(string s)
{
    Trie* root=new Trie();
    return root->countDistinct(s);
}
int main()
{
    string s;
    cin>>s;
    cout<<countDistinctSubstrings(s)<<"\n";
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292

Suppose string is "abab"

Now we will run two for loop first i=0 and second j=i to n-1

count=0
i=0
    j=0 "a"
        count=1
    j=1 "ab"
        count=2
    j=2 "aba"
        count=3
    j=3 "abab"
        count=4
i=1
    j=1 "b"
        count=5
    j=2 "ba"
        count=6
    j=3 "bab"
        count=7
i=2
    j=2 "a"
        already in the trie
    j=3 "ab"
        already in the trie
i=3
    j=3 "b"
        already in the trie

Now count=7 and we have one more substring which is "" 
    count+1=> 7+1 => 8
*/
