#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

/*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/

int countBalancedSubstrings(const string& s) {
    int n = s.length();
    unordered_map<int, int> count;
    int balance = 0;
    int result = 0;
    
    //Khởi tạo balanceCount với giá trị 0 xuất hiện 1 lần
    count[0] = 1;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            balance--;
        } else {
            balance++;
        }
        
        //Nếu balance đã xuất hiện trước đó, nghĩa là có xâu con từ lần xuất hiện trước đến vị trí hiện tại có số lượng 0 và 1 bằng nhau
        if (count.find(balance) != count.end()) {
            result += count[balance];
        }
        
        //Tăng số lần xuất hiện của balance
        count[balance]++;
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << countBalancedSubstrings(s) << endl;
    return 0;
}
