#include "TacVuLietKe.h"
#include "ChungKhoan.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
 
void TacVuLietKe::thucHien() {
    ifstream fin("ck.dat", ios::binary);
    if (!fin) { cout << "Chua co file ck.dat!\n"; return; }
 
    
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
 
    ChungKhoan ck;
    while (fin.read((char*)&ck, sizeof(ChungKhoan))) {
        ck.hienThi();
    }
    fin.close();
}