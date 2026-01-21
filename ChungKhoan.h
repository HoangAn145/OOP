#pragma once
#include <string>
using namespace std;

class ChungKhoan {
public:
    char maCK[10];
    float giaTran, giaSan, giaTC;
    
    float giaMua[3];
    long klMua[3];

    float giaKhop;
    long klKhop;
    float thayDoi;

    float giaBan[3];
    long klBan[3];

    long tongKL;
    float moCua, caoNhat, thapNhat;

    long nnMua, nnBan;

    void parse(string line);
    void hienThi() const;
    float getGiaDongCua() const;
    long getKhoiLuongGiaoDich() const;
};