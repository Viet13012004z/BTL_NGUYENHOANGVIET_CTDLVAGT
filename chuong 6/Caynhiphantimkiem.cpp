#include <iostream>
using namespace std;

// Cau truc Node cho cay nhi phan tim kiem
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Them phan tu vao cay nhi phan tim kiem
Node* themPhanTu(Node* root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return root;
    }
    if (value < root->data) {
        root->left = themPhanTu(root->left, value); // Them vao nhanh trai
    } else {
        root->right = themPhanTu(root->right, value); // Them vao nhanh phai
    }
    return root;
}

// Tim phan tu nho nhat trong cay
Node* timMin(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Tim phan tu lon nhat trong cay
Node* timMax(Node* root) {
    Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Xoa phan tu khoi cay nhi phan tim kiem
Node* xoaPhanTu(Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data) {
        root->left = xoaPhanTu(root->left, value); // Tim va xoa trong nhanh trai
    } else if (value > root->data) {
        root->right = xoaPhanTu(root->right, value); // Tim va xoa trong nhanh phai
    } else {
        // Truong hop 1: Node co 1 con hoac khong co con
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Truong hop 2: Node co 2 con
        Node* temp = timMin(root->right); // Tim node nho nhat trong cay con ben phai
        root->data = temp->data; // Thay gia tri node can xoa bang node thay the
        root->right = xoaPhanTu(root->right, temp->data); // Xoa node thay the
    }
    return root;
}

// Duyet cay nhi phan tim kiem theo thu tu tien thu tu
void duyetTienThuTu(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    duyetTienThuTu(node->left);
    duyetTienThuTu(node->right);
}

// Duyet cay nhi phan tim kiem theo thu tu trung thu tu
void duyetTrungThuTu(Node* node) {
    if (node == NULL) return;
    duyetTrungThuTu(node->left);
    cout << node->data << " ";
    duyetTrungThuTu(node->right);
}

// Duyet cay nhi phan tim kiem theo thu tu hau thu tu
void duyetHauThuTu(Node* node) {
    if (node == NULL) return;
    duyetHauThuTu(node->left);
    duyetHauThuTu(node->right);
    cout << node->data << " ";
}

// Tim phan tu ke tiep trong cay nhi phan tim kiem
Node* timPhanTuKeTiep(Node* root, int value) {
    Node* current = root;
    Node* next = NULL;
    while (current != NULL) {
        if (value < current->data) {
            next = current;
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            if (current->right != NULL) {
                return timMin(current->right);
            }
            break;
        }
    }
    return next;
}
// Xoa cay nhi phan
void xoaCay(Node* &root) {
    if (root != NULL) {
        xoaCay(root->left); // Xoa cay con ben trai
        xoaCay(root->right); // Xoa cay con ben phai
        delete root; // Xoa node hien tai
        root = NULL; // Dat root thanh NULL
    }
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
        root = themPhanTu(root, value);
    }
    // Duyet cay theo tien thu tu
    cout << "Duyet cay theo tien thu tu: ";
    duyetTienThuTu(root);
    cout << endl;
    // Duyet cay theo trung thu tu
    cout << "Duyet cay theo trung thu tu: ";
    duyetTrungThuTu(root);
    cout << endl;
    // Duyet cay theo hau thu tu
    cout << "Duyet cay theo hau thu tu: ";
    duyetHauThuTu(root);
    cout << endl;
    // Tim phan tu nho nhat va lon nhat
    Node* minNode = timMin(root);
    Node* maxNode = timMax(root);
    cout << "Phan tu nho nhat: " << (minNode ? minNode->data : -1) << endl;
    cout << "Phan tu lon nhat: " << (maxNode ? maxNode->data : -1) << endl;
    // Tim phan tu ke tiep
    cout << "Nhap gia tri phan tu can tim phan tu ke tiep: ";
    cin >> value;
    Node* nextNode = timPhanTuKeTiep(root, value);
    cout << "Phan tu ke tiep cua " << value << " la: " << (nextNode ? nextNode->data : -1) << endl;
    // Xoa phan tu
    cout << "Nhap gia tri phan tu can xoa: ";
    cin >> value;
    root = xoaPhanTu(root, value);
    cout << "Duyet cay sau khi xoa phan tu " << value << ": ";
    duyetTrungThuTu(root);
    cout << endl;
    // Xoa cay
    xoaCay(root);
    cout << "Cay sau khi xoa toan bo: ";
    duyetTrungThuTu(root); // Cay da bi xoa, khong in ra gi
    cout << endl;
    return 0;
}

