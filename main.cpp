#include <iostream>
#include <fstream>
#include <vector>
int main() {
    int ch;
    do {
        cout << "\n===== QUAN LY CHUNG KHOAN (OOP/SPLIT FILES) =====\n";
        cout << "1. Chuyen doi du lieu (ck.txt -> ck.dat)\n";
        cout << "2. Liet ke danh sach\n";
        cout << "3. Tim gia dong cua cao nhat\n";
        cout << "4. Tim khoi luong giao dich cao nhat\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> ch

        switch (ch) {
            case 1: tacVu = new TacVuChuyenDoi(); break;
            case 2: tacVu = new TacVuLietKe(); break;
            case 3: tacVu = new TacVuTimMaxGia(); break;
            case 4: tacVu = new TacVuTimMaxKL(); break;
            case 0: cout << "Ket thuc.\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (ch != 0);

    return 0;
}