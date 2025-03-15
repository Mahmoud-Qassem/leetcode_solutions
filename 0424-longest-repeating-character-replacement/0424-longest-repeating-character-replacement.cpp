class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, left = 0, right = 0,mx=0;
        vector<int> frq(26);
        while (left < n) {
            while (right < n) {
                frq[s[right++] - 'A']++;
                mx=max(mx,frq[s[right-1] - 'A']);
                if ((right - left) - mx <= k)
                    ans = max(ans, right - left);
                else
                    break;
            }
            frq[s[left++] - 'A']--;
        }
        return ans;
    }
};
