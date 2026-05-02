#ifndef METRODATA_H
#define METRODATA_H

#include <bits/stdc++.h>
using namespace std;

class MetroData {
public:
    map<string, vector<pair<string, int>>> adj;

    void addConnection(string u, string v, int dist);
    vector<string> getStations();
};

#endif
