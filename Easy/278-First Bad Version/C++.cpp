class Solution {
    public:
        bool isBadVersion(int version); // already define(bad = return false)

        int firstBadVersion(int n) { // 1~n
            if (n == 1) return 1;
            int left = 1;
            int right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (isBadVersion(mid) == true) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

        int bad_method(int n) { // 1~n
            for (int i = 1; i <= n; i++) {
                if (isBadVersion(i) == false) return i;
            }
            return -1;
        }
};