class Solution {
public:
    vector<int> constructDistancedSequence(int n) {

        vector<int> ans, done(n + 1), crnt(2 * n - 1);

        auto rec = [&](auto rec, int idx, int ok = 0) -> bool {
            if (ok == 2 * n - 1) {
                ans = crnt;
                return true;
            }
            if (idx >= 2 * n - 1)
                return false;
            if (crnt[idx])
                return rec(rec, idx + 1, ok);

            int cnt = 0;
            for (int i = n; i >= 1; --i) {
                if (i == 1) {
                     if (not done[i]) {
                        done[i] = 1;
                        crnt[idx] = i;
                        if (rec(rec, idx + 1, ok + 1)) {
                            return true;
                        }
                        crnt[idx] = 0;
                        done[i] = 0;
                    }
                } else {
                    if (not done[i] and i + idx < 2 * n - 1 and
                        crnt[i + idx] == 0) {
                        done[i] = 1;
                        crnt[idx] = crnt[i + idx] = i;
                        if (rec(rec, idx + 1, ok + 2)) {
                            return true;
                        }
                        crnt[idx] = crnt[i + idx] = 0;
                        done[i] = 0;
                    }
                }
            }
            if (ans.size())
                return true;
            return false;
        };
        rec(rec, 0);
        return ans;
    }
};