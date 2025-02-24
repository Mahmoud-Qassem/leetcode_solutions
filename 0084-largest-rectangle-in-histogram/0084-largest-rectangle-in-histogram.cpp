#define sz(s) (int)(s.size())
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> st;
        int maxArea = 0, area = 0, i = 0;
        while (i < sz(v)) {
            if (st.empty() || v[st.top()] <= v[i])
                st.push(i++);
            else {
                int top = st.top();
                st.pop();
                if (st.empty())
                    area = v[top] * i;
                else
                    area = v[top] * (i - st.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (st.empty())
                area = v[top] * i;
            else
                area = v[top] * (i - st.top() - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
