class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int k = rounds.size();
        vector<int> circle(n+1,0);
        vector<int> ans;
        int m = INT_MIN;
        
        for(int i = 1; i<k; i++){
            for(int j = rounds[i-1]; j%(n+1)!=rounds[i]; j++){
                if(j%(n+1) == 0)
                continue;

                circle[j%(n+1)]++;
                m = max(m,circle[j%(n+1)]);
            }
        }
        circle[rounds[k-1]]++;
        m = max(m,circle[rounds[k-1]]);

        for(int i = 1; i<n+1; i++){
            if(circle[i] == m)
            ans.push_back(i);
        }
        return ans;
    }
};