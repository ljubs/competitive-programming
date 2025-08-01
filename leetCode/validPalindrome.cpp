class Solution {
public:
    char lower(char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }

    bool isChar(char c) {
        if ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) return true;
        return false;
    }

    bool isPalindrome(string s) {
        int left, right;
        left = 0;
        right = s.size() - 1;
        while (left <= right) {
            if (!isChar(s[left])) {
                left++;
                continue;
            }
            if (!isChar(s[right])) {
                right--;
                continue;
            }
            if (lower(s[left]) != lower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};