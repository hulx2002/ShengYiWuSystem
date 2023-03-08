#include "shizhisha.h"
#include <iostream>

shizhisha::shizhisha() {
    double r;
    r = 100.0 * rand() / RAND_MAX;
    if (r < 26.68) {
        this->zct = z_dashengming;
    }
    else if (r < 53.34) {
        this->zct = z_dagongji;
    }
    else if (r < 80) {
        this->zct = z_dafangyu;
    }
    else if (r < 90) {
        this->zct = z_yuansuchongnengxiaolv;
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
        r = 100.0 * rand() / RAND_MAX;
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
            switch (this->zct) {
            case z_dashengming:
                fctzl[i] = dagongji;
                break;
            case z_dagongji:
                fctzl[i] = dashengming;
                break;
            case z_dafangyu:
                fctzl[i] = dashengming;
                break;
            case z_yuansuchongnengxiaolv:
                fctzl[i] = dashengming;
                break;
            case z_yuansujingtong:
                fctzl[i] = dashengming;
                break;
            }
        }
        else if (r < 65) {
            switch (this->zct) {
            case z_dashengming:
                fctzl[i] = dafangyu;
                break;
            case z_dagongji:
                fctzl[i] = dafangyu;
                break;
            case z_dafangyu:
                fctzl[i] = dagongji;
                break;
            case z_yuansuchongnengxiaolv:
                fctzl[i] = dagongji;
                break;
            case z_yuansujingtong:
                fctzl[i] = dagongji;
                break;
            }
        }
        else if (r < 75) {
            switch (this->zct) {
            case z_dashengming:
                fctzl[i] = yuansuchongnengxiaolv;
                break;
            case z_dagongji:
                fctzl[i] = yuansuchongnengxiaolv;
                break;
            case z_dafangyu:
                fctzl[i] = yuansuchongnengxiaolv;
                break;
            case z_yuansuchongnengxiaolv:
                fctzl[i] = dafangyu;
                break;
            case z_yuansujingtong:
                fctzl[i] = dafangyu;
                break;
            }
        }
        else if (r < 85) {
            switch (this->zct) {
            case z_dashengming:
                fctzl[i] = yuansujingtong;
                break;
            case z_dagongji:
                fctzl[i] = yuansujingtong;
                break;
            case z_dafangyu:
                fctzl[i] = yuansujingtong;
                break;
            case z_yuansuchongnengxiaolv:
                fctzl[i] = yuansujingtong;
                break;
            case z_yuansujingtong:
                fctzl[i] = yuansuchongnengxiaolv;
                break;
            }
        }
        else if (r < 92.5) {
            fctzl[i] = baojilv;
        }
        else {
            fctzl[i] = baojishanghai;
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

void shizhisha::print() {
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
    case z_yuansuchongnengxiaolv:
        std::cout << "元素充能效率" << std::endl;
        break;
    case z_yuansujingtong:
        std::cout << "元素精通" << std::endl;
        break;
    }
    this->print0();
}

shizhisha::zhucitiao shizhisha::getzct() {
    return this->zct;
}