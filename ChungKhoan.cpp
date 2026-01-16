#include "ChungKhoan.h"
#include <iostream>
#include <sstream>
#include <cstring>

string clean(string s) {
    string r;
    for (char c : s)
        if (c != ',') r += c;
    return r;
}

void ChungKhoan::parse(string line) {
    stringstream ss(line);
    string t;

    ss >> t; strcpy(maCK, t.c_str());
    ss >> giaTran >> giaSan >> giaTC;

    ss >> giaMua[2] >> t; klMua[2] = stol(clean(t));
    ss >> giaMua[1] >> t; klMua[1] = stol(clean(t));
    ss >> giaMua[0] >> t; klMua[0] = stol(clean(t));

    ss >> giaKhop >> t; klKhop = stol(clean(t));
    ss >> thayDoi;

    ss >> giaBan[0] >> t; klBan[0] = stol(clean(t));
    ss >> giaBan[1] >> t; klBan[1] = stol(clean(t));
    ss >> giaBan[2] >> t; klBan[2] = stol(clean(t));

    ss >> t; tongKL = stol(clean(t));
    ss >> moCua >> caoNhat >> thapNhat;

    ss >> t; nnMua = stol(clean(t));
    ss >> t; nnBan = stol(clean(t));
}

void ChungKhoan::hienThi() const {
    cout << maCK << "\t"
         << giaTran << "\t" << giaSan << "\t" << giaTC << "\t"
         << giaMua[0] << "/" << klMua[0] << "\t"
         << giaMua[1] << "/" << klMua[1] << "\t"
         << giaMua[2] << "/" << klMua[2] << "\t"
         << giaKhop << "/" << klKhop << "\t"
         << thayDoi << "\t"
         << giaBan[0] << "/" << klBan[0] << "\t"
         << giaBan[1] << "/" << klBan[1] << "\t"
         << giaBan[2] << "/" << klBan[2] << "\t"
         << tongKL << "\t"
         << moCua << "\t" << caoNhat << "\t" << thapNhat << "\t"
         << nnMua << "\t" << nnBan
         << endl;
}

float ChungKhoan::getGiaDongCua() const {
    return giaKhop;
}

long ChungKhoan::getKhoiLuongGiaoDich() const {
    return tongKL;
}

