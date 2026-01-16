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

    long tongKL;                 // TỔNG KHỐI LƯỢNG GIAO DỊCH TRONG NGÀY
    float moCua, caoNhat, thapNhat;

    long nnMua, nnBan;

    void parse(string line);
    void hienThi() const;

    // ===== GETTER CHUẨN THEO ĐỀ =====
    float getGiaDongCua() const;
    long getKhoiLuongGiaoDich() const;
};
