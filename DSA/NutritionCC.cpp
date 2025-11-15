/*Nutrition Cost
There are N different food items, each providing an essential vitamin Ai and costing Bi. 
There is an integer parameter C which represents the value of a single vitamin to you.
You will buy some of the food items to maximize C⋅X−Y (C multiplied by X minus Y), where 
X represents the number of distinct vitamins eaten, and Y represents the total cost of all the food items. Find this maximum possible value.
 It is also possible to buy no food item at all, in which case the answer is simply 
0.
$ Input Format:
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.The first line of each test case contains N and C - the number of food items and the value of a vitamin.
The second line contains N integers -A1,A2,…,AN.The third line contains N integers-B1,B2,…,BN.
$ Output Format:
For each test case, output on a new line the maximum possible value of C⋅X − Y as explained in the statement.
*/
#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For dynamic arrays (vectors A and B)
#include <map>      // For std::map to store min_costs for each vitamin type
#include <algorithm> // For std::min (to find the minimum cost)
#include <climits>   // For LLONG_MAX (not strictly needed here as map handles initial value)

void solve() {
    int N;       // Number of food items
    long long C; // Value of a single vitamin
    std::cin >> N >> C;

    std::vector<int> A(N); // Array for vitamin types
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> B(N); // Array for costs
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    // std::map<int, long long> min_costs;
    // This map will store: key = vitamin_type, value = minimum_cost_to_get_this_vitamin
    // We use long long for costs because B_i can be up to 10^9, and min_costs values
    // could potentially be large (though individual B_i are just long long, it's good practice).
    std::map<int, long long> min_costs;

    // Step 1: Process all food items to find the minimum cost for each distinct vitamin
    for (int i = 0; i < N; ++i) {
        int vitamin_type = A[i];
        long long cost = B[i];

        // The 'find' method checks if a key exists in the map.
        // If it doesn't exist (returns map.end()), then this is the first time we see this vitamin.
        if (min_costs.find(vitamin_type) == min_costs.end()) {
            min_costs[vitamin_type] = cost; // Store the cost for this new vitamin type.
        } else {
            // If the vitamin type already exists in the map,
            // update its stored minimum cost if the current 'cost' is smaller.
            min_costs[vitamin_type] = std::min(min_costs[vitamin_type], cost);
        }
    }

    // Step 2: Calculate the maximum possible value (C*X - Y)
    long long max_value = 0; // Start with 0, representing the option of buying nothing.

    // Iterate through each unique vitamin and its minimum cost stored in the map.
    // 'auto const& [vitamin_type, min_cost_for_this_vitamin]' is C++17 structured binding
    // It's a concise way to iterate through map key-value pairs.
    for (std::pair<const int, long long> const& entry : min_costs) {
    int vitamin_type = entry.first;
    long long min_cost_for_this_vitamin = entry.second;
        // Calculate the net gain (C * 1 - cost) for acquiring this distinct vitamin.
        long long current_gain = C - min_cost_for_this_vitamin;

        // If the net gain is positive, it means acquiring this vitamin improves our total score.
        // So, we add this gain to our overall maximum value.
        if (current_gain > 0) {
            max_value += current_gain;
        }
        // If current_gain is 0 or negative, we don't gain anything or we lose.
        // So, we simply don't acquire this particular vitamin.
        // This is implicitly handled by not adding to max_value.
    }

    // Output the final maximum possible value.
    std::cout << max_value << std::endl;
}

int main() {
    // These two lines optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) unties cin from cout, so cin doesn't flush cout before reading.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) { // Loop for each test case
        solve();
    }
    return 0;
}