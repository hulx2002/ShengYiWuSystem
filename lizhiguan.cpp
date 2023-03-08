#include "lizhiguan.h"
#include <iostream>

lizhiguan::lizhiguan() {
    double r;
    r = 100.0 * rand() / RAND_MAX;
    if (r < 22) {
        this->zct = z_dashengming;
    }
    else if (r < 44) {
        this->zct = z_dagongji;
    }
    else if (r < 66) {
        this->zct = z_dafangyu;
    }
    else if (r < 76) {
        this->zct = z_baojilv;
    }
    else if (r < 86) {
        this->zct = z_baojishanghai;
    }
    else if (r < 96) {
        this->zct = z_zhiliaojiacheng;
    }
    else {
        this->zct = z_yuansujingtong;
    }
    shengyiwu::fucitiaozhonglei fctzl[4];
    r = 100.0 * rand() / RAND_MAX;
    if (r < 80.0) {
        this->setlevel(4);
    }
    else {
        this->setlevel(0);
    }
    for (int i = 0; i < 4; i++) {
        r = 110.0 * rand() / RAND_MAX;
        if (r < 15) {
            fctzl[i] = xiaoshengming;
        }
        else if (r < 30) {
            fctzl[i] = xiaogongji;
        }
        else if (r < 45) {
            fctzl[i] = xiaofangyu;
        }
        else if (r < 55) {
            fctzl[i] = dashengming;
        }
        else if (r < 65) {
            fctzl[i] = dagongji;
        }
        else if (r < 75) {
            fctzl[i] = dafangyu;
        }
        else if (r < 85) {
            fctzl[i] = yuansuchongnengxiaolv;
        }
        else if (r < 95) {
            fctzl[i] = yuansujingtong;
        }
        else if (r < 102.5) {
            fctzl[i] = baojilv;
        }
        else {
            fctzl[i] = baojishanghai;
        }
        if ((this->zct == z_dashengming && fctzl[i] == dashengming) || (this->zct == z_dagongji && fctzl[i] == dagongji) || (this->zct == z_dafangyu && fctzl[i] == dafangyu) || (this->zct == z_baojilv && fctzl[i] == baojilv) || (this->zct == z_baojishanghai && fctzl[i] == baojishanghai) || (this->zct == z_yuansujingtong && fctzl[i] == yuansujingtong)) {
            i--;
        }
        for (int j = 0; j < i; j++) {
            if (fctzl[i] == fctzl[j]) {
                i--;
                break;
            }
        }
    }
    this->setzhonglei(fctzl);
    this->initshuzhi();
    this->setscore(-1);
}

void lizhiguan::print() {
    std::cout << this->getscore() << "分" << std::endl;
    switch (this->zct) {
    case z_dashengming:
        std::cout << "生命值" << std::endl;
        break;
    case z_dagongji:
        std::cout << "攻击力" << std::endl;
        break;
    case z_dafangyu:
        std::cout << "防御力" << std::endl;
        break;
    case z_baojilv:
        std::cout << "暴击率" << std::endl;
        break;
    case z_baojishanghai:
        std::cout << "暴击伤害" << std::endl;
        break;
    case z_zhiliaojiacheng:
        std::cout << "治疗加成" << std::endl;
        break;
    case z_yuansujingtong:
        std::cout << "元素精通" << std::endl;
        break;
    }
    this->print0();
}

lizhiguan::zhucitiao lizhiguan::getzct() {
    return this->zct;
}