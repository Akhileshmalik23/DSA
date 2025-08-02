class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for (int i = 0; i < basket1.size(); i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]++;
        }
        for (unordered_map<int, int>::iterator it = freq.begin();
             it != freq.end(); it++) {
            if (it->second % 2 != 0)
                return -1;
        }
        unordered_map<int, int> freq1, freq2;
        for (int i = 0; i < basket1.size(); i++) {
            freq1[basket1[i]]++;
            freq2[basket2[i]]++;
        }

        vector<int> extra1, extra2;

        for (unordered_map<int, int>::iterator it = freq.begin();
             it != freq.end(); it++) {
            int fruit = it->first;
            int total = it->second;

            int targetval = total / 2;

            if(freq1[fruit]>targetval){
                int extra = freq1[fruit]-targetval;
                for(int i =0 ; i  < extra; i++){
                    extra1.push_back(fruit);
                }
            }

            if(freq2[fruit]>targetval){
                int extra = freq2[fruit]-targetval;
                for(int i =0 ; i<extra; i++){
                    extra2.push_back(fruit);
                }
            }
             }
            sort(extra1.begin(),extra1.end(),greater<int>());
            sort(extra2.begin(),extra2.end());

            int minFruit = basket1[0];
            for(int i =1; i<basket1.size(); i++){
                if(basket1[i]<minFruit)
                 minFruit=basket1[i];
            }

            for(int i =0 ; i <basket2.size();i++){
                if(basket2[i]<minFruit)minFruit = basket2[i];
            }

            long long totalcost =0 ; 
            for(int i =0 ; i<extra1.size();i++){
                int a = extra1[i];
                int b = extra2[i];
                int swapcost = min(a,b);
                int bridgecost = 2*minFruit;

                totalcost +=min(swapcost,bridgecost);
            }
            return totalcost;
        }
    
};