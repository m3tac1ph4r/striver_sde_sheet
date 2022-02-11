#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
struct Node
{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return links[ch-'a'];
    }
    void putChar(char ch,Node* temp)
    {
        links[ch-'a']=temp;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool checkEnd()
    {
        return flag;
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
        temp->setEnd();         //temp->flag=true;
    }
    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i]))
                return false;
            temp = temp->get(word[i]);
        }
        if(temp->checkEnd()==true)
            return true;
        else
            return false;
        
    }
    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!temp->containsKey(prefix[i]))
                return false;
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};
int main()
{
    Trie* root=new Trie();
    root->insert("apple");
    root->insert("app");
    cout<<root->search("apple")<<"\n";
    cout<<root->startsWith("app")<<"\n";
    cout<<root->search("ashu")<<"\n";
    return 0;
}

/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/