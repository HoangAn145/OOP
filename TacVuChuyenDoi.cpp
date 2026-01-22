#include "TacVuChuyenDoi.h"
#include "ChungKhoan.h"
#include <iostream>
#include <fstream>
using namespace std;
 
void TacVuChuyenDoi::thucHien() {
    ifstream fin("ck.txt");
    ofstream fout("ck.dat", ios::binary);
 
    if (!fin || !fout) {
        cout << "Loi mo file\n";
        return;
    }
    string line;
    getline(fin, line); getline(fin, line); 
 
    while (getline(fin, line)) {
        if (line.empty()) continue;
        ChungKhoan ck;
        ck.parse(line);
        fout.write((char*)&ck, sizeof(ChungKhoan));
    }
    fin.close(); fout.close();
    cout << "Da chuyen doi sang ck.dat\n";
}