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
    if (s_clean.empty()) return NAN;
    try { return stof(s_clean); } catch (...) { return NAN; }
}

long stringToLong(string s) {
    if (s.empty()) return -1;
    string s_clean = clean(s);
    if (s_clean.empty()) return -1;
    try { return stol(s_clean); } catch (...) { return -1; }
}

string formatPair(float gia, long kl) {
    stringstream ss;
    if (std::isnan(gia) && kl == -1) return "";
    if (!std::isnan(gia)) ss << fixed << setprecision(2) << gia; else ss << "   ";
    ss << "/";
    if (kl != -1) ss << kl; else ss << "   ";
    return ss.str();
}

string formatPrice(float gia) {
    if (std::isnan(gia)) return "";
    stringstream ss;
    ss << fixed << setprecision(2) << gia;
    return ss.str();
}

string formatVol(long kl) {
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
    const int W_MA = 6, W_GIA = 7, W_PAIR = 16, W_VOL = 10;
    cout << left << setw(W_MA) << maCK
         << right 
         << setw(W_GIA) << formatPrice(giaTran) << setw(W_GIA) << formatPrice(giaSan) << setw(W_GIA) << formatPrice(giaTC)
         << setw(W_PAIR) << formatPair(giaMua[2], klMua[2])
         << setw(W_PAIR) << formatPair(giaMua[1], klMua[1])
         << setw(W_PAIR) << formatPair(giaMua[0], klMua[0])
         << setw(W_PAIR) << formatPair(giaKhop, klKhop)
         << setw(W_GIA) << formatPrice(thayDoi)
         << setw(W_PAIR) << formatPair(giaBan[0], klBan[0])
         << setw(W_PAIR) << formatPair(giaBan[1], klBan[1])
         << setw(W_PAIR) << formatPair(giaBan[2], klBan[2])
         << setw(W_VOL) << formatVol(tongKL)
         << setw(W_GIA) << formatPrice(moCua) << setw(W_GIA) << formatPrice(caoNhat) << setw(W_GIA) << formatPrice(thapNhat)
         << setw(W_VOL) << formatVol(nnMua) << setw(W_VOL) << formatVol(nnBan)
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