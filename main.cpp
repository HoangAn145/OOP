#include <iostream>
#include "TacVuChuyenDoi.h"
#include "TacVuLietKe.h"
#include "TacVuTimMax.h"
 
using namespace std;
 
int main() {
    int ch;
    TacVu* tacVu = nullptr;
 
    do {
        cout << "\n===== QUAN LY CHUNG KHOAN =====\n";
        cout << "1. Chuyen doi du lieu \n";
        cout << "2. Liet ke danh sach\n";
        cout << "3. Tim gia dong cua cao nhat\n";
        cout << "4. Tim khoi luong giao dich cao nhat\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> ch;
 
        if (tacVu != nullptr) { delete tacVu; tacVu = nullptr; }
 
        switch (ch) {
            case 1: tacVu = new TacVuChuyenDoi(); break;
            case 2: tacVu = new TacVuLietKe(); break;
            case 3: tacVu = new TacVuTimMaxGia(); break;
            case 4: tacVu = new TacVuTimMaxKL(); break;
            case 0: cout << "Ket thuc.\n"; break;
            default: cout << "Lua chon khong dung\n";
        }
 
        if (tacVu != nullptr) tacVu->thucHien();
 
    } while (ch != 0);
 
    if (tacVu != nullptr) delete tacVu;
    return 0;
}