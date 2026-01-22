#include "TacVuTimMax.h"
#include "ChungKhoan.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
 

static void indaumuc() {
    cout << left << setw(6) << "MaCK"
        << right 
        << setw(10) << "Gia Tran" << setw(10) << "Gia San" << setw(10) << "Gia TC"
        << setw(16) << "Du Mua 3" << setw(16) << "Du Mua 2" << setw(16) << "Du Mua 1"
        << setw(10) << "Gia Khop"
        << setw(10) << "KL Khop"
        << setw(10) << "+/-"
        << setw(16) << "Ban 1" << setw(16) << "Ban 2" << setw(16) << "Ban 3"
        << setw(10) << "TongKL"
        << setw(10) << "Mo Cua" << setw(10) << "Cao" << setw(10) << "Thap"
        << setw(10) << "NNMua" << setw(10) << "NNBan" << endl;
}
 
void TacVuTimMaxGia::thucHien() {
    ifstream fin("ck.dat", ios::binary);
    if (!fin) { cout << "Chua co file ck.dat\n"; return; }
 
    ChungKhoan ck, maxCK;
    bool first = true, foundAny = false;
 
    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        float gia = ck.getGiaDongCua();
        if (std::isnan(gia)) continue;
        if (first || gia > maxCK.getGiaDongCua()) {
            maxCK = ck; first = false; foundAny = true;
        }
    }
 
    if (foundAny) {
        cout << "Ma co gia dong cua cao nhat:\n";
        indaumuc();
        maxCK.hienThi();
    } else cout << "Khong tim thay du lieu.\n";
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
        cout << "Ma co khoi luong giao dich lon nhat:\n";
        indaumuc();
        maxCK.hienThi();
    } else cout << "Khong tim thay du lieu.\n";
    fin.close();
}