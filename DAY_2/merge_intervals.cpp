#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> s;
    s.push_back({v[0].first, v[0].second});
    for (int i = 1; i < n; i++)
    {
        int start1 = s[s.size() - 1].first;
        int end1 = s[s.size() - 1].second;
        int start2 = v[i].first;
        int end2 = v[i].second;
        if (end1 >= start2)
        {
            s.pop_back();
            end1 = max(end1, end2);
            s.push_back({start1, end1});
        }
        else
            s.push_back({start2, end2});
    }
    cout << s.size() << endl;
    for (int i = 0; i < s.size(); i++)
        cout << s[i].first << " " << s[i].second << endl;
    return 0;
}