class Solution {
private:    
    bool isChar (char c){
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
    char convertToLower(char ch){
        if(ch >= 'A' && ch <= 'Z') ch ^= 1<<5;
        return ch;
    }
public:
    bool isPalindrome(string s) {
        vector<char> seen;
        seen.reserve(s.size());
        for(const auto& ch : s){
            if(isChar(ch)){
                char c = convertToLower(ch);
                seen.push_back(c);
            }
        }

        int stopPoint = seen.size()/2;
        for(int i = 0; i < stopPoint; i++){
            if (seen[i] != seen[seen.size() - 1 - i]) return false;
        }

        return true;
    }
};