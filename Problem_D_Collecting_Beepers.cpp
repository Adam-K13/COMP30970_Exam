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

pair<int, pair<int,int> > find_shortest(pair<int,int> starting_position, vector<pair<int, pair<int, int> > > locations) {
    vector<pair<int, pair<int,int> > > distances;

    for(int i = 0; i < locations.size(); i++) {
        int distance = manhattan_dist(starting_position, locations[i].second);
        distances.push_back(make_pair(distance, locations[i].second));   
    }
    sort(distances.begin(), distances.end());
    return distances[1];
}

int find_path(pair<int,int> starting_position, vector<pair<int, pair<int, int> > >  locations) {
    for(int i = 0; i < locations.size(); i++) {
        pair<int, pair<int,int> > shortest = find_shortest(locations[i].second, locations);
        cout << shortest.first << ": " << shortest.second.first << " " << shortest.second.first;
        cout << "\n";
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