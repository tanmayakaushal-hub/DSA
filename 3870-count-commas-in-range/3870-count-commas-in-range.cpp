class Solution {
public:
    int countCommas(int n) {
        int commas = 0;
        for(int i = 1000; i <= n; i++){
            commas++;
        }
        return commas;
    }
};