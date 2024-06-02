#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/
double AB = sqrt(((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second)));
double AC = sqrt(((a.first - c.first) * (a.first - c.first)) + ((a.second - c.second) * (a.second - c.second)));
double BC = sqrt(((c.first - b.first) * (c.first - b.first)) + ((c.second - b.second) * (c.second - b.second)));
double p = (AB + AC + BC) / 2;
return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}