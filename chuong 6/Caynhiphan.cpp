#include <iostream>
#include<queue>
using namespace std;

// Cau truc Node (moi phan tu trong cay nhi phan)
struct Node {
    int data;       // Du lieu luu tru trong node
    Node* left;     // Con tro tro den nhanh trai
    Node* right;    // Con tro tro den nhanh phai

    Node(int value) {
        data = value;
        left = NULL;  // Su dung NULL thay cho nullptr
        right = NULL; // Su dung NULL thay cho nullptr
    }
};

// Cau truc Cay nhi phan
class CayNhiPhan {
private:
    Node* root;  // Con tro chi den phan tu goc cua cay

public:
    CayNhiPhan() {
        root = NULL;  // Cay ban dau rong
    }

    // Ham them phan tu vao cay (theo quy tac cua cay nhi phan)
    void them(int value) {
        root = themdequy(root, value);
    }

    // Ham de quy de chen mot phan tu vao cay
    Node* themdequy(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);  // Tao node moi khi gap vi tri trong
        }

        if (value < node->data) {
            node->left = themdequy(node->left, value);  // Them vao nhánh trai neu gia tri nho hon
        } else {
            node->right = themdequy(node->right, value);  // Them vao nhánh phai neu gia tri lon hon
        }

        return node;
    }

    // Duyet cay theo chieu rong (level order)
    void duyetChieuRong() {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            cout << temp->data << " ";
            q.pop();

            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }

    // Duyet cay theo tien thu tu (pre-order)
    void duyetTienThuTu() {
        duyetTienThuTudequy(root);
    }

    // Duyet cay theo tien thu tu (pre-order) de quy
    void duyetTienThuTudequy(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        duyetTienThuTudequy(node->left);
        duyetTienThuTudequy(node->right);
    }

    // Duyet cay theo trung thu tu (in-order)
    void duyetTrungThuTu() {
        duyetTrungThuTudequy(root);
    }

    // Duyet cay theo trung thu tu (in-order) de quy
    void duyetTrungThuTudequy(Node* node) {
        if (node == NULL) return;
        duyetTrungThuTudequy(node->left);
        cout << node->data << " ";
        duyetTrungThuTudequy(node->right);
    }

    // Duyet cay theo hau thu tu (post-order)
    void duyetHauThuTu() {
        duyetHauThuTudequy(root);
    }

    // Duyet cay theo hau thu tu (post-order) de quy
    void duyetHauThuTudequy(Node* node) {
        if (node == NULL) return;
        duyetHauThuTudequy(node->left);
        duyetHauThuTudequy(node->right);
        cout << node->data << " ";
    }

    // Ham huy cay, giai phong bo nho
    ~CayNhiPhan() {
        xoaCay(root);
    }

    // Ham de quy huy cay
    void xoaCay(Node* node) {
        if (node == NULL) return;
        xoaCay(node->left);
        xoaCay(node->right);
        delete node;
    }
};

int main() {
    CayNhiPhan cay;
    int n, value;

    // Nhap so luong phan tu can them vao cay
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    // Nhap cac phan tu va them vao cay
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu " << i + 1 << ": ";
        cin >> value;
        cay.them(value);  // Them phan tu vao cay
    }

    // Duyet cay theo chieu rong
    cout << "Duyet theo chieu rong  ";
    cay.duyetChieuRong();
    cout << endl;

    // Duyet cay theo tien thu tu
    cout << "Duyet theo tien thu tu  ";
    cay.duyetTienThuTu();
    cout << endl;

    // Duyet cay theo trung thu tu
    cout << "Duyet theo trung thu tu  ";
    cay.duyetTrungThuTu();
    cout << endl;

    // Duyet cay theo hau thu tu
    cout << "Duyet theo hau thu tu  ";
    cay.duyetHauThuTu();
    cout << endl;

    return 0;
}

