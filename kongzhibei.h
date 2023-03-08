#include "shengyiwu.h"

class kongzhibei : public shengyiwu {
public:
    enum zhucitiao {
        z_dashengming,
        z_dagongji,
        z_dafangyu,
        z_huo,
        z_lei,
        z_bing,
        z_shui,
        z_feng,
        z_yan,
        z_cao,
        z_wuli,
        z_yuansujingtong
    };
public:
    kongzhibei();
    void print();
    kongzhibei::zhucitiao getzct();
private:
    kongzhibei::zhucitiao zct;
};