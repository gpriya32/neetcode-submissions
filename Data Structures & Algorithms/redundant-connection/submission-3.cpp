class Solution {
public:
   
    
    int findP(int n, vector<int>&parent){
        if(n==parent[n]){
            return n;
        }
        // tree compression
        return parent[n] = findP(parent[n], parent);
    }

    bool unionByRank(int u, int v, vector<int>&parent, vector<int>&rank){
        int r_u = rank[u];
        int r_v = rank[v];
        int p_u = findP(u, parent);
        int p_v = findP(v, parent);
        if(p_u == p_v) return true;
        if(r_u<r_v){
            parent[p_u] = p_v;
        } else if (r_u>r_v){
            parent[p_v] = p_u;
        } else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }

        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n= edges.size();
    vector<int>parent(n+1), rank(n+1, 0);
    for(int i =1;i<=n;i++){
        parent[i] = i;
    }

    for(auto edge : edges){
        if(unionByRank(edge[0], edge[1], parent, rank)) return edge;
    }

    return {};
    
    }
};
