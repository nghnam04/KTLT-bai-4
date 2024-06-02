#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

       /*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/

void delete_even(vector<int> &a) {
     for (auto it = a.begin(); it != a.end(); ) {
        if (*it % 2 == 0) {
            it = a.erase(it); 
        } else {
            ++it; 
        }
    }
}

void sort_decrease(vector<int> &a) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> temp;
    for(int v1 : a) temp.push_back(v1);
    for(int v2 : b) temp.push_back(v2);
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    return temp; 
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}