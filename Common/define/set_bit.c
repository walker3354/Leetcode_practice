#define SET_BIT(REG, n) ((REG) |= 1U << (n))

#define CLEAR_BIT(REG, n) ((REG) &= ~(1U << (n)))

#define TOGGLE_BIT(REG, n) ((REG) ^= 1U << (n))

#define CHECK_BIT(REG, n) ((REG) & (1U << (n)))