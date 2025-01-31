// KRUSHKAL'S ALGORITHM
// Find MST of a weighted connected graph using DSU-
// 1. sort edges in ascending order
// 2. start picking up edges with lower weight to higher weight
//     a. if current edge connects A and B, check if they are already connected in same component or not using DSU
//     b. if connected then skip this edge
//     c. if not connected, use this edge

// Prob link- https://leetcode.com/problems/min-cost-to-connect-all-points/description/

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

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edj;
        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = abs(x1-x2) + abs(y1-y2);
                edj.push_back({wt,i,j});
            }
        }
        sort(edj.begin(),edj.end());
        UnionFind dsu(n+1);
        int ans = 0;
        for(auto i: edj){
            if(!dsu.isSameSet(i[1],i[2])){
                ans += i[0];
                dsu.unionSet(i[1],i[2]);
            }
        }
        return ans;
    }
};
// Practice Problems-
// 1- https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
