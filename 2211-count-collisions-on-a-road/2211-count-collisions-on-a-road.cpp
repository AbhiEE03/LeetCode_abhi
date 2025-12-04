class Solution {
public:
    int countCollisions(string directions) {
        long long collisions=0, n = directions.size();
        long long l = 0, r = n-1;
        // Eliminating left moving cars on the left boundary
        while(directions[l] == 'L' && l<n){
            l++;
        }
         // Eliminating right moving cars on the right boundary
        while(directions[r]=='R' && r>=0){
            r--;
        }

        // Tackling those which will contribute to collision
        while(l<=r){
            if(directions[l] =='R' || directions[l] == 'L' ){
                collisions++;
                l++;
            }else l++;
        }

        return collisions;

    }
};