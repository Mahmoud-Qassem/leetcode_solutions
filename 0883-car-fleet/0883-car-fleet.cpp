class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        struct car{
            int position, speed;
        };
        
        int n=position.size();
        vector<car>cars;
        for(int i=0;i<n;++i){
            cars.push_back(car{position[i],speed[i]});
        }
                auto compare=[](car&toyota, car&bmw){
             return toyota.position>bmw.position;
        };

        sort(cars.begin(),cars.end(),compare);

        vector<float>finishTime;
        for(car&c:cars){
            finishTime.push_back( (target-c.position)/(float)c.speed );
        }

        int fleets=n;
        float last=finishTime[0];
        
        for(int i=1;i<n;++i){
            if(finishTime[i]-last>0){
                last=finishTime[i];
            }
            else fleets--;
        }
        return fleets;
    }
};