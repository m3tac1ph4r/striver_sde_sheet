#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;
    
vector<string> split(string path,char deli)
{
    vector<string> ans;
    string temp="";
    for(int i=0;i<path.length();i++)
    {
        if(path[i]!=deli)
        {
            temp=temp+path[i];
        }
        else
        {
            ans.push_back(temp);
            temp="";
        }
    }
    ans.push_back(temp);
    return ans;
}   
string simplifyPath(string path)
{
    if(path.length()==1)
        return "/";
    vector<string> words=split(path,'/');
    string res="";
    stack<string> myStack;
    vector<string> answer_words;
    for(int i=0;i<words.size();i++)
    {
        if(words[i]==".." and !myStack.empty())
            myStack.pop();
        else if((words[i]!="..") and (words[i]!=".") and (words[i]!=""))
        {
            myStack.push(words[i]);
        }
    }
    if(myStack.empty())
        return "/";
    while(!myStack.empty())
    {
        answer_words.push_back(myStack.top());
        answer_words.push_back("/");
        myStack.pop();
    }
    for (int i = answer_words.size()-1; i >=0 ; i--)
    {
        res+=answer_words[i];
    }
    return res;
}    
int main()
{
    string path;
    cin>>path;
    string ans=simplifyPath(path);
    cout<<ans;
    return 0;
}

/*
https://leetcode.com/problems/simplify-path/
*/
/*
Firstly we will split the string using delimeter '/'

There are simple two rules:
1. ".." is for pop
2. Other we will push in the stack

INPUT: /a/./b/../../c
If we delimit the string using '/' then {a . b .. .. c}

Now if word is ".." then pop from stack and if word is "" and "." and ".." then push the word in stack

Now we have vector {a . b .. .. c}

0. a will be inserted in the stack [a]
1. nothing will happen  [a]
2. b will be inserted in the stack [a b]
3. b will be pop out from the stack [a]
4. a will be pop out from the stack []
5. c will be inserted

Now we will pop out all the element from stack and then add "/" in the vector

Then it would be like {c,/} Now print the vector from size-1 to 0
*/

