class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int m = v.size();
        if (m == 1 and n and v[0])
            return 0;
        else if (m == 1)
            return 1; 

        for (int i = 0; i < m and n; ++i) {
            if (!v[i]) {
                if (!i and !v[i + 1]) {
                    v[i] = 1;
                    n--;
                }
                else if (i and !v[i - 1] and i == m - 1) {
                    v[i] = 1;
                    n--;
                } else if (i and i < m - 1 and !v[i - 1] and !v[i + 1]) {
                    v[i] = 1;
                    n--;
                }
            }
        }
        return !n;
    }
};