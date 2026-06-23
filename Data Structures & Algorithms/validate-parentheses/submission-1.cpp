class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        unordered_map<char, char> match;
        match[')'] = '(';
        match[']'] = '[';
        match['}'] = '{';

        for (char e : s) {
            if (match.find(e) != match.end()) {
                if (stk.empty() || stk.top() != match[e]) return false;
                else stk.pop();
            } else {
                stk.push(e);
            }
        }

        return stk.empty();
    }
};
