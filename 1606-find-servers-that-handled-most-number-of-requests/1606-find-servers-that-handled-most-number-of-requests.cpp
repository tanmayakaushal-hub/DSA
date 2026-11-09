class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        using t=tuple<int,int>;
        set<int> st;//free server indices
        priority_queue<t,vector<t>,greater<>> pq;//end time,server index
        vector<int> busy(k,0);
        for(int i=0;i<k;i++) st.insert(i);
        for(int i=0;i<arrival.size();i++)
        {
            int req_id=i;
            int startTime=arrival[i],endTime=startTime+load[i];


            while(!pq.empty() && get<0>(pq.top())<=startTime)
            {
                auto [eTime,id]=pq.top();
                pq.pop();
                st.insert(id);
            }
            if(st.size()==0) continue;//drop the request
            auto it=st.lower_bound(req_id%k);
            int serverid;
            if(it==st.end()) serverid=*st.begin();
            else serverid=*it;
            pq.push({endTime,serverid});
            st.erase(serverid);
            busy[serverid]++;
        }
        int maxi=*max_element(busy.begin(),busy.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            if(busy[i]==maxi) ans.push_back(i);
        }
        return ans;
    }
};