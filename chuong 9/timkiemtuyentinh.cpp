#include <iostream>
#include <vector>
using namespace std;
int linearSearch(const vector<int>& arr, int target) {
    // Duyet qua moi phan tu trong mang
    for (int i = 0; i < arr.size(); i++) {
        // Neu phan tu tai vi tri i bang gia tri target tra ve chi so i
        if (arr[i] == target) {
            return i;
        }
    }
    //  Neu khong tim thay phan tu tra ve -1
    return -1;
}
int main() {
    int N, target;
    // Nhap vao so luong phan tu trong mang N va mang arr
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> N;
    vector<int> arr(N);
    // Nhap cac gia tri cho mang arr
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    //  Nhap vao gia tri can tim target
    cout << "Nhap gia tri can tim: ";
    cin >> target;
    // Goi ham tim kiem tuyen tinh
    int result = linearSearch(arr, target);
    if (result != -1) {
        cout << "Gia tri " << target << " tai chi so: " << result << endl;
    } else {
        cout << "Gia tri " << target << " khong ton tai trong mang." << endl;
    }
    return 0;
}

