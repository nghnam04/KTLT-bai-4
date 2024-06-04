#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0); // Thêm một cột giả có chiều cao 0 để dễ dàng xử lý các cột còn lại trong stack
    int max_area = 0;
    int n = heights.size();
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, h * w);
        }
        s.push(i);
    }
    
    return max_area;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    cout << largestRectangleArea(heights) << endl;

    return 0;
}
