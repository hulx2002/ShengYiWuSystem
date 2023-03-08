#include "pingfensystem.h"

pingfensystem::pingfensystem() {
    this->q_dashengming = 0.0;
    this->q_dagongji = 0.0;
    this->q_dafangyu = 0.0;
    this->q_baojilv = 0.0;
    this->q_baojishanghai = 0.0;
    this->q_yuansujingtong = 0.0;
    this->q_yuansuchongnengxiaolv = 0.0;
}

pingfensystem::pingfensystem(double q_dashengming, double q_dagongji, double q_dafangyu, double q_baojilv, double q_baojishanghai, double q_yuansujingtong, double q_yuansuchongnengxiaolv) {
    this->q_dashengming = q_dashengming;
    this->q_dagongji = q_dagongji;
    this->q_dafangyu = q_dafangyu;
    this->q_baojilv = q_baojilv;
    this->q_baojishanghai = q_baojishanghai;
    this->q_yuansujingtong = q_yuansujingtong;
    this->q_yuansuchongnengxiaolv = q_yuansuchongnengxiaolv;
}

void pingfensystem::setquanzhong(double q_dashengming, double q_dagongji, double q_dafangyu, double q_baojilv, double q_baojishanghai, double q_yuansujingtong, double q_yuansuchongnengxiaolv) {
    this->q_dashengming = q_dashengming;
    this->q_dagongji = q_dagongji;
    this->q_dafangyu = q_dafangyu;
    this->q_baojilv = q_baojilv;
    this->q_baojishanghai = q_baojishanghai;
    this->q_yuansujingtong = q_yuansujingtong;
    this->q_yuansuchongnengxiaolv = q_yuansuchongnengxiaolv;
}

void pingfensystem::pingfen(shengyiwu* syw) {
    double score = 0.0;
    for (int i = 0; i < 4; i++) {
        switch (syw->getzhonglei()[i]) {
        case shengyiwu::fucitiaozhonglei::baojilv:
            score += syw->getshuzhi()[i] * 2 * this->q_baojilv;
            break;
        case shengyiwu::fucitiaozhonglei::baojishanghai:
            score += syw->getshuzhi()[i] * 1 * this->q_baojishanghai;
            break;
        case shengyiwu::fucitiaozhonglei::yuansujingtong:
            score += syw->getshuzhi()[i] * 0.33 * this->q_yuansujingtong;
            break;
        case shengyiwu::fucitiaozhonglei::yuansuchongnengxiaolv:
            score += syw->getshuzhi()[i] * 1.1979 * this->q_yuansuchongnengxiaolv;
            break;
        case shengyiwu::fucitiaozhonglei::dagongji:
            score += syw->getshuzhi()[i] * 1.33 * this->q_dagongji;
            break;
        case shengyiwu::fucitiaozhonglei::dashengming:
            score += syw->getshuzhi()[i] * 1.33 * this->q_dashengming;
            break;
        case shengyiwu::fucitiaozhonglei::dafangyu:
            score += syw->getshuzhi()[i] * 1.06 * this->q_dafangyu;
            break;
        case shengyiwu::fucitiaozhonglei::xiaogongji:
            score += syw->getshuzhi()[i] * 0.398 * 0.5 * this->q_dagongji;
            break;
        case shengyiwu::fucitiaozhonglei::xiaoshengming:
            score += syw->getshuzhi()[i] * 0.026 * 0.66 * this->q_dashengming;
            break;
        case shengyiwu::fucitiaozhonglei::xiaofangyu:
            score += syw->getshuzhi()[i] * 0.335 * 0.66 * this->q_dafangyu;
            break;
        }
    }
    syw->setscore(int(score));
}