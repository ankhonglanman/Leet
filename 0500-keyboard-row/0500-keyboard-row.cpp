class Solution {
private:
    unordered_set<char> firstRow = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
    unordered_set<char> secondRow = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
    unordered_set<char> thirdRow = {'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
public:
    vector<string> findWords(vector<string>& words) {

        vector<string> res;
        res.reserve(words.size()); 
        for (const auto& word : words) {

            bool add = true;
            if (firstRow.contains(word[0])) {
                for (const auto& ch : word) {
                    if (!firstRow.contains(ch)) {
                        add = false;
                        break;
                    }
                }
            }
            else if (secondRow.contains(word[0])){
                for (const auto& ch : word) {
                    if (!secondRow.contains(ch)) {
                        add = false;
                        break;
                    }
                }
            }
            else {
                for (const auto& ch : word) {
                    if (!thirdRow.contains(ch)) {
                        add = false;
                        break;
                    }
                }
            }

            if (add) res.push_back(word);
        }
        
        return res;
    }
};