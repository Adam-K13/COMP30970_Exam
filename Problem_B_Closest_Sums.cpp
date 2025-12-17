#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> all_sums(vector<int> set_of_numbers) {
    vector<int> resulting_sums;
    for(int i = 0; i < set_of_numbers.size() -1; i++) {
        for(int j = i+1; j < set_of_numbers.size(); j++) {
            int new_sum = set_of_numbers[i] + set_of_numbers[j];
            resulting_sums.push_back(new_sum);
        }
    }
    return resulting_sums;
}

int binarySearch(vector<int> all_sums, int x) {
    int low = 0;
    int high = all_sums.size() - 1;
    while (low <= high) {
        int mid = low + ((high - low) / 2);

        if (all_sums[mid] == x)
            return mid;

        if (all_sums[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return low;
}


int main() {   
    int num_numbers;  
    int i = 1;
    while(cin >> num_numbers) {
        cout << "Case " << i << ":\n";
        vector<int> set_of_numbers;
        int new_number;
        for(int i = 0; i < num_numbers; i++) {
            cin >> new_number;
            set_of_numbers.push_back(new_number);
        }
        
        vector<int> sums = all_sums(set_of_numbers);
        sort(sums.begin(), sums.end());
        for(int j = 0; j < sums.size(); j++) {
            cout << sums[j] << " ";
        }
        cout << "\n";
            
        int num_queries;
        cin >> num_queries;

        for(int i = 0; i < num_queries; i++) {
            int query_num;
            cin >> query_num;
            int new_result = binarySearch(sums, query_num); 
            cout << "Closest sum to " << query_num << " is " << sums[new_result] << ".\n"; 
        }
        i++;
    }

    return 0;
}