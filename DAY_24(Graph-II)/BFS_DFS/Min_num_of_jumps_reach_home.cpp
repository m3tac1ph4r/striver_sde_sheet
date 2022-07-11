#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int minimumJumps(vector<int> &forbidden, int a, int b, int x)
{

    queue<pair<int, bool>> q;
    unordered_set<int> st(forbidden.begin(), forbidden.end());

    st.insert(0);

    q.push({0, true});
    int steps = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto front = q.front();
            q.pop();

            if (front.first == x)
                return steps;

            // forward
            int forward_pos = front.first + a;
            if (forward_pos <= 6000 and st.count(forward_pos) == 0)
            {
                q.push({forward_pos, true});
                st.insert(forward_pos);
            }

            // backward
            int backward_pos = front.first - b;
            if (front.second == true and backward_pos <= 6000 and backward_pos >= 0 and st.count(backward_pos) == 0)
            {
                q.push({backward_pos, false});
            }
        }

        steps++;
    }
    return -1;
}

int main()
{

    return 0;
}

// https://leetcode.com/problems/minimum-jumps-to-reach-home/