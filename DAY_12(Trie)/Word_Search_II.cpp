#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

class Solution
{
public:
    bool visited[13][13] = {false};
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    struct Trie
    {
        Trie *links[26];
        bool flag = false;
        string str;

        bool containsKey(char ch)
        {
            return links[ch - 'a'] != NULL;
        }
        void putChar(char ch, Trie *temp)
        {
            links[ch - 'a'] = temp;
        }
        Trie *get(char ch)
        {
            return links[ch - 'a'];
        }
        void setEnd()
        {
            flag = true;
        }
    };
    Trie *root = new Trie();
    void insert(string word)
    {
        Trie *temp = root;
        for (char ch : word)
        {
            if (temp->containsKey(ch) == false)
            {
                temp->putChar(ch, new Trie());
            }
            temp = temp->get(ch);
        }
        temp->str = word;
        temp->setEnd();
    }

    void dfs(int i, int j, vector<vector<char>> &board, Trie *node, unordered_set<string> &st,
             int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        node = node->get(board[i][j]);
        if (visited[i][j] || node == NULL)
            return;

        if (node->flag)
        {
            st.insert(node->str);
        }

        visited[i][j] = true;
        for (int pos = 0; pos < 4; pos++)
        {
            int newRow = i + delRow[pos];
            int newCol = j + delCol[pos];

            dfs(newRow, newCol, board, node, st, n, m);
        }
        visited[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (string word : words)
            insert(word);

        int n = board.size();
        int m = board[0].size();
        unordered_set<string> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(i, j, board, root, st, n, m);
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};

int main()
{

    return 0;
}

// https://youtu.be/dF5uQw7fvLA
// https://leetcode.com/problems/word-search-ii/description/