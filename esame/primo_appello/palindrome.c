_Bool isPalindrome(const char *s, int first, int last) {
    while (first < last) {
        if (s[first] != s[last]) {
            return 0;
        }
        first++;
        last--;
    }
    return 1;
}
