class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s(nums.begin(), nums.end());
        int a = ((n)*(n+1))/2;
        int b = 0;
        for(int i : s) b += i;
        int c = 0;
        for(int i : nums) c += i;

        return {c-b, a-b};
    }
};