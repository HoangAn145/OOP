#include "ChungKhoan.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

string clean(string s) {
    string r;
    for (char c : s) if (c != ',') r += c;
    return r;
}

float stringToFloat(string s) {
    if (s.empty()) return NAN;
    string s_clean = clean(s);
    try { return stof(s_clean); } catch (...) { return NAN; }
}

long stringToLong(string s) {
    if (s.empty()) return -1;
    string s_clean = clean(s);
    try { return stol(s_clean); } catch (...) { return -1; }
}

string dinhdangCap(float gia, long kl) {
    stringstream ss;
    if (std::isnan(gia) && kl == -1) return "";
    if (!std::isnan(gia)) ss << fixed << setprecision(2) << gia; else ss << "   ";
    ss << "/";
    if (kl != -1) ss << kl; else ss << "   ";
    return ss.str();
}

string dinhdangGia(float gia) {
    if (std::isnan(gia)) return "";
    stringstream ss;
    ss << fixed << setprecision(2) << gia;
    return ss.str();
}

string dinhdangKl(long kl) {
    if (kl == -1) return "";
    return to_string(kl);
}

void ChungKhoan::parse(string line) {
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (getline(ss, token, '\t')) tokens.push_back(token);
    while (tokens.size() < 25) tokens.push_back("");

    strcpy(maCK, tokens[0].c_str());
    giaTran = stringToFloat(tokens[1]);
    giaSan  = stringToFloat(tokens[2]);
    giaTC   = stringToFloat(tokens[3]);
    giaMua[2] = stringToFloat(tokens[4]); klMua[2] = stringToLong(tokens[5]);
    giaMua[1] = stringToFloat(tokens[6]); klMua[1] = stringToLong(tokens[7]);
    giaMua[0] = stringToFloat(tokens[8]); klMua[0] = stringToLong(tokens[9]);
    giaKhop = stringToFloat(tokens[10]); klKhop = stringToLong(tokens[11]);
    thayDoi = stringToFloat(tokens[12]);
    giaBan[0] = stringToFloat(tokens[13]); klBan[0] = stringToLong(tokens[14]);
    giaBan[1] = stringToFloat(tokens[15]); klBan[1] = stringToLong(tokens[16]);
    giaBan[2] = stringToFloat(tokens[17]); klBan[2] = stringToLong(tokens[18]);
    tongKL = stringToLong(tokens[19]);
    moCua = stringToFloat(tokens[20]); caoNhat = stringToFloat(tokens[21]); thapNhat = stringToFloat(tokens[22]);
    nnMua = stringToLong(tokens[23]); nnBan = stringToLong(tokens[24]);
}

void ChungKhoan::hienThi() const {
    cout << left << setw(6) << maCK
         << right 
         << setw(10) << dinhdangGia(giaTran) << setw(10) << dinhdangGia(giaSan) << setw(10) << dinhdangGia(giaTC)
         << setw(16) << dinhdangCap(giaMua[2], klMua[2])
         << setw(16) << dinhdangCap(giaMua[1], klMua[1])
         << setw(16) << dinhdangCap(giaMua[0], klMua[0])
         << setw(10) << dinhdangGia(giaKhop)
         << setw(10) << dinhdangKl(klKhop)
         << setw(10) << dinhdangGia(thayDoi)
         << setw(16) << dinhdangCap(giaBan[0], klBan[0])
         << setw(16) << dinhdangCap(giaBan[1], klBan[1])
         << setw(16) << dinhdangCap(giaBan[2], klBan[2])
         << setw(10) << dinhdangKl(tongKL)
         << setw(10) << dinhdangGia(moCua) << setw(10) << dinhdangGia(caoNhat) << setw(10) << dinhdangGia(thapNhat)
         << setw(10) << dinhdangKl(nnMua) << setw(10) << dinhdangKl(nnBan)
         << endl;
}

float ChungKhoan::getGiaDongCua() const {
    if (std::isnan(giaKhop)) return 0.0f;
    return giaKhop;
}
long ChungKhoan::getKhoiLuongGiaoDich() const {
    if (tongKL == -1) return 0;
    return tongKL;
}