#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Helper function to count valid pairs in a string
int count_pairs(const string& s) {
    int pairs = 0;
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (!st.empty()) {
                st.pop();
                pairs++;
            }
        }
    }
    return pairs;
}

void solve_n_shifted_greedy(string s, int k) {
    int n = s.length();
    int min_pairs = n; 
    string best_string = s;

    // 1. Precalculate initial absolute pairs globally
    stack<int> st;
    vector<int> pair_partner(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                int open_idx = st.top();
                st.pop();
                pair_partner[open_idx] = i;
                pair_partner[i] = open_idx;
            }
        }
    }

    // 2. Run the greedy strategy N times, changing the entry point node
    for (int start = 0; start < n; start++) {
        vector<bool> deleted(n, false);
        int current_k = k;

        // Pass 1: Target opening brackets that belong to a pair, starting from 'start'
        for (int step = 0; step < n; step++) {
            int i = (start + step) % n;
            if (s[i] == '(' && pair_partner[i] != -1 && current_k > 0) {
                deleted[i] = true;
                current_k--;
            }
        }

        // Pass 2: Fill remaining budget with whatever is left, starting from 'start'
        for (int step = 0; step < n; step++) {
            int i = (start + step) % n;
            if (!deleted[i] && current_k > 0) {
                deleted[i] = true;
                current_k--;
            }
        }

        // Reconstruct string for this specific run
        string temp = "";
        for (int i = 0; i < n; i++) {
            if (!deleted[i]) temp += s[i];
        }

        // Keep track of the absolute minimum pairs found across all starting nodes
        int current_pairs = count_pairs(temp);
        if (current_pairs < min_pairs) {
            min_pairs = current_pairs;
            best_string = temp;
        }
    }

    cout << "Best String Found:   " << best_string << "\n";
    cout << "Minimum Pairs Found: " << min_pairs << "\n";
}

int main() {
    // Testing against the cascade counterexample
    string s = "(( )";
    int k = 1;
    cout << "Testing String: " << s << " | k = " << k << "\n";
    solve_n_shifted_greedy(s, k);
    return 0;
}