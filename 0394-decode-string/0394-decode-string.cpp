class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> results;
        string ans;
        int k = 0;

        for (const auto& c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                results.push(ans);
                k = 0;
                ans = "";
            } else if (c == ']') {
                int times = counts.top();
                counts.pop();
                string prev = results.top(); 
                results.pop();
                string repeated;
                for (int i = 0; i < times; i++) repeated += ans;
                ans = prev + repeated;
            } else {
                ans += c;
            }
        }

        return ans;
    }
};