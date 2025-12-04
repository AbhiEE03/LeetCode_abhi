class Solution {
public:
    int countCollisions(string directions) {
        long long collisions=0, n = directions.size();
        long long l = 0, r = n-1;
        // Eliminating left moving cars on the left boundary
        while( l<n && directions[l] == 'L' ){
            l++;
        }
         // Eliminating right moving cars on the right boundary
        while(r>=0 && directions[r]=='R' ){
            r--;
        }

        // Tackling those which will contribute to collision
        for(int i=l; i<=r; i++){
            if(directions[i]!='S') collisions++;
        }

        return collisions;

    }
};