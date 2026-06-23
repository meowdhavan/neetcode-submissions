class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char e : s) {
            if (e == ')') {
                if (stk.empty() || stk.top() != '(') {
                    return false;
                } else {
                    stk.pop();
                }
            } else if (e == ']') {
                if (stk.empty() || stk.top() != '[') {
                    return false;
                } else {
                    stk.pop();
                }
            } else if (e == '}') {
                if (stk.empty() || stk.top() != '{') {
                    return false;
                } else {
                    stk.pop();
                }
            } else {
                stk.push(e);
            }
        }

        return stk.empty();
    }
};
