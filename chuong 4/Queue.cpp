#include <iostream>
#include <queue>
#include <string>
using namespace std;
// Thap phan sang nhi phan
string decimalToBinary(int number) {
    if (number == 0) return "0";
    string binary = "";
    while (number > 0) {
        binary = (number % 2 == 0 ? "0" : "1") + binary;
        number /= 2;
    }
    return binary;
}
void printBinaryNumbers(int K, int N) {
    queue<int> q;
    for (int i = K; i <= N; ++i) {
        q.push(i);
    }
    // Duyet qua cac so trong pham vi
    while (!q.empty()) {
        int current = q.front();
        q.pop();
    // Chuyen so hien tai sang nhi phan
        cout << decimalToBinary(current) << " ";
    }
    cout << endl;
}
int main() {
    int K, N;
    cout << "Nhap N: ";
    cin >> K;
    cout << "Nhap K: ";
    cin >> N;
    if (K > N || K < 1) {
        cout << "Kh hop le" << endl;
        return 1;
    }
    cout << "Cac so nhi phan tu " << K << " den " << N << " la:" << endl;
    printBinaryNumbers(K, N);
    return 0;
}

