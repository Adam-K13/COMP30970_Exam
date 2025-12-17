//dijkstra to find shortest path from each to every other node
//sum of costs from start to next then to next closest untill all beepers reached
//from the last beeper back = total cost

#include <iostream>
#include <algorithm>
using namespace std;

int manhattan_dist(pair<int,int> pos_x , pair<int,int> pos_y) {
    int x1 = pos_x.first;
    int x2 = pos_x.second;
    int y1 = pos_y.first;
    int y2 = pos_y.second;

    return abs(x2 - x1) + abs(y2 - y1);
}

pair<int, pair<int,int> >  find_shortest(pair<int,int> starting_position, vector<pair<int, pair<int, int> > > locations) {
    vector<pair<int, pair<int,int> > > distances;

    for(int i = 0; i < locations.size(); i++) {
        for(int j = 0; j < locations.size(); j++) {
            int distance = manhattan_dist(locations[i].second, locations[j].second);
            distances.push_back(make_pair(distance, locations[j].second));
        }
    }
    sort(distances.begin(), distances.end());
    return distances[1];
}

int find_path(pair<int,int> starting_position, vector<pair<int, pair<int, int> > >  locations) {
    for(int i = 0; i < locations.size(); i++) {
        pair<int, pair<int,int> >  adj = find_shortest(starting_position, locations);
        cout << adj.first << ":" << adj.second.first << " " << adj.second.second << "\n"; 
    } 
}


int main() {
    int num_cases;
    cin >> num_cases;
    for(int c = 0; c < num_cases; c++) {
        pair<int,int> grid_size;
        cin >> grid_size.first >> grid_size.second;

        pair<int,int> starting_position;
        vector<pair<int, pair<int,int> > > beeper_locations;
        cin >> starting_position.first >> starting_position.second;
        beeper_locations.push_back(make_pair(0, starting_position));

        int num_beepers;
        cin >> num_beepers;
        for(int i = 0; i < num_beepers; i++) {
            pair<int, int> new_beeper;
            cin >> new_beeper.first >> new_beeper.second;
            beeper_locations.push_back(make_pair(i + 1, new_beeper));
        }

        for(int i = 0; i < beeper_locations.size(); i++) {
            cout << beeper_locations[i].second.first << " " << beeper_locations[i].second.second << "\n";
        }
        cout << "\n";

        int result = find_path(starting_position, beeper_locations);
        cout << result << "\n";
    }

    return 0;
}