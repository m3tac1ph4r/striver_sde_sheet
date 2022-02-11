#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

struct Node
{
    Node* links[26];
    bool flag=false;
    int cntEndsWith=0,countPrefix=0;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
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
            temp->countPrefix++;  // It will increase the countPrefix to 1 from 0 for every new refernce node
        }
        temp->setEnd();
        temp->cntEndsWith++;
    }
    int countWordsEqualTo(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsKey(word[i]))
                return 0;
            temp=temp->get(word[i]);
        }
        return temp->cntEndsWith;
    }
    int countWordsStartingWith(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsKey(word[i]))
                return 0;
            temp=temp->get(word[i]);
        }
        return temp->countPrefix;
    }
    void erase(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->containsKey(word[i]))
            {
                temp=temp->get(word[i]);
                temp->countPrefix--;
            }
        }
        temp->cntEndsWith--;
    }
};
int main()
{
    Trie *root = new Trie();
    root->insert("coding");
    root->insert("ninja");
    cout<<root->countWordsEqualTo("coding")<<"\n";
    cout<<root->countWordsStartingWith("nin")<<"\n";
    root->erase("coding");
    cout << root->countWordsEqualTo("coding") << "\n";
    return 0;
};

/*
https://www.codingninjas.com/codestudio/problems/implement-trie_1387095

countPrefix is used to find the count the number of word starting with these alphabet
cntEndsWith is used to find how many words are there of that word.

For Example:
insert coding
insert ccol
countWordsEqualTo coding
countWordsStartingWith nin
erase coding

INSERT CODING
Root Node : {}
    reference(root)  c   {countPrefix:1,cntEndsWith:0}
    reference(c)     o   {countPrefix:1,cntEndsWith:0}
    reference(o)     d   {countPrefix:1,cntEndsWith:0}
    reference(d)     i   {countPrefix:1,cntEndsWith:0}
    reference(i)     n   {countPrefix:1,cntEndsWith:0}
    reference(n)     g   {countPrefix:1,cntEndsWith:1}

INSERT COOL
Root Node:{}
    reference(root)  c   {countPrefix:2,cntEndsWith:0}
    reference(c)     o   {countPrefix:2,cntEndsWith:0}
    reference(o)     o   {countPrefix:1,cntEndsWith:0}
    reference(o)     l   {countPrefix:1,cntEndsWith:0}


For deletion:
    We will decrease counter prefix and countEndsWith in last

DELETE CODING

    reference(root)  c   {countPrefix:1,cntEndsWith:0}
    reference(c)     o   {countPrefix:1,cntEndsWith:0}
    reference(o)     d   {countPrefix:0,cntEndsWith:0}
    reference(d)     i   {countPrefix:0,cntEndsWith:0}
    reference(i)     n   {countPrefix:0,cntEndsWith:0}
    reference(n)     g   {countPrefix:0,cntEndsWith:0}
*/