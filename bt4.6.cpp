#include <bits/stdc++.h>

using namespace std;
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    vector<int> result; // Lưu trữ thứ tự các đỉnh được thăm
    Q.push(1); // Bắt đầu từ đỉnh số 1
    
        /*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/
 while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        result.push_back(v);

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                Q.push(neighbor);
            }
        }
    }

    // In ra thứ tự các đỉnh được thăm
    for (int v : result) {
        cout << v << endl;
    }

}
int main(){
    	
int n = 10;
vector< list<int> > adj;
adj.resize(n + 1);
adj[1].push_back(2);
adj[1].push_back(3);
adj[1].push_back(6);
adj[2].push_back(7);
adj[2].push_back(4);
adj[2].push_back(8);
adj[3].push_back(10);
adj[3].push_back(9);
adj[4].push_back(1);
adj[4].push_back(8);
adj[5].push_back(2);
adj[5].push_back(4);
adj[6].push_back(7);
adj[6].push_back(9);
adj[7].push_back(3);
adj[7].push_back(9);
adj[7].push_back(10);
adj[8].push_back(9);
adj[8].push_back(2);
adj[9].push_back(3);
bfs(adj);
}
