class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       // we use a queue data structure, push room keys
       // and a visited array, if all true at end return true;
        queue<int> q;
        vector<bool> visited(rooms.size(),false);
        visited[0]=true;

        for(int i=0;i<rooms[0].size();i++)
        {q.push(rooms[0][i]);}


        while(!q.empty()){
        int x = q.front();
        q.pop();
        if(!visited[x]){
            visited[x]=true;
            for(int i=0;i<rooms[x].size();i++)
            {
                if(!visited[rooms[x][i]])
                q.push(rooms[x][i]);
            }
        }
    }
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false)
            return false;
        }
        return true;
    }
};