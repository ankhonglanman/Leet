class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (const auto& num1 : arr1) {
            for (const auto& num2 : arr2) {
                if (abs(num2 - num1) <= d) goto notValid;
            }
            res++;
            notValid: 
        }

        return res;
    }
};