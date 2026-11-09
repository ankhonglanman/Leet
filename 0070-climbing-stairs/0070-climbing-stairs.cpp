class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        vector<int> stepsEachStair(n + 1, 0);
        stepsEachStair[0] = 1;
        stepsEachStair[1] = 1;

        for (int i = 2; i <= n; i++) {
            stepsEachStair[i] = stepsEachStair[i - 1] + stepsEachStair[i - 2];
        }

        return  stepsEachStair[n];
    }
};