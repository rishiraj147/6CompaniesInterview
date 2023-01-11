class Solution {
public:
    bool isCycle(vector<int> adj[],int root,vector<bool>&vis,vector<bool>&inst){

        vis[root]=true;
        inst[root]=true;

        for(int child:adj[root]){
            if(!vis[child] && isCycle(adj,child,vis,inst)) return true;
            else if(inst[child]) return true;
        }

        inst[root]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto vct:prerequisites){
            adj[vct[1]].push_back(vct[0]);
        }

        vector<bool> vis(numCourses,false);
        vector<bool> inst(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycle(adj,i,vis,inst)) return false;      
        }
        return true;    
    }
};