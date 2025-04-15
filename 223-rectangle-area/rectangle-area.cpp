class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Calculate area of first rectangle
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        
        // Calculate area of second rectangle
        int area2 = (bx2 - bx1) * (by2 - by1);
        
        // Find the overlapping rectangle's coordinates
        int x_left = max(ax1, bx1);
        int x_right = min(ax2, bx2);
        int y_top = min(ay2, by2);
        int y_bottom = max(ay1, by1);
        
        // Calculate overlapping area, if it exists
        int overlap_area = 0;
        if (x_right > x_left && y_top > y_bottom) {
            overlap_area = (x_right - x_left) * (y_top - y_bottom);
        }
        
        // Return total area using inclusion-exclusion
        return area1 + area2 - overlap_area;
    }
};