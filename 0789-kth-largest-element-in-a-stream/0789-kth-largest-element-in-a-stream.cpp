class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>>q;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto&it:nums) {
            q.push(it);
            if(q.size()>K)q.pop();
        }
    }

    int add(int val) {
        q.push(val);
        if(q.size()>K)q.pop();
        return q.top();
    }
};