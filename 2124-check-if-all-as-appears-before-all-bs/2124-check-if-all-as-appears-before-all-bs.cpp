class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        int len = s.size();
        for (; i < len; i++) {
            if (s[i] == 'b') break;
        }

        for (; i < len; i++) {
            if (s[i] == 'a') return false;
        }

        return true;
    }
};