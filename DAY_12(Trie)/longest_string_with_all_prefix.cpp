#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
struct Node
{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a']!=NULL);
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void putChar(char ch,Node* node)
    {
        links[ch-'a']=node;
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
    bool searchChar(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                return false;
            }
            temp=temp->get(word[i]);
        }
        return temp->flag;
    }
    bool searchWord(string word)
    {
        for(int i=1;i<word.length();i++)
        {
            if (searchChar(word.substr(0, i)) != true)
            {
                return false;
            }
        }
        return true;
    }
    void insert(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsKey(word[i]))
            {
                temp->putChar(word[i],new Node());
            }
            temp=temp->get(word[i]);
        }
        temp->flag=true;
    }
};
string completeString(int n,vector<string> a)
{
    int max_len=0;
    string ans="";
    Trie* root=new Trie();
    for(int i=0;i<a.size();i++)
    {
        root->insert(a[i]);
    }
    for(int i=0;i<a.size();i++)
    {
        if(root->searchWord(a[i]))
        {
            if(a[i].length()>ans.length())
            {
                ans=a[i];
            }
            else if(a[i].length()==ans.length() and a[i]<ans)
            {
                ans=a[i];
            }
        }
    }
    return ans==""?"None":ans;
}    
int main()
{
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<completeString(n,a);
    return 0;
}

/*
https://www.codingninjas.com/codestudio/problems/complete-string_2687860
*/