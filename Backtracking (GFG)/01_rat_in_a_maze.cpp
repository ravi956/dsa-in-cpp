//0->blocked walls
//1->rat can move in this
//rat has to moves right({i,j}->{i,j+1}) and down({i,j}->{i+1,j})
//he wants to go from cell {0,0} to cell {n-1,n-1}
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<bool>> path(MAX, vector<bool>(MAX, false));

bool isValid(int i, int j, int n, vector<vector<int>> &maze)
{
    return (i < n && j < n && maze[i][j] == 1);
}

void printPath(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}

bool mazeSolver(vector<vector<int>> &maze, int i, int j, int n)
{
    if (i == n - 1 && j == n - 1 && maze[i][j] == 1)
    {
        cout << "YES\n";
        path[i][j] = true;
        printPath(n);
        return true;
    }

    if (isValid(i, j, n, maze))
    {
        path[i][j] = true;

        if (mazeSolver(maze, i, j + 1, n))
            return true;
        else if (mazeSolver(maze, i + 1, j, n))
            return true;

        path[i][j] = false;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the size of grid/maze :";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the values of the cells :\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    if (mazeSolver(maze, 0, 0, n) == false)
    {
        cout << "NO\n";
    }

    return 0;
}