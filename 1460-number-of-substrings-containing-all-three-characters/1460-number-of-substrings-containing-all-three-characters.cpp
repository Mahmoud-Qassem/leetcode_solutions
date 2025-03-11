class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, ans=0;
        int n = s.size();
        int a = 0, b = 0, c = 0;
        while (left < n) {
            while (right < n and !(a && b && c)) {
                if (s[right] == 'a')
                    a++;
                else if (s[right] == 'b')
                    b++;
                else
                    c++;
                right++;
            }
            if (a && b && c)
                ans += n - right+1;
            if (s[left] == 'a')
                a--;
            else if (s[left] == 'b')
                b--;
            else
                c--;
            left++;
        }
        return ans;
    }
};