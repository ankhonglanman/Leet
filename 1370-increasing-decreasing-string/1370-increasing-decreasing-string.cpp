class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0};
        int len = s.size();

        for (const auto& ch : s) {
            freq[ch - 'a']++;
        }

        string res = "";
        res.reserve(s.size());

        while (res.size() < len) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0){
                    res.push_back('a' + i);
                    freq[i]--;
                }
            }

            for (int j = 25; j >= 0; j--) {
                if (freq[j] > 0) {
                    res.push_back('a' + j);
                    freq[j]--;
                }
            }
        }

        return res;
    }
};