/*
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 * 
 * Example:
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 */

#ifndef LEET_CODE_0079_WORDSEARCH_H_
#define LEET_CODE_0079_WORDSEARCH_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0079 {
    class Solution {
    public:
        bool exist(vector<vector<char>> &board,
                   vector<vector<bool>> &map,
                   int row_idx, int row_num,
                   int col_idx, int col_num,
                   string &word, int char_idx) {
            if (row_idx == row_num || row_idx < 0 || col_idx == col_num || col_idx < 0) return false;
            if (map[row_idx][col_idx] || board[row_idx][col_idx] != word[char_idx]) return false;
            if (char_idx == word.size() - 1) return true;

            map[row_idx][col_idx] = true;
            if (exist(board, map, row_idx, row_num, col_idx + 1, col_num, word, char_idx + 1)) return true;
            if (exist(board, map, row_idx, row_num, col_idx - 1, col_num, word, char_idx + 1)) return true;
            if (exist(board, map, row_idx + 1, row_num, col_idx, col_num, word, char_idx + 1)) return true;
            if (exist(board, map, row_idx - 1, row_num, col_idx, col_num, word, char_idx + 1)) return true;
            map[row_idx][col_idx] = false;

            return false;
        }

        bool exist(vector<vector<char>> &board, string word) {
            if (word.empty()) return true;
            int row_num = board.size();
            if (row_num == 0) return false;
            int col_num = board[0].size();
            if (col_num == 0) return false;

            vector<vector<bool>> map(row_num, vector<bool>(col_num, false));
            for (int row_idx = 0; row_idx < row_num; row_idx++) {
                for (int col_idx = 0; col_idx < col_num; col_idx++) {
                    if (exist(board, map, row_idx, row_num, col_idx, col_num, word, 0)) return true;
                }
            }
            return false;
        }
    };

}

TEST(L0079_WordSearch, CASE_TEST) {
    using namespace L0079;
    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    EXPECT_TRUE(s.exist(board, "SEE"));
}

#endif //LEET_CODE_0079_WORDSEARCH_H_
