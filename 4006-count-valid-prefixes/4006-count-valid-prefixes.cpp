class Solution {
public:
    int countValidPrefixes(string s) {
        int numZero = 0;
        int numOne = 0; 

        int res = 0;
        for (const auto& ch : s) {
            if (ch == '0') numZero++;
            else numOne++;

            if (abs(numOne - numZero) <= 1) res++;
        }

        return res;
    }
};