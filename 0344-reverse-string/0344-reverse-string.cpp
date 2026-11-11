class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int end = len / 2;
        for (int i = 0; i < end; i++) {
            swap(s[i], s[len - 1 - i]);
        }
    }
};