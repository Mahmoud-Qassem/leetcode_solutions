class Solution {
public:
    string minWindow(string big, string small) {
        int n = big.size(), m = small.size();
        if (n < m)
            return "";

        vector<int> crnt(128), fixed(128);
        int cnt=0;
        for (char c : small){
            if(not fixed[c])cnt++;
            fixed[c]++;
        }

        int left = 0, right = 0, ans = INT_MAX, x = -1, y = -1;
        int balanced=0;

        while (right < n) {
            crnt[big[right]]++;
            if( fixed[ big[right] ] and fixed[ big[right] ]-crnt[big[right]] ==0)balanced++;
            right++;

            while (left < n and fixed[big[left]] < crnt[big[left]]) {
                crnt[big[left]]--;
                if( fixed[ big[left] ] and fixed[ big[left] ]-crnt[big[left]] ==1)balanced--;
                left++;
            }

            if (ans > right - left + 1 and balanced==cnt) {
                x = left, y = right, ans = right - left + 1;
            }
        }
        if (x != -1)
            return big.substr(x, y - x);
        return "";
    }
};