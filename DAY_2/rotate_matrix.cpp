#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // TRANSPOSE MATRIX
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    //reverse the row
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

/*
1. Firstly transpose the matrix 
2. Then reverse each row

ORIGINAL MATRIX : 

    1 2 3
    4 5 6
    7 8 9

TRANSPOSE MATRIX :

    1 4 7
    2 5 8
    3 6 9

NOW REVERSE OF EACH ROW :

    7 4 1
    8 5 2
    9 6 3

*/
