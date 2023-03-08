#include "sizhiyu.h"
#include <iostream>

sizhiyu::sizhiyu() {
    double r;
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
        if (r < 15.79) {
            fctzl[i] = xiaoshengming;
        }
        else if (r < 31.58) {
            fctzl[i] = xiaofangyu;
        }
        else if (r < 42.11) {
            fctzl[i] = dashengming;
        }
        else if (r < 52.64) {
            fctzl[i] = dagongji;
        }
        else if (r < 63.17) {
            fctzl[i] = dafangyu;
        }
        else if (r < 73.7) {
            fctzl[i] = yuansuchongnengxiaolv;
        }
        else if (r < 84.23) {
            fctzl[i] = yuansujingtong;
        }
        else if (r < 92.12) {
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

void sizhiyu::print() {
    std::cout << this->getscore() << "·Ö" << std::endl;
    std::cout << "¹¥»÷Á¦" << std::endl;
    this->print0();
}
