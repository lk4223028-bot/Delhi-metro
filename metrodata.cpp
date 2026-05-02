#include "MetroData.h"

void MetroData::addConnection(string u, string v, int dist) {
    adj[u].push_back({v, dist});
    adj[v].push_back({u, dist});
}

vector<string> MetroData::getStations() {
    vector<string> stations;
    for (auto &i : adj) {
        stations.push_back(i.first);
    }
    return stations;
}
