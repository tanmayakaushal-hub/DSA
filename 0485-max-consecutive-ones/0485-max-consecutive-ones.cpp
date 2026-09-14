class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, cnt = 0;
        for(int i : nums){
            if(i == 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
    }
};