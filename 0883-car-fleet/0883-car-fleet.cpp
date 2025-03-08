class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double>dist;
        int n=position.size();
        vector<pair<int,int>>combine;

        for(int i=0;i<n;++i){
            combine.push_back({position[i],speed[i]});
        }
        sort(combine.rbegin(), combine.rend());

        for(int i=0;i<n;++i){
            dist.push_back( (target-combine[i].first)/(double)combine[i].second );
        }
        for(auto&it:dist)cout<<it<<" ";
        cout<<endl;
        int groups=n;
        double last=dist[0];

        for(int i=1;i<n;++i){
            if(dist[i]-last>0){
                last=dist[i];
            }
            else groups--;
        }
        return groups;
    }
};
