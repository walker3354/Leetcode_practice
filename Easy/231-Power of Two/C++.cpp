class Solution {
    public:
        bool isPowerOfTwo(int n) { return (n > 0) && (n & (n - 1) == 0); }

        bool bad_method(int n) {
            if (n == 1) return true;
            if (n % 2 != 0 || n == 0) return false;

            while (true) {
                n /= 2;
                if (n == 1) {
                    return true;
                } else if (n % 2 != 0) {
                    return false;
                }
            }
        }
};