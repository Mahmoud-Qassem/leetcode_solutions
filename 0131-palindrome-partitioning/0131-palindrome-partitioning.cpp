#define all(s) (s).begin(),(s).end()
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        for (int i = 0; i < (pow(2, n - 1)); i++) { ///
            bitset<16> X(i);
            string bts = X.to_string();
            reverse(all(bts));
            string tmp;
            char c = bts[0];
            tmp += s[0];
            vector<string> subs;
            for (int j = 1; j < n; ++j) {

                if (bts[j] == c) {
                    tmp += s[j];
                } else {
                    subs.push_back(tmp);
                    tmp = "";
                    tmp += s[j];
                    c = bts[j];
                }
            }

            subs.push_back(tmp);
            bool notAllOfThemArePalind = 1;
            for (auto& it : subs) {
                int sz = it.size();
                for (int k = 0; k < (sz / 2); k++) {
                    if (it[k] != it[sz - k - 1]) {
                        notAllOfThemArePalind = 0;
                        break;
                    }
                }
            }
            if (notAllOfThemArePalind)
                ans.push_back(subs);
        }

        return ans;
    }
};