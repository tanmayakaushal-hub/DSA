class node{
    public:
    int val, i, j;
    node(int data, int x, int y){
        val = data;
        i = x;
        j = y;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a -> val > b -> val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*, vector<node*>, compare> minHeap; // minHeap logic ke liye
        int max_value = INT_MIN; // heap mein current maximum value
        int min_value = -1;

        for(int i = 0; i < nums.size(); i++){
            node* temp = new node(nums[i][0], i, 0);
            minHeap.push(temp);
            if(nums[i][0] > max_value) max_value = nums[i][0];
        }

        min_value = minHeap.top() -> val;
        vector<int> ans = {min_value, max_value};
        int range = max_value - min_value;

        while(minHeap.size() > 0){
            node* temp = minHeap.top();
            minHeap.pop();

            int i = temp -> i;
            int j = temp -> j;
            delete temp;

            if(j+1 < nums[i].size()){
                node* next = new node(nums[i][j+1], i, j+1);
                minHeap.push(next);
                max_value = max(max_value, next->val);
                min_value = minHeap.top()->val;
                
                if(max_value - min_value < range){
                ans[0] = min_value;
                ans[1] = max_value;
                range = max_value - min_value;
                }
            }
            else{
                break;
            }
        }

        return ans;
    }
};