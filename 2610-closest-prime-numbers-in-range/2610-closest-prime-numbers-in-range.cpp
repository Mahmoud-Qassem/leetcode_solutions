
class Solution {
public:
    const int MAX=1e6+5;
    vector<int>primes;
    Solution() {
        vector<bool>isprime(MAX);

        for (int i = 0; i < MAX; ++i)
            isprime[i] = 1;
        isprime[0] = isprime[1] = 0;

        for (int i = 2; i * i < MAX; ++i) {
            if (isprime[i]) {

                for (int j = i * 2; j < MAX; j += i)
                    isprime[j] = 0;
            }
        }
        for (int i = 0; i < MAX; ++i)
            if (isprime[i])
                primes.push_back(i);
    }

    vector<int> closestPrimes(int left, int right) {
        int a = -1, b = -1;
        int a_idx=lower_bound(primes.begin(),primes.end(),left)-primes.begin();
        int b_idx=upper_bound(primes.begin()+a_idx+1,primes.end(),right)-primes.begin();
        
        int diff=INT_MAX;
        for(int i=a_idx;i<b_idx-1;++i){
            //cout<<primes[i]<<" ";
            if(primes[i+1]-primes[i]<diff){
                diff=primes[i+1]-primes[i];
                a=primes[i];
                b=primes[i+1];
            }
        }
        return {a, b};
    }
};