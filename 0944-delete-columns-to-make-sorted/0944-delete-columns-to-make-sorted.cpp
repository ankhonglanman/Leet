class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strLen = strs[0].size();

        vector<char> prev(strLen, '0');
        int minDel = 0;
        for (const auto& str : strs) {
            for (int i = 0; i < strLen; i++) {
                if (prev[i] != '~') {
                    if (str[i] < prev[i]) {
                        minDel++;
                        prev[i] = '~';
                        continue;
                    }
                    prev[i] = str[i];
                }
            } 
        }

        return minDel;
    }
};