class Solution {
    map<char, int> digitRepetition;
    bool checkDigitRepetition()
    {
        map<char, int>::iterator it;
        for(it = digitRepetition.begin(); it != digitRepetition.end(); it++)
        {
            if(it->second > 1)
            return true;
            else
            it->second = 0;
        }
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(char c = '1'; c < '9' + 1; c++)
        digitRepetition[c] = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(digitRepetition.count(board[i][j]) > 0)
                digitRepetition[board[i][j]]++;
            }
            if(checkDigitRepetition())
            return false;
            for(int j = 0; j < 9; j++)
            {
                if(digitRepetition.count(board[j][i]) > 0)
                digitRepetition[board[j][i]]++;
            }
            if(checkDigitRepetition())
            return false;
            for(int j = 0; j < 9; j++)
            {

                if(digitRepetition.count(board[(i / 3) * 3 + j / 3][j % 3 + (i * 3) % 9]) > 0)
                digitRepetition[board[(i / 3) * 3 + j / 3][j % 3 + (i * 3) % 9]]++;
            }
            if(checkDigitRepetition())
            return false;
        }
        return true;
    }
};
