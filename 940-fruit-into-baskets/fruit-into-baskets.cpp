class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start =0 ; 
        int maxLen=0; 

        unordered_map<int,int> basket;


        for(int i =0 ;i<fruits.size(); i++){
            basket[fruits[i]]++;
            while(basket.size()>2){
                basket[fruits[start]]--;
                if(basket[fruits[start]]==0){
                    basket.erase(fruits[start]);
                }
                start++;
            }
            maxLen=max(maxLen,i-start+1);
        }
        return maxLen;
    }
};