class Solution {
public:
 
    void dfs (int node, int color, vector<int>&visited, vector<vector<int>>&g){
        if(visited[node])return;
        visited[node] = color;
        for(int i =0;i<g[node].size();i++){
            dfs(g[node][i], color, visited, g);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int m= edges.size(), color = 0;
        vector<vector<int>>g(n);
        vector<int>visited(n,0);
        for (int i =0;i<m;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                color++;
                dfs(i, color, visited, g);
            }
        }

        return color;
    }
};
