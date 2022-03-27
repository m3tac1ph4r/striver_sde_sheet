#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

string FirstNonRepeating(string s)
{
    string ans;
    unordered_map<char,int> count;
    queue<char> q;
    for(int i=0;i<s.length();i++)
    {
        // charachter added to the queue and increased the count in map
        q.push(s[i]);
        count[s[i]]++;
        
        while(!q.empty())
        {
            // check if the character is at the front is repeating or not if yes then remove it
            if(count[q.front()]>1)
                q.pop();
            else
            {
                //if the character is non repeating then push it to the ans 
                ans.push_back(q.front());
                break;
            }
        }
        //if all elements are repeating till s[i] then put # to the ans
        if(q.empty())
            ans.push_back('#');
    }
    return ans;
} 
int main()
{
    string s;
    cin>>s;
    cout << FirstNonRepeating(s); 
    return 0;
}
/*
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
*/