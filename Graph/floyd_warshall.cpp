#include <iostream>
#include <vector>
using namespace std;

void shortest_dist(vector<vector<int>> &matrix) {
    int s = matrix.size();

    // Step 1: Replace -1 with "infinity" and 0 for diagonal
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9; // large value = infinity
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    // Step 2: Floyd–Warshall
    for (int k = 0; k < s; k++) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Step 3: Negative cycle detection
    for (int i = 0; i < s; i++) {
        if (matrix[i][i] < 0) {
            cout << "Negative cycle detected\n";
            return; // stop immediately
        }
    }

    // Step 4: Print shortest distance matrix
    cout << "Shortest Distance Matrix:\n";
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (matrix[i][j] == 1e9)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n; // number of vertices
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    shortest_dist(matrix);
    return 0;
}
