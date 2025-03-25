class Solution {
    static bool cmp1(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // Sort by start_y in ascending order
    }

    static bool cmp2(vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; // Sort by start_x in ascending order
    }

public:
    bool find(int n, vector<vector<int>>& rectangles) {
        int regions = 0;
        int prev = rectangles[0][1] + 1;

        for (vector<int>& rectangle : rectangles) {
            if (rectangle[1] < prev) {
                prev = max(prev, rectangle[3]);
            } else {
                regions++;
                if (prev > n) return false;
                prev = rectangle[3];
            }

            if (regions == 2) return true;
        }

        return regions == 2;
    }

    bool find2(int n, vector<vector<int>>& rectangles) {
        int regions = 0;
        int prev = rectangles[0][0] + 1;

        for (vector<int>& rectangle : rectangles) {
            if (rectangle[0] < prev) {
                prev = max(prev, rectangle[2]);
            } else {
                regions++;
                if (prev > n) return false;
                prev = rectangle[2];
            }

            if (regions == 2) return true;
        }

        return regions == 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), cmp1);
        if (find(n, rectangles)) return true;

        sort(rectangles.begin(), rectangles.end(), cmp2);
        return find2(n, rectangles);
    }
};
