#include<bits/stdc++.h>
using namespace std;

struct State {
    int cat, mouse, who;
    bool operator <(const State& b) const {
        return tie(cat, mouse, who)
            <  tie(b.cat, b.mouse, b.who);
    }
};

const int CAT = 0;
const int MOUSE = 1;
map<State, bool> winner; // arr[n][n][2]
map<State, int> out;

vector<vector<int>> graph;
vector<int> cat_degree;

bool decided(State state) {
    return state.mouse == state.cat || state.mouse == 0 || state.cat == 0;
}

void rec(State state, bool result) {
  
    if(winner.count(state)) {
        assert(winner[state] == result);
        return;
    }
    winner[state] = result;
    if(state.who == MOUSE) {
        // CAT moved previously
        for(int prev_cat : graph[state.cat]) {
            State prev_state{prev_cat, state.mouse, CAT};
            if(decided(prev_state)) {
                continue;
            }
            if(result == CAT) {
                rec(prev_state, CAT);
            }
            else {
                if(++out[prev_state] == cat_degree[prev_cat]) {
                    rec(prev_state, MOUSE);
                }
            }
        }
    }
    else {
        // MOUSE moved previously
        for(int prev_mouse : graph[state.mouse]) {
            State prev_state{state.cat, prev_mouse, MOUSE};
            if(decided(prev_state)) {
                continue;
            }
            if(result == MOUSE) {
                rec(prev_state, MOUSE);
            }
            else {
                if(++out[prev_state] == (int) graph[prev_mouse].size()) {
                    rec(prev_state, CAT);
                }
            }
        }
    }
}

int catMouseGame(vector<vector<int>> _graph) {
    winner.clear();
    out.clear();
    graph = _graph;
    int n = graph.size();
    cat_degree = vector<int>(n);
    for(int a = 0; a < n; ++a) {
        cat_degree[a] = graph[a].size();
        for(int b : graph[a]) {
            if(b == 0) {
                cat_degree[a]--;
            }
        }
    }
    for(int cat = 1; cat < n; cat++) {
        for(int who : {0, 1}) {
            rec({cat, 0, who}, MOUSE);
            rec({cat, cat, who}, CAT);
        }
    }
    State start{2, 1, MOUSE};
    if(winner.count(start)) {
        if(winner[start] == MOUSE) {
            return 1;
        }
        return 2;
    }
    return 0;
}