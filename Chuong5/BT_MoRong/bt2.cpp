#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

// Định nghĩa struct để biểu diễn một điểm trong mê cung
struct Point {
    int x, y;
    Point parent; // Lưu trữ ô cha
};

// Hàm kiểm tra xem một điểm có hợp lệ trong mê cung không
bool isValid(int r, int c, int n, int m) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

// Hàm tìm đường đi bằng BFS
pair<int, stack<Point>> bfs(int n, int m, int maze[][6], Point start, Point end) {
    if (maze[start.x][start.y] == 1 || maze[end.x][end.y] == 1) {
        return {0, {}};
    }

    queue<Point> q;
    start.parent = {-1, -1};
    q.push(start);
    bool visited[5][6] = {false};
    visited[start.x][start.y] = true;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == end.x && current.y == end.y) {
            stack<Point> path;
            Point curr = current;
            while (curr.x != -1) {
                path.push(curr);
                curr = curr.parent;
            }
            return {path.size(), path};
        }

        for (int i = 0; i < 4; ++i) {
            int next_r = current.x + dx[i];
            int next_c = current.y + dy[i];

            if (isValid(next_r, next_c, n, m) && maze[next_r][next_c] == 0 && !visited[next_r][next_c]) {
                visited[next_r][next_c] = true;
                Point next_point = {next_r, next_c, current};
                q.push(next_point);
            }
        }
    }

    return {0, {}};
}

// Hàm tìm đường đi bằng DFS
pair<int, stack<Point>> dfs(int n, int m, int maze[][6], Point start, Point end) {
    if (maze[start.x][start.y] == 1 || maze[end.x][end.y] == 1) {
        return {0, {}};
    }

    stack<Point> s;
    start.parent = {-1, -1};
    s.push(start);
    bool visited[5][6] = {false};
    visited[start.x][start.y] = true;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!s.empty()) {
        Point current = s.top();
        s.pop();

        if (current.x == end.x && current.y == end.y) {
            stack<Point> path;
            Point curr = current;
            while (curr.x != -1) {
                path.push(curr);
                curr = curr.parent;
            }
            return {path.size(), path};
        }

        for (int i = 0; i < 4; ++i) {
            int next_r = current.x + dx[i];
            int next_c = current.y + dy[i];

            if (isValid(next_r, next_c, n, m) && maze[next_r][next_c] == 0 && !visited[next_r][next_c]) {
                visited[next_r][next_c] = true;
                Point next_point = {next_r, next_c, current};
                s.push(next_point);
            }
        }
    }

    return {0, {}};
}

int main() {
    ifstream infile("MECUNG.INP");
    ofstream outfile("MECUNG.OUT");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening input files!" << endl;
        return 1;
    }

    int n, m, x0, y0, x1, y1;
    infile >> n >> m >> x0 >> y0 >> x1 >> y1;

    int maze[5][6];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            infile >> maze[i][j];
        }
    }

    Point start = {x0 - 1, y0 - 1}; // Điều chỉnh về index 0-based
    Point end = {x1 - 1, y1 - 1};

    outfile << "BFS:" << endl;
    pair<int, stack<Point>> bfs_result = bfs(n, m, maze, start, end);
    outfile << bfs_result.first << endl;
    if (bfs_result.first > 0) {
        stack<Point> path = bfs_result.second;
        while (!path.empty()) {
            Point p = path.top();
            outfile << p.x + 1 << " " << p.y + 1 << endl;
            path.pop();
        }
    }

    outfile << endl << "DFS:" << endl;
    pair<int, stack<Point>> dfs_result = dfs(n, m, maze, start, end);
    outfile << dfs_result.first << endl;
    if (dfs_result.first > 0) {
        stack<Point> path = dfs_result.second;
        stack<Point> reversed_path;
        while (!path.empty()) {
            reversed_path.push(path.top());
            path.pop();
        }
        while (!reversed_path.empty()) {
            Point p = reversed_path.top();
            outfile << p.x + 1 << " " << p.y + 1 << endl;
            reversed_path.pop();
        }
    }

    infile.close();
    outfile.close();

    return 0;
}