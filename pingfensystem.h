#include "shengyiwu.h"

class pingfensystem {
public:
    pingfensystem();
    pingfensystem(double q_dashengming, double q_dagongji, double q_dafangyu, double q_baojilv, double q_baojishanghai, double q_yuansujingtong, double q_yuansuchongnengxiaolv);
    void setquanzhong(double q_dashengming, double q_dagongji, double q_dafangyu, double q_baojilv, double q_baoshanghai, double q_yuansujingtong, double q_yuansuchongnengxiaolv);
    void pingfen(shengyiwu* syw);
private:
    double q_dashengming, q_dagongji, q_dafangyu, q_baojilv, q_baojishanghai, q_yuansujingtong, q_yuansuchongnengxiaolv;
};