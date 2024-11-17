#include <iostream>
using namespace std;

// Cau truc Node cho cay nhi phan tong quat
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Them phan tu vao cay nhi phan tong quat
Node* themPhanTu(Node* root, int value) {
    if (root == NULL) {
        return new Node(value); // Neu cay trong, tao node goc
    }
    char direction;
    cout << "Them " << value << " vao ben trai (l) hay ben phai (r) cua " << root->data << ": ";
    cin >> direction;
    if (direction == 'l') {
        root->left = themPhanTu(root->left, value); // Them vao nhanh trai
    } else {
        root->right = themPhanTu(root->right, value); // Them vao nhanh phai
    }
    return root;
}

// Duyet tien thu tu
void duyetTienThuTu(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    duyetTienThuTu(node->left);
    duyetTienThuTu(node->right);
}

// Duyet trung thu tu
void duyetTrungThuTu(Node* node) {
    if (node == NULL) return;
    duyetTrungThuTu(node->left);
    cout << node->data << " ";
    duyetTrungThuTu(node->right);
}

// Duyet hau thu tu
void duyetHauThuTu(Node* node) {
    if (node == NULL) return;
    duyetHauThuTu(node->left);
    duyetHauThuTu(node->right);
    cout << node->data << " ";
}

// Tinh chieu cao cua cay
int tinhChieuCao(Node* node) {
    if (node == NULL) return 0;
    int chieuCaoTrai = tinhChieuCao(node->left);
    int chieuCaoPhai = tinhChieuCao(node->right);
    return max(chieuCaoTrai, chieuCaoPhai) + 1;
}

// Tinh so luong nut trong cay
int demSoLuongNut(Node* node) {
    if (node == NULL) return 0;
    return demSoLuongNut(node->left) + demSoLuongNut(node->right) + 1;
}

// Xoa cay nhi phan tong quat
void xoaCay(Node* &root) {
    if (root == NULL) return;
    xoaCay(root->left);
    xoaCay(root->right);
    delete root;
    root = NULL;
}

// Ham main de kiem tra cac thao tac
int main() {
    Node* root = NULL;
    int n, value;

    // Nhap so luong phan tu can them vao cay
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    // Nhap cac phan tu va them vao cay
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu " << i + 1 << ": ";
        cin >> value;
        if (root == NULL) {
            root = new Node(value); // Tao goc neu cay trong
        } else {
            themPhanTu(root, value);
        }
    }

    // Duyet cay theo cac thu tu
    cout << "Duyet cay theo tien thu tu: ";
    duyetTienThuTu(root);
    cout << endl;

    cout << "Duyet cay theo trung thu tu: ";
    duyetTrungThuTu(root);
    cout << endl;

    cout << "Duyet cay theo hau thu tu: ";
    duyetHauThuTu(root);
    cout << endl;

    // Tinh chieu cao cua cay
    int chieuCao = tinhChieuCao(root);
    cout << "Chieu cao cua cay: " << chieuCao << endl;

    // Tinh so luong nut trong cay
    int soLuongNut = demSoLuongNut(root);
    cout << "So luong nut trong cay: " << soLuongNut << endl;

    // Xoa cay
    xoaCay(root);
    cout << "Cay sau khi xoa toan bo: ";
    duyetTrungThuTu(root); // Cay da bi xoa, khong in ra gi
    cout << endl;

    return 0;
}

