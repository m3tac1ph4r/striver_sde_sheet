#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

vector<int> repeatedNumbers(vector<int> A)
{
    vector<int> count(A.size() + 1, 0);
    vector<int> ans(2);
    for (int i = 0; i < A.size(); i++)
    {
        count[A[i]]++;
    }
    int repeating = 0, missing = 0;
    for (int i = 0; i < count.size(); i++)
    {
        if (repeating == 0 and count[i] > 1)
        {
            // cout<<i<<"\n";
            ans[0] = i;
            repeating = 1;
        }
        else if (missing == 0 and count[i] == 0 and i != 0)
        {
            // cout << i << "\n";
            ans[1] = i;
            missing = 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> ans = repeatedNumbers(A);
    for (int i = 0; i < 2; i++)
        cout << ans[i] << " ";
    return 0;
}