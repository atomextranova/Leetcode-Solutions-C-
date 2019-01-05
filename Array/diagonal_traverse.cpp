using namespace std;

#include <vector>
#include <iostream>

class Solution {
public:

    // Time: O(n) scan the matrix once
    // Space: O(n) extra space to store the extra array
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        size_t N = matrix.size();
        size_t M = matrix[0].size();
        size_t size_new = N * M;
        vector<int> array(size_new);
        size_t row = 0;
        size_t column = 0;
        for (size_t i = 0; i < size_new; i++) {
            array[i] = matrix[row][column];
            // Move upwards
            if ((row + column) % 2 == 0) {
                // Touch right margins, next one will be on row down
                if (column == M - 1) {
                    row += 1;
                // Touch top margins, next one will be on column right
                } else if (row == 0) {
                    column += 1;
                // Move right and up
                } else {
                    row -= 1;
                    column += 1;
                }
            // Move downwards
            } else {
                // Touch bottom margins, next one will be on column right
                if (row == N - 1) {
                    column += 1;
                // Touch left margins, next one will be on row down
                } else if (column == 0) {
                    row += 1;
                // Move down and left
                } else {
                    row += 1;
                    column -= 1;
                }
            }
        }
        return array;
    }

    // Less condition checks
    // Time: O(n) scan the matrix once
    // Space: O(n) extra space to store the extra array
    vector<int> findDiagonalOrder_2(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), k = 0;
        vector<int> res(m * n);
        // i+j = c, m[i][j], next is m[i-1][j+1] or m[i+1][j-1]
        for (int c = 0; c < m + n - 1; ++c) {
            // Get the bound of row index
            // Upper bound is the smaller between c and max row index (m - 1)
            // Lower bound is the larger between 0 and c - (n - 1) (column max index). The larger n - 1, the lower bound
            // becomes larger until it reaches 0
            int low = max(0, c - n + 1), high = min(c, m - 1);
            if (c % 2 == 0) {
                for (int i = high; i >= low; --i) {
                    res[k++] = matrix[i][c - i];
                }
            } else {
                for (int i = low; i <= high; ++i) {
                    res[k++] = matrix[i][c - i];
                }
            }
        }
        return res;
    }
};

//void print_vector (vector<vector<int>> &matrix) {
//
//}

int main() {
    auto sol = new Solution();
    vector <vector<int>> test_case_1(3, vector<int>(4, 1));
    size_t index = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            test_case_1[i][j] = index;
            index += 1;
        }
    }
    sol->findDiagonalOrder(test_case_1);
};
