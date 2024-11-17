#include <iostream>
#include <vector>
using namespace std;

void sapxepnoibot(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) { // Lap qua mang N-1 lan
        for (int j = 0; j < n - i - 1; j++) { // So sanh cac phan tu ke nhau
            if (arr[j] > arr[j + 1]) { // Hoan doi neu ptu truoc lon hon
                swap(arr[j], arr[j + 1]);
            }
        }
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

   sapxepnoibot(arr); // goi ham

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " "; // In ra mang sap xep
    }
    cout << endl;

    return 0;
}

