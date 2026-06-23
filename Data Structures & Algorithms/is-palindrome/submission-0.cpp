class Solution {
public:
    bool isPalindrome(string s) {
        string flat;

        for (char e : s) {
            if (isalnum(e)) {
                flat += tolower(e);
            }
        }

        for (int i = 0; i < flat.size() / 2; ++i) {
            if (flat[i] != flat[flat.size() - i - 1]) return false;
        }

        return true;
    }
};
