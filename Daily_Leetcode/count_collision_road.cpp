class Solution {
public:
    int countCollisions(string dir) {
        
        int res(0), n(size(dir)), i(0), carsFromRight(0);
        
        while (i < n and dir[i] == 'L') i++; // skipping all the cars going to left from beginning as they will never collide
        
        for ( ; i<n; i++) {
            if (dir[i] == 'R')  carsFromRight++;
            else {
                // if dir[i] == 'S' then there will be carsFromRight number of collission
                // if dir[i] == 'L' then there will be carsFromRight+1 number of collision (one collision for the rightmost cars and carsFromRight collision for the cars coming from left)
                res += (dir[i] == 'S') ? carsFromRight : carsFromRight+1;
                carsFromRight = 0;
            }
        }
        return res;
    }
};
