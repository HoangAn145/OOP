#include "TacVuTimMax.h"
#include "ChungKhoan.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
 

static void inHeaderNgan() {
    const int W_MA = 6, W_GIA = 7, W_PAIR = 16, W_VOL = 10;
    cout << left << setw(W_MA) << "Ma"
<< right 
<< setw(W_GIA) << "Tran" << setw(W_GIA) << "San" << setw(W_GIA) << "TC"
<< setw(W_PAIR) << "Mua 3" << setw(W_PAIR) << "Mua 2" << setw(W_PAIR) << "Mua 1"
<< setw(W_PAIR) << "Khop Lenh" << setw(W_GIA) << "+/-"
<< setw(W_PAIR) << "Ban 1" << setw(W_PAIR) << "Ban 2" << setw(W_PAIR) << "Ban 3"
<< setw(W_VOL) << "TongKL"
<< setw(W_GIA) << "Mo" << setw(W_GIA) << "Cao" << setw(W_GIA) << "Thap"
<< setw(W_VOL) << "NNMua" << setw(W_VOL) << "NNBan" << endl;
    cout << setfill('-') << setw(175) << "-" << setfill(' ') << endl;
}
 
void TacVuTimMaxGia::thucHien() {
    ifstream fin("ck.dat", ios::binary);
    if (!fin) { cout << "Chua co file ck.dat\n"; return; }
 
    ChungKhoan ck, maxCK;
    bool first = true, foundAny = false;
 
    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        float gia = ck.getGiaDongCua();
        if (std::isnan(gia) || gia == 0) continue;
        if (first || gia > maxCK.getGiaDongCua()) {
            maxCK = ck; first = false; foundAny = true;
        }
    }
 
    if (foundAny) {
        cout << "\n=== MA CO GIA DONG CUA CAO NHAT ===\n";
        inHeaderNgan();
        maxCK.hienThi();
    } else cout << "\nKhong tim thay du lieu.\n";
    fin.close();
}
 
void TacVuTimMaxKL::thucHien() {
    ifstream fin("ck.dat", ios::binary);
    if (!fin) { cout << "Chua co file ck.dat\n"; return; }
 
    ChungKhoan ck, maxCK;
    bool first = true, foundAny = false;
 
    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        long kl = ck.getKhoiLuongGiaoDich();
        if (kl <= 0) continue;
        if (first || kl > maxCK.getKhoiLuongGiaoDich()) {
            maxCK = ck; first = false; foundAny = true;
        }
    }
 
    if (foundAny) {
        cout << "\n=== MA CO KHOI LUONG GD CAO NHAT ===\n";
        inHeaderNgan();
        maxCK.hienThi();
    } else cout << "\nKhong tim thay du lieu.\n";
    fin.close();
}