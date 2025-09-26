class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(); // Number of elements in the height array
        int water = 0;         // Initialize the total trapped water volume
        vector<int> stack;     // Stack to store indices of height elements
        // Iterate through the heights
        for (int right = 0; right < n; right++)
        {
            // Process each height to trap water
            while (!stack.empty() && height[stack.back()] < height[right])
            {
                // If the current height is greater than the height at the top of the stack
                int mid = stack.back(); // Get the index of the height at the top of the stack
                stack.pop_back();       // Pop the index from the stack
                // If the stack becomes empty, no more water can be trapped
                if (stack.empty())
                    break;
                int left = stack.back();                                                      // Get the index of the next height from the top of the stack
                int minHeight = min(height[right] - height[mid], height[left] - height[mid]); // Calculate the minimum height of the two borders
                int width = right - left - 1;                                                 // Calculate the width between the left and right borders
                water += minHeight * width;                                                   // Calculate the trapped water volume and add it to the total
            }
            stack.push_back(right); // Push the current index onto the stack
        }
        return water; // Return the total trapped water volume
    }
};