#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

void printMaze(const vector<vector<int>>& maze) {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPath(vector<vector<int>>& maze, int row, int col) {
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, int>> Q;
    Q.push({0, 1});
    visited[0][1] = true;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        if (x == row - 1 && y == col - 2) return true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            bool isInBound = nx >= 0 && ny >= 0 && nx < row && ny < col;
            if (isInBound) {
                bool isWall = maze[nx][ny] == 0;
                bool notVisited = !visited[nx][ny];
                if (!isWall && notVisited) {
                    visited[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }

        }
    }
    return false;
}

void buildMaze(vector<vector<int>>& maze, int row, int col) {
   srand((time(0)));

    for (int i = 1; i < row - 1; ++i) {
        for (int j = 1; j < col - 1; ++j) {
            maze[i][j] = rand() % 9 + 1;
        }
    }
    for (int i = 0; i < row; ++i) {
        maze[i][0] = maze[i][col - 1] = 0;
    }
    for (int j = 0; j < col; ++j) {
        maze[0][j] = maze[row - 1][j] = 0;
    }

    maze[0][1] = rand() % 9 + 1;
    maze[row - 1][col - 2] = rand() % 9 + 1; 


    for (int i = 1; i < row - 1; ++i) {
        for (int j = 1; j < col - 1; ++j) {
            bool isWall = (maze[i][j] == 0);
            bool randomAddWall = (rand() % 2 == 0);
            bool isStartOrEnd = (i == 0 && j == 1) || (i == row - 1 && j == col - 2);

            if (!isWall && randomAddWall && !isStartOrEnd) {
                int back = maze[i][j];
                maze[i][j] = 0; 
                if (!isPath(maze, row, col)) {
                    maze[i][j] = back; 
                }
            }
        }
    }
}

int main() {
    int row, col;
    cin >> row >> col;

    if (row < 3 || col < 3) {
        cout << "미로를 만들기 위해서는 최소 3개의 행과 열이 필요합니다." << endl;
        return 1;
    }

    vector<vector<int>> maze(row, vector<int>(col));
    buildMaze(maze, row, col);
    printMaze(maze);

    return 0;
}