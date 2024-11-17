#include <iostream>
using namespace std;

// C?u trúc Node (m?i ph?n t? trong danh sách liên k?t ðõn)
struct Node {
    int data;     // D? li?u lýu tr? trong node
    Node* next;   // Con tr? tr? ð?n ph?n t? ti?p theo trong danh sách
};

// C?u trúc Danh sách liên k?t ðõn
class DanhSachLienKetDon {
private:
    Node* head;  // Con tr? ch? ð?n ph?n t? ð?u tiên c?a danh sách

public:
    DanhSachLienKetDon() {
        head = NULL;  // Kh?i t?o danh sách tr?ng (dùng NULL thay v? nullptr)
    }

    // Thêm ph?n t? vào cu?i danh sách
    void themPhanTuCuoi(int giaTri) {
        Node* nodeMoi = new Node;
        nodeMoi->data = giaTri;
        nodeMoi->next = NULL;  // Dùng NULL thay v? nullptr

        if (head == NULL) {
            head = nodeMoi;  // N?u danh sách tr?ng, gán ph?n t? m?i là head
        } else {
            Node* tam = head;
            while (tam->next != NULL) {
                tam = tam->next;  // Di chuy?n ð?n ph?n t? cu?i cùng
            }
            tam->next = nodeMoi;  // Gán ph?n t? m?i vào cu?i danh sách
        }
    }

    // Xóa ph?n t? ð?u tiên trong danh sách
    void xoaPhanTuDauTien() {
        if (head != NULL) {
            Node* tam = head;
            head = head->next;  // C?p nh?t head tr? ð?n ph?n t? ti?p theo
            delete tam;         // Gi?i phóng b? nh? c?a ph?n t? ð?u tiên
        }
    }

    // T?m ki?m ph?n t? trong danh sách
    bool timKiemPhanTu(int giaTri) {
        Node* tam = head;
        while (tam != NULL) {
            if (tam->data == giaTri) {
                return true;  // T?m th?y ph?n t?
            }
            tam = tam->next;
        }
        return false;  // Không t?m th?y ph?n t?
    }

    // In t?t c? các ph?n t? trong danh sách
    void hienThiDanhSach() {
        Node* tam = head;
        while (tam != NULL) {
            cout << tam->data << " ";
            tam = tam->next;
        }
        cout << endl;
    }

    // H?y danh sách (gi?i phóng b? nh?)
    ~DanhSachLienKetDon() {
        Node* tam;
        while (head != NULL) {
            tam = head;
            head = head->next;
            delete tam;
        }
    }
};

int main() {
    DanhSachLienKetDon danhSach;
    int n, giaTri;

    // Nh?p s? lý?ng ph?n t? c?n thêm vào danh sách
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    // Nh?p các ph?n t? và thêm vào danh sách
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu " << i + 1 << ": ";
        cin >> giaTri;
        danhSach.themPhanTuCuoi(giaTri);  // Thêm ph?n t? vào danh sách
    }

    cout << "Danh sach sau khi them cac phan tu: ";
    danhSach.hienThiDanhSach();

    // T?m ki?m ph?n t?
    cout << "Nhap gia tri phan tu can tim: ";
    cin >> giaTri;
    if (danhSach.timKiemPhanTu(giaTri)) {
        cout << "Phan tu " << giaTri << " co trong danh sach." << endl;
    } else {
        cout << "Phan tu " << giaTri << " khong co trong danh sach." << endl;
    }

    // Xóa ph?n t? ð?u tiên
    danhSach.xoaPhanTuDauTien();
    cout << "Danh sach sau khi xoa phan tu dau tien: ";
    danhSach.hienThiDanhSach();

    return 0;
}

