#include "RouteCalculator.h"

void RouteCalculator::shortestPath(MetroData &metro, string src, string dest) {
    map<string, int> dist;
    map<string, string> parent;

    for (auto &i : metro.adj) {
        dist[i.first] = INT_MAX;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        for (auto &nbr : metro.adj[node]) {
            string next = nbr.first;
            int weight = nbr.second;

            if (d + weight < dist[next]) {
                dist[next] = d + weight;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }

    // Path print
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
