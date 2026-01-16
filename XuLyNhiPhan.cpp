#include "XuLyNhiPhan.h"
#include "ChungKhoan.h"
#include <fstream>
#include <iostream>

using namespace std;

void docTxtGhiNhiPhan() {
    ifstream fin("ck.txt");
    ofstream fout("ck.dat", ios::binary);

    if (!fin || !fout) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    string line;
    getline(fin, line);
    getline(fin, line);

    while (getline(fin, line)) {
        ChungKhoan ck;
        ck.parse(line);
        fout.write((char*)&ck, sizeof(ChungKhoan));
    }

    fin.close();
    fout.close();

    cout << "Da ghi TOAN BO chung khoan vao ck.dat\n";
}
