class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // sort(apple.begin(), apple.end(), [](int a , int b){
        //     return a>b;
        // });
        sort(capacity.begin(), capacity.end(), [](int a , int b){
            return a>b;
        });
        // int n = apple.size(), m = capacity.size();
        int total_Apple = accumulate(apple.begin(), apple.end(), 0);
        int i=0, boxes=0;
        while(total_Apple > 0){
            total_Apple -= capacity[i];
            boxes++;
            i++;
        }
        return boxes;      
    }
};