//? 1. Reverse the string and compare it with the original string
//! TC: O(n) SC: O(1)

//? 2. Use two pointers to compare the characters from start and end of the string
//! TC: O(n) SC: O(1)
// https://leetcode.com/problems/valid-palindrome/submissions/1286457918

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size()-1;
    
    while (i<j) {
        while (!isalnum(s[i]) && i < j) {
            i++;
        }
        while (!isalnum(s[j]) && i < j) {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}