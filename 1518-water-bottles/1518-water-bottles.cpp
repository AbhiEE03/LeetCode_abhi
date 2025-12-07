class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        return numBottles + (numBottles-1)/(numExchange-1);
    }
};


// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int drunk=numBottles;
//         int empty=numBottles;

//         while(empty>=numExchange){
//             empty-=numExchange;
//             drunk++;
//             empty++;
//         }
//         return drunk;
//     }
// };