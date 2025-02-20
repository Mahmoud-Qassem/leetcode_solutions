class Solution
{
private:
    int n, m;
    bool valid(int r, int c, vector<vector<char>> &board)
    {
        unordered_map<char, int> mp;
        for (int i = r; i < r + 3; ++i)
        {
            for (int j = c; j < c + 3; ++j)
            {
                if (board[i][j] != '.' && mp[board[i][j]])
                    return false;
                mp[board[i][j]]++;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        n = board.size(), m = board.size();

        for (int c = 0; c < m; ++c)
        {
            unordered_map<char, int> mp;
            for (int r = 0; r < n; ++r)
            {
                if (board[r][c] != '.' && mp[board[r][c]])
                    return false;

                mp[board[r][c]]++;
            }
        }

        for (int r = 0; r < n; ++r)
        {
            unordered_map<char, int> mp;
            for (int c = 0; c < m; ++c)
            {
                if (board[r][c] != '.' && mp[board[r][c]])
                    return false;
                mp[board[r][c]]++;
            }
        }

        for (int j = 0; j < n; j += 3)
        {
            for (int i = 0; i < n; i += 3)
            {
                if (not valid(i, j, board))
                {
                    return false;
                }
            }
        }
        return true;
    }
};