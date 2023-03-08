#include "shengyiwu.h"

class shizhisha : public shengyiwu {
public:
    enum zhucitiao {
        z_dashengming,
        z_dagongji,
        z_dafangyu,
        z_yuansuchongnengxiaolv,
        z_yuansujingtong
    };
public:
    shizhisha();
    void print();
    shizhisha::zhucitiao getzct();
private:
    shizhisha::zhucitiao zct;
};