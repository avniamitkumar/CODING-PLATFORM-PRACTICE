class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }

        int cols = matrix[0].size();
        int maxArea = 0;

        // Create a vector to track the heights of each column
        vector<int> heights(cols, 0);

        for (int i = 0; i < rows; i++) {
            // Update the heights array for the current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    // If the current cell is '1', increment the height of the column
                    heights[j]++;
                } else {
                    // If the current cell is '0', reset the height of the column to 0
                    heights[j] = 0;
                }
            }

            // Calculate the maximum area using the histogram approach
            stack<int> stk;
            int currArea = 0;

            for (int j = 0; j <= cols; j++) {
                // Process each column and maintain a non-decreasing stack of heights
                while (!stk.empty() && (j == cols || heights[j] <= heights[stk.top()])) {
                    // The current height is less than the height of the previous column
                    int top = heights[stk.top()]; // Get the height of the top column
                    stk.pop(); // Pop the top column from the stack
                    int breadth = stk.empty() ? j : j - stk.top() - 1;
                    // Calculate the breadth of the rectangle using the current column and the previous column
                    currArea = max(currArea, top * breadth);
                    // Update the maximum area if necessary
                }
                stk.push(j); // Push the current column index to the stack
            }

            // Update the maximum area
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};