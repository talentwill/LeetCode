// 2023-12-21

class Solution {
public:
    string tictactoe(vector<string>& board)
    {
        const int N = board.size();

        // 横向检查
        for (int i = 0; i < N; i++) {
            int j = 1;
            for (; j < N; j++) {
                if (board[i][j] == ' ' or board[i][j] != board[i][0]) {
                    break;
                }
            }
            if (j == N) {
                return string(1, board[i][0]);
            }
        }

        // 纵向检查
        for (int j = 0; j < N; j++) {
            int i = 1;
            for (; i < N; i++) {
                if (board[i][j] == ' ' or board[i][j] != board[0][j]) {
                    break;
                }
            }
            if (i == N) {
                return string(1, board[0][j]);
            }
        }

        // 对角线检查
        int i = 1;
        for (int j = 1; i < N; i++, j++) {
            if (board[i][j] == ' ' or board[i][j] != board[0][0]) {
                break;
            }
        }
        if (i == N) {
            return string(1, board[0][0]);
        }

        // 逆对角线检查
        int j = N - 2;
        for (i = 1; i < N; i++, j--) {
            if (board[i][j] == ' ' or board[i][j] != board[0][N - 1]) {
                break;
            }
        }
        if (i == N) {
            return string(1, board[0][N - 1]);
        }

        // 空格检查
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == ' ') {
                    return "Pending";
                }
            }
        }
        return "Draw";
    }
};