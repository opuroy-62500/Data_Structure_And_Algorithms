#include<iostream>
#include<algorithm>
using namespace std;

// Structure to represent an item with profit and weight
struct Item {
    int profit;
    int weight;
};

// Comparison function to sort items by profit/weight ratio in descending order
bool compareItems(Item a, Item b) {
    double ratio1 = (double)a.profit / (double)a.weight;
    double ratio2 = (double)b.profit / (double)b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // 1 & 2. Compute ratio and sort items in decreasing order of ratio
    sort(arr, arr + n, compareItems);

    // 3. Initialize profit
    double finalProfit = 0.0;

    // 4. Loop through each item
    for (int i = 0; i < n; i++) {
        
        // If the item can completely fit in the remaining capacity
        if (arr[i].weight <= W) {
            finalProfit += arr[i].profit;
            W -= arr[i].weight;
        } 
        // If the item cannot fit completely, take a fraction of it
        else {
            double fraction = (double)W / (double)arr[i].weight;
            finalProfit += arr[i].profit * fraction;
            break; // The knapsack is now full
        }
    }

    // 5. Return the total accumulated profit
    return finalProfit;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    Item arr[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].weight;
    }
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].profit;
    }
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum profit = " << fractionalKnapsack(W, arr, n) << endl;
}