#include <bits/stdc++.h>
using namespace std;

class Metro {
    map<string, vector<pair<string, int>>> adj;

public:
    void addStation(string u, string v, int dist) {
        adj[u].push_back({v, dist});
        adj[v].push_back({u, dist});
    }

    void shortestPath(string src, string dest) {
        map<string, int> dist;
        map<string, string> parent;

        for (auto &i : adj) {
            dist[i.first] = INT_MAX;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto &nbr : adj[node]) {
                string next = nbr.first;
                int weight = nbr.second;

                if (d + weight < dist[next]) {
                    dist[next] = d + weight;
                    parent[next] = node;
                    pq.push({dist[next], next});
                }
            }
        }

        // Print path
        vector<string> path;
        string temp = dest;

        while (temp != src) {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        cout << "\n🚇 Shortest Route:\n";
        for (auto &station : path) {
            cout << station << " -> ";
        }
        cout << "END\n";

        cout << "Total Distance: " << dist[dest] << " km\n";
    }
};

int main() {
    Metro dm;

    // Sample Delhi Metro stations (simplified)
    dm.addStation("Dwarka Sec-21", "Rajiv Chowk", 20);
    dm.addStation("Rajiv Chowk", "Mandi House", 5);
    dm.addStation("Mandi House", "Yamuna Bank", 6);
    dm.addStation("Yamuna Bank", "Noida Sec-15", 10);
    dm.addStation("Rajiv Chowk", "Kashmere Gate", 7);
    dm.addStation("Kashmere Gate", "Dilshad Garden", 15);

    string src, dest;

    cout << "Enter Source Station: ";
    getline(cin, src);

    cout << "Enter Destination Station: ";
    getline(cin, dest);

    dm.shortestPath(src, dest);

    return 0;
}
