#include <iostream>
#include <stack>
using namespace std;
void kiemtra () {
    string s;
    cout << "Nhap dau ngoac: ";
    cin >> s;
    stack<char> st;
    // Duyet qua tung ky tu trong chuoi s 
    for (int i = 0; i < s.length(); i++) {
        char x = s[i];  
        if (x == '(') {
            st.push(x);  // Neu la dau mo ngoac push vao stack 
        } else {
            if (st.empty()) {
                cout << "Khong hop le" << endl;
                return;
            } else {
                st.pop();  // Neu gap dau dong ngoac pop 1 phan khoi stack 
            }
        }
    }

    if (st.empty()) {
        cout << "Hop le" << endl;  // Neu stack rong, bieu thuc hop le
    } else {
        cout << "Khong hop le" << endl;  // Neu stack không rong, bieu thuc không hop le
    }
}

int main() {
    int t;
    cout << "Nhap so luong dau ngoac can kiem tra: ";
    cin >> t;
    while (t--) {
        kiemtra(); 
    }
    return 0;
}

