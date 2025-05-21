class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
   vector<int> x(m, 0);
    vector<int> y(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j]==0){
                    x[i]=1;
                    y[j]=1;
                }
            }
        }

        for(int i = 0 ; i<m ;i++){
            for(int j = 0 ; j<n;j++){
               if (x[i] == 1 || y[j] == 1)
                matrix[i][j] = 0;
            }
        }
    }

};