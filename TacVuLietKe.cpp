#include "TacVuLietKe.h"
#include "ChungKhoan.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
 
void TacVuLietKe::thucHien() {
    ifstream fin("ck.dat", ios::binary);
    if (!fin) { cout << "Chua co file ck.dat\n"; return; }

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
 
    ChungKhoan ck;
    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        ck.hienThi();
    }
    fin.close();
}