#include <iostream>
#include <vector>
#include <climits>

#define MAX_CITIES 10

using namespace std;

int graph[MAX_CITIES][MAX_CITIES];
int num_cities;
vector<int> optimal_path(MAX_CITIES);
vector<bool> visited(MAX_CITIES, false);
int optimal_cost = INT_MAX;

void tsp_lc_bb(int node, int depth, int cost) {
    visited[node] = true;
    optimal_path[depth] = node;

    // If all cities have been visited, add the cost to return to the start city
    if (depth == num_cities - 1) {
        cost += graph[node][0];  // Add cost of returning to the starting city

        if (cost < optimal_cost) {
            optimal_cost = cost;

            // Copy the optimal path
            for (int i = 0; i < num_cities; i++) {
                optimal_path[i] = optimal_path[i];
            }
        }
    } else {
        // Try visiting all unvisited cities
        for (int i = 0; i < num_cities; i++) {
            if (!visited[i]) {
                int new_cost = cost + graph[node][i];

                // Proceed only if the new cost is less than the current optimal cost
                if (new_cost < optimal_cost) {
                    tsp_lc_bb(i, depth + 1, new_cost);
                }
            }
        }
    }

    visited[node] = false;  // Mark this city as unvisited for other paths
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> num_cities;

    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {
            cin >> graph[i][j];
        }
    }

    // Start the recursive Branch and Bound function from the starting city (node 0)
    tsp_lc_bb(0, 0, 0);

    // Output the optimal path and cost
    cout << "Optimal Path: ";
    for (int i = 0; i < num_cities; i++) {
        cout << optimal_path[i] << " ";
    }
    cout << "0\n";  // Return to the starting city

    cout << "Optimal Cost: " << optimal_cost << endl;

    return 0;
}

