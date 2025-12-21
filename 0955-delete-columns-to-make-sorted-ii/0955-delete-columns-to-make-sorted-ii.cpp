class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        int deletions = 0;
        vector<bool> already_Sorted(rows - 1, false);

        for (int i = 0; i < cols; i++) {

            bool deleted = false;
            for (int j = 1; j < rows; j++) {

                if ((strs[j][i] < strs[j - 1][i]) && !already_Sorted[j - 1]) {
                    deleted = true;
                    deletions++;
                    break;
                }
            }
            if (deleted)
                continue;

            for (int r = 0; r < rows - 1; r++) {
                already_Sorted[r] =
                    already_Sorted[r] | (strs[r][i] < strs[r + 1][i]);
            }
        }

        return deletions;
    }
};