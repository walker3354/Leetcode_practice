int reverseBits(int n) {
    unsigned int result = 0;

    for (int i = 0; i < 32; i++) {
        if ((n & (1U << i)) != 0) {
            result |= (1U << (31 - i));
        }
    }
    return (int)result;
}

int better_soulation(int n) {
    // 1 bit exchange
    // 2 bit exchange
    // 4 bit exchange
    // 8 bit exchange
    // 16bit exchange
    n = ((n & (0x55555555U)) << 1) | ((n & (0xAAAAAAAAU)) >> 1);
    n = ((n & (0x33333333U)) << 2) | ((n & (0xCCCCCCCCU)) >> 2);
    n = ((n & (0x0F0F0F0FU)) << 4) | ((n & (0xF0F0F0F0U)) >> 4);
    n = ((n & (0x00FF00FFU)) << 8) | ((n & (0xFF00FF00U)) >> 8);
    n = ((n & (0x0000FFFFU)) << 16) | ((n & (0xFFFF0000U)) >> 16);
    return n;
}