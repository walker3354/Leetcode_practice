#include <math.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int lowest_index = 0;
    int highest_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < prices[lowest_index]) {
            lowest_index = i;
        }
        if (prices[i] > prices[lowest_index]) {
            highest_profit =
                fmax(prices[i] - prices[lowest_index], highest_profit);
        }
    }
    return highest_profit;
}