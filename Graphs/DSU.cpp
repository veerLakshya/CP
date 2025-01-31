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

int main() {
    int n = 5; // Number of elements
    UnionFind uf(n);
    
    cout << "Initially, all elements are separate sets." << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i << " is in set " << uf.findSet(i) << endl;
    }
    
    cout << "\nPerforming union operations: " << endl;
    uf.unionSet(0, 1);
    uf.unionSet(1, 2);
    
    cout << "Set of element 0: " << uf.findSet(0) << endl;
    cout << "Set of element 1: " << uf.findSet(1) << endl;
    cout << "Set of element 2: " << uf.findSet(2) << endl;
    cout << "Set of element 3: " << uf.findSet(3) << endl;
    cout << "Set of element 4: " << uf.findSet(4) << endl;
    
    cout << "\nChecking if elements are in the same set:" << endl;
    cout << "Are 0 and 2 in the same set? " << (uf.isSameSet(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 in the same set? " << (uf.isSameSet(3, 4) ? "Yes" : "No") << endl;
    
    uf.unionSet(3, 4);
    cout << "\nAfter union(3,4), are 3 and 4 in the same set? " << (uf.isSameSet(3, 4) ? "Yes" : "No") << endl;
    
    return 0;
}
