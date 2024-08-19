class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle,vector<int>& location) {
        int duplicatepoints = 0;
        vector<double> radians;
        for (auto point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                duplicatepoints++;
            } else {
                double radian = atan2(point[1] - location[1], point[0] - location[0]) * 180.0 / M_PI;
                if (radian < 0) {
                    radian += 360;
                }
                radians.push_back(radian);
            }
        }
        
        vector<double> all_radians = radians;
        for (double radian : radians) {
            all_radians.push_back(radian + 360);
        }
        
        sort(all_radians.begin(), all_radians.end());
        
        int max_count = 0;
        int i = 0;
        for (int j = 0; j < all_radians.size(); j++) {
            while (all_radians[j] - all_radians[i] > angle) {
                i++;
            }
            max_count = max(max_count, j - i + 1);
        } 
        return duplicatepoints + max_count;
    }
};