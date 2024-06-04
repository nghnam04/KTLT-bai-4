#include <bits/stdc++.h>

using namespace std;

/*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/

// Cấu trúc để lưu trữ thông tin về các đoạn tường
class Wall {
    public:
        int a; //Số tên giặc tấn công đoạn tường này
        int k; //Khả năng chống trả của mỗi lính tại đoạn tường này
        Wall(){}
        Wall(int A, int K){
            a = A;
            k = K;
        }
};

struct Compare {
    bool operator()(const Wall& b, const Wall& c) {
        int tempb, tempc;

        if(b.a <= b.k) tempb = b.a;
        else tempb = b.k;

        if(c.a <= c.k) tempc = c.a;
        else tempc = c.k;

        return tempb < tempc;
    }
};

int main() {
    int n;
    int s;
    cin >> n >> s;
    vector<Wall> walls(n);

    int totalInvaders = 0, killInvaders = 0;

    for (int i = 0; i < n; ++i) {
        cin >> walls[i].a >> walls[i].k;
        totalInvaders += walls[i].a;
    }

    priority_queue <Wall, vector<Wall>, Compare> pq;

    for (auto wall : walls){
        pq.push(wall);
    }

    while(!pq.empty() && s>0){
        Wall inf = pq.top(); 
        pq.pop();
        if(inf.a <= inf.k){
            killInvaders += inf.a;
        } else {
            int remainInvaders = inf.a - inf.k;
            pq.push(Wall(remainInvaders, inf.k));
            killInvaders += inf.k;
        }

        s--;
    }

    cout << totalInvaders - killInvaders << endl;

    return 0;
}