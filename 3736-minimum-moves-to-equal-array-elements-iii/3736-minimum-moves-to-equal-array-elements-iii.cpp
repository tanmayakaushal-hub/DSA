class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int moves = 0;

        for(int i : nums) moves += mx - i;

        return moves;
    }
};