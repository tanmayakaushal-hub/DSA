class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2){
            if(nums[0] == nums[1]) return 2;
            else return 1;
        }

        int ans = 0;
        for(int i = 1; i < n-1; i++){
            double avg = (nums[i-1] + nums[i+1])/2.00;
            if(double(nums[i]) >= avg) ans++;
        }
        if(nums[0] >= nums[1]) ans++;
        if(nums[n-1] >= nums[n-2]) ans++;
        return ans;
    }
};