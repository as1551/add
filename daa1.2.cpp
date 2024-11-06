#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int numItems) {
    // Create a 2D array `dp` to store the maximum value at each subproblem
    vector<vector<int>> dp(numItems + 1, vector<int>(capacity + 1, 0));

    // Fill the dp array
    for (int i = 1; i <= numItems; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weights[i - 1] <= j) {
                // Item can be included or excluded; choose the option with the higher value
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                // Item can't be included, so carry forward the previous value
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The maximum value obtainable with the given capacity and items
    return dp[numItems][capacity];
}

int main() {
    int capacity, numItems;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<int> weights(numItems), values(numItems);
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < numItems; ++i) {
        cin >> weights[i];
    }
    cout << "Enter the values of the items: ";
    for (int i = 0; i < numItems; ++i) {
        cin >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values, numItems);
    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}

