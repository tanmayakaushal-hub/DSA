class node{
    public:
    char ch;
    int no;

    node(char ch, int val){
        this -> ch = ch;
        this -> no = val;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a -> no < b -> no;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<node*, vector<node*>, compare> pq;
        unordered_map<char, int> mp;
        string ans = "";
        
        for(char ch : s) mp[ch]++;

        for (const auto& [key, value] : mp){
            node* nn = new node(key, value);
            pq.push(nn);
        }


        while(pq.size() >= 2){
            node* n1 = pq.top();
            pq.pop();
            node* n2 = pq.top();
            pq.pop();

            ans += n1 -> ch;
            ans += n2 -> ch;

            if(--n1 -> no > 0) pq.push(n1);
            if(--n2 -> no > 0) pq.push(n2);
            
        }

        if(!pq.empty()){
            node* temp = pq.top();
            if(temp -> no > 1) return "";
            ans += temp -> ch;
        }

        return ans;


    }
};