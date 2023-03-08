#include "kongzhibei.h"
#include <iostream>

kongzhibei::kongzhibei() {
    double r;
    r = 100.0 * rand() / RAND_MAX;
    if (r < 19.175) {
        this->zct = z_dashengming;
    }
    else if (r < 38.35) {
        this->zct = z_dagongji;
    }
    else if (r < 57.5) {
        this->zct = z_dafangyu;
    }
    else if (r < 62.5) {
        this->zct = z_huo;
    }
    else if (r < 67.5) {
        this->zct = z_lei;
    }
    else if (r < 72.5) {
        this->zct = z_bing;
    }
    else if (r < 77.5) {
        this->zct = z_shui;
    }
    else if (r < 82.5) {
        this->zct = z_feng;
    }
    else if (r < 87.5) {
        this->zct = z_yan;
    }
    else if (r < 92.5) {
        this->zct = z_cao;
    }
    else if (r < 97.5) {
        this->zct = z_wuli;
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
        if ((this->zct == z_dashengming && fctzl[i] == dashengming) || (this->zct == z_dagongji && fctzl[i] == dagongji) || (this->zct == z_dafangyu && fctzl[i] == dafangyu) || (this->zct == z_yuansujingtong && fctzl[i] == yuansujingtong)) {
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

void kongzhibei::print() {
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
    case z_huo:
        std::cout << "火元素伤害加成" << std::endl;
        break;
    case z_lei:
        std::cout << "雷元素伤害加成" << std::endl;
        break;
    case z_bing:
        std::cout << "冰元素伤害加成" << std::endl;
        break;
    case z_shui:
        std::cout << "水元素伤害加成" << std::endl;
        break;
    case z_feng:
        std::cout << "风元素伤害加成" << std::endl;
        break;
    case z_yan:
        std::cout << "岩元素伤害加成" << std::endl;
        break;
    case z_cao:
        std::cout << "草元素伤害加成" << std::endl;
        break;
    case z_wuli:
        std::cout << "物理伤害加成" << std::endl;
        break;
    case z_yuansujingtong:
        std::cout << "元素精通" << std::endl;
        break;
    }
    this->print0();
}

kongzhibei::zhucitiao kongzhibei::getzct() {
    return this->zct;
}