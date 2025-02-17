class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> st;
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        do {
            for (int i = 0; i < (1 << n); ++i) {
                int msk = i;
                string s;
                for (int j = 0; j < n; ++j, msk /= 2) {
                    if (msk % 2)
                        s += tiles[j];
                }
                st.insert(s);
            }

        } while (next_permutation(tiles.begin(), tiles.end()));
        for(auto&it:st)cout<<it<<" ";cout<<endl;
        return (int)st.size()-1;
    }
};