class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v;
        for(int i = 0; i < m-1; i++){
            string st;
            st.append(1, '.');
            st.append(n-1, '#');
            v.push_back(st);
        }
        string st;
        st.append(n, '.');
        v.push_back(st);
        return v;
    }
};