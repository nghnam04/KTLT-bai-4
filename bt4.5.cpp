#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm> // for reverse

using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size(), false);
    vector<int> result; // Để lưu trữ thứ tự các đỉnh được thăm
    
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    while (!S.empty()) {
        int v = S.top();
        S.pop();
        
        if (!visited[v]) {
            visited[v] = true;
            result.push_back(v);
            
            // Đảo ngược thứ tự các đỉnh kề để đảm bảo ưu tiên từ trái sang phải
            list<int> neighbors = adj[v];
            neighbors.reverse();
            for (int neighbor : neighbors) {
                if (!visited[neighbor]) {
                    S.push(neighbor);
                }
            }
        }
    }
    
    // In ra thứ tự các đỉnh được thăm
    for (int v : result) {
        cout << v << endl;
    }
    cout << endl;
}

int main() {
    // Ví dụ về cách sử dụng
    vector< list<int> > adj(6); // Giả sử đồ thị có 5 đỉnh (đánh số từ 1 đến 5)
    
    // Thêm các cạnh vào danh sách kề
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(5);
    
    // Gọi hàm DFS
    dfs(adj);
    
    return 0;
}
