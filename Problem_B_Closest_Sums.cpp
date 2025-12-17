#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<int> all_sums(vector<int> set_of_numbers) {
    set<int> resulting_sums;
    for(int i = 0; i < set_of_numbers.size() -1; i++) {
        for(int j = i+1; j < set_of_numbers.size() -1; j++) {
            int new_sum = set_of_numbers[i] + set_of_numbers[j];
            resulting_sums.insert(new_sum);
        }
    }
    return resulting_sums;
}


int main() {
    int num_cases;
    cin >> num_cases;

    for(int c =0; c< num_cases; c++) {
        int num_numbers;
        vector<int> set_of_numbers;
        
        cin >> num_numbers;
        int new_number;
        for(int i = 0; i < num_numbers; i++) {
            cin >> new_number;
            set_of_numbers.push_back(new_number);
        }
        set<int> sums = all_sums(set_of_numbers);
        
        int num_queries;
        cin >> num_queries;

        for(int i = 0; i < num_queries; i++) {
            int query_num;
            cin >> query_num;
            
        }
    }

    return 0;
}