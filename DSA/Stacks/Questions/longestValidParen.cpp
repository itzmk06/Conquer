#include <bits/stdc++.h>
class Solution {
public:
    stack<int> st;
    int longestValidParentheses(string s) {
        int maxLength = 0;
        st.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    int len = i - st.top();
                    maxLength = max(maxLength, len);
                }
            } else {
                return maxLength;
            }
        }
        return maxLength;
    }
};