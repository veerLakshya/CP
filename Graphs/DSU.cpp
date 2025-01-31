#include <iostream>
#include <vector>
#include <numeric> // For iota
using namespace std;

// Union Find Template
class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }
    
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

// *PROBLEMS for DSU* -
// https://codeforces.com/contest/151/problem/D
