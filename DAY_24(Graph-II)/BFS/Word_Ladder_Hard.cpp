#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    queue<pair<string, int>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    q.push({beginWord, 1});
    while (!q.empty())
    {
        string word = q.front().first;
        int ladder = q.front().second;
        q.pop();
        cout << word << endl;
        if (word == endWord)
            return ladder;
        st.erase(word);
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            for (int j = 0; j < 26; j++)
            {
                word[i] = 'a' + j;
                if (st.find(word) != st.end())
                {
                    q.push({word, ladder + 1});
                }
            }
            word[i] = ch;
        }
    }
    return 0;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/word-ladder/
// https://youtu.be/Lu7xJ94m5tU