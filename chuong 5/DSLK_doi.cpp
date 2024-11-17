#include <iostream>
using namespace std;

// Cau truc Node (moi phan tu trong danh sach lien ket doi)
struct Node {
    int data;       // Du lieu luu tru trong node
    Node* next;     // Con tro tro den phan tu tiep theo
    Node* prev;     // Con tro tro den phan tu truoc do
};

// Cau truc Danh sach lien ket doi
class DoublyLinkedList {
private:
    Node* head;  // Con tro tro den phan tu dau tien cua danh sach
    Node* tail;  // Con tro tro den phan tu cuoi cung cua danh sach

public:
    DoublyLinkedList() {
        head = tail = NULL;  // Khoi tao danh sach rong
    }

    // Them phan tu vao dau danh sach
    void themVaoDau(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;  // Con tro next tro den phan tu dau danh sach hien tai
        newNode->prev = NULL;  // Phan tu dau danh sach khong co phan tu truoc

        if (head != NULL) {
            head->prev = newNode;  // Neu danh sach khong rong, gan prev cua head tro den node moi
        }
        head = newNode;  // Cap nhat head tro den node moi
        if (tail == NULL) {
            tail = head;  // Neu danh sach chi co mot phan tu, tail cung phai tro den node moi
        }
    }

    // Them phan tu vao cuoi danh sach
    void themVaoCuoi(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;  // Phan tu cuoi khong co phan tu sau no
        newNode->prev = tail;  // Con tro prev tro den phan tu cuoi hien tai

        if (tail != NULL) {
            tail->next = newNode;  // Neu danh sach khong rong, gan next cua tail tro den node moi
        }
        tail = newNode;  // Cap nhat tail tro den node moi
        if (head == NULL) {
            head = tail;  // Neu danh sach rong, head cung phai tro den node moi
        }
    }

    // Xoa phan tu dau tien trong danh sach
    void xoaDau() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;  // Cap nhat head tro den phan tu tiep theo
            if (head != NULL) {
                head->prev = NULL;  // Neu danh sach con phan tu, cap nhat prev cua head ve NULL
            }
            delete temp;  // Giai phong bo nho cua phan tu dau tien
            if (head == NULL) {
                tail = NULL;  // Neu danh sach rong, tail cung phai NULL
            }
        }
    }

    // Xoa phan tu cuoi cung trong danh sach
    void xoaCuoi() {
        if (tail != NULL) {
            Node* temp = tail;
            tail = tail->prev;  // Cap nhat tail tro den phan tu truoc do
            if (tail != NULL) {
                tail->next = NULL;  // Neu danh sach con phan tu, cap nhat next cua tail ve NULL
            }
            delete temp;  // Giai phong bo nho cua phan tu cuoi cung
            if (tail == NULL) {
                head = NULL;  // Neu danh sach rong, head cung phai NULL
            }
        }
    }

    // Tim kiem phan tu trong danh sach
    bool timKiem(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;  // Tim thay phan tu
            }
            temp = temp->next;
        }
        return false;  // Khong tim thay phan tu
    }

    // Hien thi danh sach
    void hienThi() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Giai phong bo nho khi huy danh sach
    ~DoublyLinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int n, value;

    // Nhap so luong phan tu can them vao danh sach
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    // Nhap cac phan tu va them vao danh sach
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu " << i + 1 << ": ";
        cin >> value;
        list.themVaoCuoi(value);  // Them phan tu vao cuoi danh sach
    }

    cout << "Danh sach sau khi them cac phan tu: ";
    list.hienThi();

    // Tim kiem phan tu
    cout << "Nhap gia tri phan tu can tim: ";
    cin >> value;
    if (list.timKiem(value)) {
        cout << "Phan tu " << value << " co trong danh sach." << endl;
    } else {
        cout << "Phan tu " << value << " khong co trong danh sach." << endl;
    }

    // Xoa phan tu dau tien
    list.xoaDau();
    cout << "Danh sach sau khi xoa phan tu dau tien: ";
    list.hienThi();

    // Xoa phan tu cuoi cung
    list.xoaCuoi();
    cout << "Danh sach sau khi xoa phan tu cuoi cung: ";
    list.hienThi();

    return 0;
}

