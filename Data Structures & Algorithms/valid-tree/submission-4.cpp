class Solution {
public:
    bool isCyclePresent(int start, int parent, vector<int> &visited, vector<vector<int>> &graph){
       bool res =false;
       visited[start] = 1;
       for(int i=0;i<graph[start].size();i++){
           if(!visited[graph[start][i]]){
                res = res || isCyclePresent(graph[start][i], start, visited, graph);
           } else if(parent != graph[start][i]){
                return true;
           }
       }  
       return res || false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        vector<int>visited (n, 0);
        if(n==1 && edges.size()==0) return true;
        if(n==1 && edges.size()==1) return false;

        for(vector<int>a:edges){
           g[a[0]].push_back(a[1]);
           g[a[1]].push_back(a[0]);
        }
        
        if (isCyclePresent(0, 0, visited, g)) return false;
        for(int i=0;i<n;i++){
            cout<<visited[i];
           if(!visited[i])return false;
        }
        return true;
    }
};
