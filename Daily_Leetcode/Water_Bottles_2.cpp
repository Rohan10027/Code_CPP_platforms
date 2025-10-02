class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int emptyBottles = 0;
        int full = numBottles;

        while (full + emptyBottles >= numExchange) {
            // Exchange the bottles
            
            if(emptyBottles >= numExchange){
                emptyBottles-=numExchange;
                full++;
                numExchange++;
            }
            else{
                totalDrunk+=full;
                emptyBottles+=full;
                full=0;
            }
        }
        
        return totalDrunk + full;
    }
};
