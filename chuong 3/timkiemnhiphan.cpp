#include <iostream>
#include <vector>
#include <algorithm> // De su dung sort()
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Neu tim thay tra ve chi so
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Tim kiem trong nua phai
        }
        else {
            high = mid - 1; // Tim kiem trong nua trai
        }
    }

    return -1; // Khong tim thay
}
int main() {
    int N, target;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> N;
    vector<int> arr(N);
    // Nhap cac gia tri cho mang
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // Sap xep mang truoc khi tim kiem nhip phan
    sort(arr.begin(), arr.end());
    // Nhap gia tri can tim
    cout << "Nhap gia tri can tim: ";
    cin >> target;
    // Tim kiem nhip phan
    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Gia tri " << target << " tai chi so: " << result << endl;
    } else {
        cout << "Gia tri " << target << " khong ton tai trong mang." << endl;
    }
    return 0;
}

