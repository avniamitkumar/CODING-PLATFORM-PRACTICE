class Solution {
public:
    bool f(vector<int>& arr, int st, vector<bool>& visited) {
        if (st < 0 || st >= arr.size() || visited[st]) {
            return false;
        }
        
        if (arr[st] == 0) {
            return true;
        }
        
        visited[st] = true;
        
        return f(arr, st + arr[st], visited) || f(arr, st - arr[st], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return f(arr, start, visited);
    }
};
