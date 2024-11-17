#include <iostream>
using namespace std;

// C?u tr�c Node (m?i ph?n t? trong danh s�ch li�n k?t ��n)
struct Node {
    int data;     // D? li?u l�u tr? trong node
    Node* next;   // Con tr? tr? �?n ph?n t? ti?p theo trong danh s�ch
};

// C?u tr�c Danh s�ch li�n k?t ��n
class DanhSachLienKetDon {
private:
    Node* head;  // Con tr? ch? �?n ph?n t? �?u ti�n c?a danh s�ch

public:
    DanhSachLienKetDon() {
        head = NULL;  // Kh?i t?o danh s�ch tr?ng (d�ng NULL thay v? nullptr)
    }

    // Th�m ph?n t? v�o cu?i danh s�ch
    void themPhanTuCuoi(int giaTri) {
        Node* nodeMoi = new Node;
        nodeMoi->data = giaTri;
        nodeMoi->next = NULL;  // D�ng NULL thay v? nullptr

        if (head == NULL) {
            head = nodeMoi;  // N?u danh s�ch tr?ng, g�n ph?n t? m?i l� head
        } else {
            Node* tam = head;
            while (tam->next != NULL) {
                tam = tam->next;  // Di chuy?n �?n ph?n t? cu?i c�ng
            }
            tam->next = nodeMoi;  // G�n ph?n t? m?i v�o cu?i danh s�ch
        }
    }

    // X�a ph?n t? �?u ti�n trong danh s�ch
    void xoaPhanTuDauTien() {
        if (head != NULL) {
            Node* tam = head;
            head = head->next;  // C?p nh?t head tr? �?n ph?n t? ti?p theo
            delete tam;         // Gi?i ph�ng b? nh? c?a ph?n t? �?u ti�n
        }
    }

    // T?m ki?m ph?n t? trong danh s�ch
    bool timKiemPhanTu(int giaTri) {
        Node* tam = head;
        while (tam != NULL) {
            if (tam->data == giaTri) {
                return true;  // T?m th?y ph?n t?
            }
            tam = tam->next;
        }
        return false;  // Kh�ng t?m th?y ph?n t?
    }

    // In t?t c? c�c ph?n t? trong danh s�ch
    void hienThiDanhSach() {
        Node* tam = head;
        while (tam != NULL) {
            cout << tam->data << " ";
            tam = tam->next;
        }
        cout << endl;
    }

    // H?y danh s�ch (gi?i ph�ng b? nh?)
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

    // Nh?p s? l�?ng ph?n t? c?n th�m v�o danh s�ch
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    // Nh?p c�c ph?n t? v� th�m v�o danh s�ch
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu " << i + 1 << ": ";
        cin >> giaTri;
        danhSach.themPhanTuCuoi(giaTri);  // Th�m ph?n t? v�o danh s�ch
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

    // X�a ph?n t? �?u ti�n
    danhSach.xoaPhanTuDauTien();
    cout << "Danh sach sau khi xoa phan tu dau tien: ";
    danhSach.hienThiDanhSach();

    return 0;
}

