int reverseBits(int n) {
    unsigned int result = 0;

    for (int i = 0; i < 32; i++) {
        int bit = 0;
        if (((1U << (31 - i)) & n) != 0) {
            bit = 1;
        }
        result |= (bit << i);
    }
    return (int)result;
}
