#include <stdio.h>

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


//2,4,1
int maxProfit(int* prices, int pricesSize) {
    int profit, minLeft, maxRight, maxIndex, minIndex, maxProfit;
    minLeft = prices[0];
    maxRight = prices[0];
    maxIndex = 0;
    minIndex = 0;
    maxProfit = 0; 
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < minLeft){
            minLeft = prices[i];
            minIndex = i;
        }
        if(prices[i] > maxRight || minIndex > maxIndex){
            maxRight = prices[i];
            maxIndex = i;
        }
        profit = maxRight - minLeft;
        if(profit > maxProfit){
            maxProfit = profit;
        }
    }
    return maxProfit;
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int prices[] = {2, 4, 1};
    int result = maxProfit(prices, sizeof(prices)/4);
    printArray(prices, sizeof(prices)/4);
    printf("%d\n", result);

}
