#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

void solve(vector<vector<int>> &image, int i, int j, int oldColor, int newColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor)
        return;

    image[i][j] = newColor;
    solve(image, i - 1, j, oldColor, newColor); // UP
    solve(image, i, j - 1, oldColor, newColor); // LEFT
    solve(image, i + 1, j, oldColor, newColor); // DOWN
    solve(image, i, j + 1, oldColor, newColor); // RIGHT
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    if (image[sr][sc] != newColor)
        solve(image, sr, sc, image[sr][sc], newColor);
    return image;
}
int main()
{
    
    return 0;
}

// https://leetcode.com/problems/flood-fill/