#include "shengyiwu.h"

class lizhiguan : public shengyiwu {
public:
    enum zhucitiao {
        z_dashengming,
        z_dagongji,
        z_dafangyu,
        z_baojilv,
        z_baojishanghai,
        z_zhiliaojiacheng,
        z_yuansujingtong
    };
public:
    lizhiguan();
    void print();
    lizhiguan::zhucitiao getzct();
private:
    lizhiguan::zhucitiao zct;
};