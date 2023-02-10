class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int,unordered_map<int,int>> map;
        int xmin=INT_MAX,ymin=INT_MAX, xmax=INT_MIN,ymax=INT_MIN;

        long long area=0;

        for(auto vct:rectangles){
            if(ymin>vct[1]||(ymin==vct[1]&&xmin>vct[0])){
                ymin=vct[1];
                xmin=vct[0];
            }

            if(ymax<vct[3]||(ymax==vct[3]&&xmax<vct[2])){
                 ymax=vct[3];
                 xmax=vct[2];
            }

            map[vct[0]][vct[1]]++;
            map[vct[2]][vct[3]]++;
            map[vct[0]][vct[3]]++;
            map[vct[2]][vct[1]]++;  

            area+= (long long )abs(vct[3]-vct[1])* abs(vct[2]-vct[0]);
        }

        long long total_area=(long long )abs(ymax-ymin) * abs(xmax-xmin);

 if(map[xmin][ymin]!=1||map[xmax][ymax]!=1||map[xmin][ymax]!=1||map[xmax][ymin]!=1||total_area!=area) return false;

        for(auto it:map){
            int x=it.first;
            for(auto it1:map[x]){
                int y=it1.first;
                if((x==xmin&&y==ymin)||(x==xmin&&y==ymax)||(x==xmax&&y==ymin)||(x==xmax&&y==ymax)) continue;

                if(it1.second&1) return false;
            }
        }

        return true;
    }
};