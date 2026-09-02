class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>arr;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=matrix[i][j];
                arr.push_back(x);
            }
        }

        sort(arr.begin(),arr.end());

        return arr[k-1];
        
    }
};