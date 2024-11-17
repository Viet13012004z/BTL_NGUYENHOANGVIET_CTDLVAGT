#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // gia su ptu i la min
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // cap nhat so phan tu nho nhat
            }
        }
        // hoan doi phan tu nho nhat toi ptu o vitri i
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    int N;
    cout << "Nhap so luong phan tu: ";
    cin >> N;

    vector<int> arr(N);

    cout << "Nhap mang: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    selectionSort(arr); // goi ham

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " "; // In ra mang sap xep
    }
    cout << endl;

    return 0;
}

