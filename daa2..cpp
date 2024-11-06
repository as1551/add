#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        const int INF = 999; // Using 999 as "infinity"
        vector<int> dist(V, INF);
        dist[S] = 0; // Distance from source to itself is 0

        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                int u = edge[0]; // Starting vertex
                int v = edge[1]; // Ending vertex
                int wt = edge[2]; // Weight of the edge

                // Relaxation step
                if (dist[u] < INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
      

        return dist; // Return the distances from source to all vertices
    }
};

int main() {
    int V, E, S;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3)); // Vector to hold edges
    cout << "Enter edges (u v weight): " << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; // Input each edge
    }

    cout << "Enter source vertex: ";
    cin >> S;

    Solution obj;
    vector<int> dist = obj.bellman_ford(V, edges, S);

    cout << "Distances from source: ";
    for (int d : dist) {
        cout << (d == 999 ? "INF" : to_string(d)) << " "; // Print INF for unreachable
    }
    cout << endl;

    return 0;
}

