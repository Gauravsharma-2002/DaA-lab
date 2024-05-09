#include <iostream>
#include <vector>
using namespace std;
vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
void findMinCoins(int V) {
    int n = denominations.size();
    int count = 0;
    cout << "Minimum number of coins/notes needed for change of " << V << " Rs.:\n";
    // Iterate through denominations
    for (int i = 0; i < n; ++i) {
        // Find the maximum number of coins/notes of current denomination that can be used
        int coins = V / denominations[i];
        // Update the count of coins/notes
        count += coins;
        // Update the remaining value
        V -= coins * denominations[i];

        // Print the count of current denomination if it's used
        if (coins > 0) {
            cout << denominations[i] << " Rs. x " << coins << endl;
        }

        // If remaining value becomes 0, break the loop
        if (V == 0)
            break;
    }

    cout << "Total number of coins/notes: " << count << endl;
}

int main() {
    int V = 2067775; 

    findMinCoins(V);

    return 0;
}
