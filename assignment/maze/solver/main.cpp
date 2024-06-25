#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int MAX_SIZE = 100; 
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Node {
    int cost;
    int x, y;
    bool operator>(const Node& otherNode) const {
        return cost > otherNode.cost;
    }
};

void printMaze(int maze[MAX_SIZE][MAX_SIZE], bool path[MAX_SIZE][MAX_SIZE], int row, int col) {
    cout << "-------------------" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (path[i][j]) {
                cout << "*";
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

void findShortestPath(int maze[MAX_SIZE][MAX_SIZE], int row, int col) {
    vector<vector<int>> Dist(row, vector<int>(col, 999));
    vector<vector<pair<int, int>>> Parent(row, vector<pair<int, int>>(col, {-1, -1}));
    bool path[MAX_SIZE][MAX_SIZE] = {{false}};

    priority_queue<Node, vector<Node>, greater<Node>> Q;
    Dist[0][1] = maze[0][1];
    Q.push({maze[0][1], 0, 1});

    while (!Q.empty()) {
        Node current = Q.top();
        Q.pop();

        int x = current.x;
        int y = current.y;

        if (current.cost > Dist[x][y]) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int dx = directions[i][0];
            int dy = directions[i][1];
            int nx = x + dx;
            int ny = y + dy;

            bool isInBounds = (nx >= 0 && nx < row && ny >= 0 && ny < col);
            bool isWall = (maze[nx][ny] == 0);

            if (isInBounds && !isWall) {
                int new_cost = current.cost + maze[nx][ny];
                if (new_cost < Dist[nx][ny]) {
                    Dist[nx][ny] = new_cost;
                    Q.push(Node{new_cost, nx, ny});
                    Parent[nx][ny] = pair<int, int>(x, y);
                }
            }
        }
    }

    int x = row - 1;
    int y = col - 2;
    while (x != -1 && y != -1) {
        path[x][y] = true;
        pair<int, int> parent = Parent[x][y];
        x = parent.first;
        y = parent.second;
    }

    printMaze(maze, path, row, col);
    cout << Dist[row-1][col-2] << endl;
}

int main() {
    int row, col;
    cin >> row >> col;
    cin.ignore();

    int maze[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < row; ++i) {
        string line;
        getline(cin, line);
        for (int j = 0; j < col; ++j) {
            maze[i][j] = line[j] - '0';
        }
    }

    findShortestPath(maze, row, col);

    return 0;
}