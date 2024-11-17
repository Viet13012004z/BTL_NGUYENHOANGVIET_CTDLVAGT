#include <iostream>
#include <vector>
using namespace std;
void sapxepchen(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Luu gia tri phan tu can chen
        int j = i - 1;
        
        // Di chuyen cac phan tu lon hon key sang phai
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Chen key vao dung vi tri
        arr[j + 1] = key;
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
   sapxepchen(arr); // Goi ham sap xep chen
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " "; // In ra mang da sap xep
    }
    cout << endl;
    return 0;
}

