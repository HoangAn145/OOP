#include <iostream>
#include <fstream>
#include "ChungKhoan.h"
#include "XuLyNhiPhan.h"

using namespace std;

void lietKe() {
    ifstream fin("ck.dat", ios::binary);
    ChungKhoan ck;

    cout << "Ma\tGiaTran\tGiaSan\tGiaTC\tDuMua/KL1 \tDuMua/KL2\tDuMua/KL3\tKhop\t+/-\t"
            "Ban1\tBan2\tBan3\tTongKL\tMo\tCao\tThap\tNNM\tNNB\n";

    while (fin.read((char*)&ck, sizeof(ChungKhoan)))
        ck.hienThi();

    fin.close();
}

void maxGiaDongCua() {
    ifstream fin("ck.dat", ios::binary);
    ChungKhoan ck, max;
    bool first = true;

    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        if (first || ck.getGiaDongCua() > max.getGiaDongCua()) {
            max = ck;
            first = false;
        }
    }

    cout << "\nChung khoan co gia dong cua cao nhat:\n";
    max.hienThi();
    fin.close();
}

void maxKhoiLuong() {
    ifstream fin("ck.dat", ios::binary);
    ChungKhoan ck, max;
    bool first = true;

    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        if (first || ck.getKhoiLuongGiaoDich() > max.getKhoiLuongGiaoDich()) {
            max = ck;
            first = false;
        }
    }

    cout << "\nChung khoan co KHOI LUONG GIAO DICH CAO NHAT (Tong KL):\n";
    max.hienThi();
    fin.close();
}


int main() {
    int ch;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Doc ck.txt -> ghi ck.dat\n";
        cout << "2. Liet ke toan bo chung khoan theo ngay\n";
        cout << "3. Gia dong cua cao nhat theo ngay\n";
        cout << "4. Khoi luong giao dich cao nhat theo ngay\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> ch;

        switch (ch) {
            case 1:
            case 2: lietKe(); break;
            case 3: maxGiaDongCua(); break;
            case 4: maxKhoiLuong(); break;
        }
    } while (ch != 0);

    return 0;
}
