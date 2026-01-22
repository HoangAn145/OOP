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
 
    int count = 0;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        ChungKhoan ck;
        ck.parse(line);
        fout.write((char*)&ck, sizeof(ChungKhoan));
        count++;
    }
    fin.close(); fout.close();
    cout << "Da chuyen doi " << count << " ban ghi sang ck.dat\n";
}