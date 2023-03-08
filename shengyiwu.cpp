#include "shengyiwu.h"
#include <iostream>

void shengyiwu::setzhonglei(shengyiwu::fucitiaozhonglei fctzl[]) {
    this->fctzl[0] = fctzl[0];
    this->fctzl[1] = fctzl[1];
    this->fctzl[2] = fctzl[2];
    this->fctzl[3] = fctzl[3];
}

shengyiwu::fucitiaozhonglei* shengyiwu::getzhonglei() {
    return this->fctzl;
}

double* shengyiwu::getshuzhi() {
    return this->fctsz;
}

void shengyiwu::setlevel(int level) {
    this->level = level;
}

void shengyiwu::initshuzhi() {
    double r;
    for (int i = 0; i < 4; i++) {
        r = 100.0 * rand() / RAND_MAX;
        switch (this->fctzl[i]) {
        case baojilv:
            if (r < 25) this->fctsz[i] = 2.7;
            else if (r < 50) this->fctsz[i] = 3.11;
            else if (r < 75) this->fctsz[i] = 3.5;
            else this->fctsz[i] = 3.89;
            break;
        case baojishanghai:
            if (r < 25) this->fctsz[i] = 5.44;
            else if (r < 50) this->fctsz[i] = 6.22;
            else if (r < 75) this->fctsz[i] = 6.99;
            else this->fctsz[i] = 7.77;
            break;
        case dagongji:
            if (r < 25) this->fctsz[i] = 4.08;
            else if (r < 50) this->fctsz[i] = 4.66;
            else if (r < 75) this->fctsz[i] = 5.25;
            else this->fctsz[i] = 5.83;
            break;
        case xiaogongji:
            if (r < 25) this->fctsz[i] = 13.62;
            else if (r < 50) this->fctsz[i] = 15.56;
            else if (r < 75) this->fctsz[i] = 17.51;
            else this->fctsz[i] = 19.45;
            break;
        case dashengming:
            if (r < 25) this->fctsz[i] = 4.08;
            else if (r < 50) this->fctsz[i] = 4.66;
            else if (r < 75) this->fctsz[i] = 5.25;
            else this->fctsz[i] = 5.83;
            break;
        case xiaoshengming:
            if (r < 25) this->fctsz[i] = 209.13;
            else if (r < 50) this->fctsz[i] = 239;
            else if (r < 75) this->fctsz[i] = 268.88;
            else this->fctsz[i] = 298.75;
            break;
        case dafangyu:
            if (r < 25) this->fctsz[i] = 5.1;
            else if (r < 50) this->fctsz[i] = 5.83;
            else if (r < 75) this->fctsz[i] = 6.56;
            else this->fctsz[i] = 7.29;
            break;
        case xiaofangyu:
            if (r < 25) this->fctsz[i] = 16.2;
            else if (r < 50) this->fctsz[i] = 18.52;
            else if (r < 75) this->fctsz[i] = 20.83;
            else this->fctsz[i] = 23.15;
            break;
        case yuansujingtong:
            if (r < 25) this->fctsz[i] = 16.32;
            else if (r < 50) this->fctsz[i] = 18.65;
            else if (r < 75) this->fctsz[i] = 20.98;
            else this->fctsz[i] = 23.31;
            break;
        case yuansuchongnengxiaolv:
            if (r < 25) this->fctsz[i] = 4.53;
            else if (r < 50) this->fctsz[i] = 5.18;
            else if (r < 75) this->fctsz[i] = 5.83;
            else this->fctsz[i] = 6.48;
            break;
        }
    }
}

void shengyiwu::shengji4() {
    double r;
    int i;
    this->level += 4;
    r = 100.0 * rand() / RAND_MAX;
    if (r < 25) i = 0;
    else if (r < 50) i = 1;
    else if (r < 75) i = 2;
    else i = 3;
    r = 100.0 * rand() / RAND_MAX;
    switch (this->fctzl[i]) {
    case baojilv:
        if (r < 25) this->fctsz[i] += 2.7;
        else if (r < 50) this->fctsz[i] += 3.11;
        else if (r < 75) this->fctsz[i] += 3.5;
        else this->fctsz[i] += 3.89;
        break;
    case baojishanghai:
        if (r < 25) this->fctsz[i] += 5.44;
        else if (r < 50) this->fctsz[i] += 6.22;
        else if (r < 75) this->fctsz[i] += 6.99;
        else this->fctsz[i] += 7.77;
        break;
    case dagongji:
        if (r < 25) this->fctsz[i] += 4.08;
        else if (r < 50) this->fctsz[i] += 4.66;
        else if (r < 75) this->fctsz[i] += 5.25;
        else this->fctsz[i] += 5.83;
        break;
    case xiaogongji:
        if (r < 25) this->fctsz[i] += 13.62;
        else if (r < 50) this->fctsz[i] += 15.56;
        else if (r < 75) this->fctsz[i] += 17.51;
        else this->fctsz[i] += 19.45;
        break;
    case dashengming:
        if (r < 25) this->fctsz[i] += 4.08;
        else if (r < 50) this->fctsz[i] += 4.66;
        else if (r < 75) this->fctsz[i] += 5.25;
        else this->fctsz[i] += 5.83;
        break;
    case xiaoshengming:
        if (r < 25) this->fctsz[i] += 209.13;
        else if (r < 50) this->fctsz[i] += 239;
        else if (r < 75) this->fctsz[i] += 268.88;
        else this->fctsz[i] += 298.75;
        break;
    case dafangyu:
        if (r < 25) this->fctsz[i] += 5.1;
        else if (r < 50) this->fctsz[i] += 5.83;
        else if (r < 75) this->fctsz[i] += 6.56;
        else this->fctsz[i] += 7.29;
        break;
    case xiaofangyu:
        if (r < 25) this->fctsz[i] += 16.2;
        else if (r < 50) this->fctsz[i] += 18.52;
        else if (r < 75) this->fctsz[i] += 20.83;
        else this->fctsz[i] += 23.15;
        break;
    case yuansujingtong:
        if (r < 25) this->fctsz[i] += 16.32;
        else if (r < 50) this->fctsz[i] += 18.65;
        else if (r < 75) this->fctsz[i] += 20.98;
        else this->fctsz[i] += 23.31;
        break;
    case yuansuchongnengxiaolv:
        if (r < 25) this->fctsz[i] += 4.53;
        else if (r < 50) this->fctsz[i] += 5.18;
        else if (r < 75) this->fctsz[i] += 5.83;
        else this->fctsz[i] += 6.48;
        break;
    }
}

void shengyiwu::shengji20() {
    while (this->level < 20) {
        this->shengji4();
    }
}

void shengyiwu::print0() {
    std::cout << "+" << this->level << std::endl;
    for (int i = 0; i < 4; i++) {
        switch (this->fctzl[i]) {
        case baojilv:
            std::cout << "暴击率+";
            break;
        case baojishanghai:
            std::cout << "暴击伤害+";
            break;
        case dagongji:
            std::cout << "攻击力+";
            break;
        case xiaogongji:
            std::cout << "攻击力+";
            break;
        case dashengming:
            std::cout << "生命值+";
            break;
        case xiaoshengming:
            std::cout << "生命值+";
            break;
        case dafangyu:
            std::cout << "防御力+";
            break;
        case xiaofangyu:
            std::cout << "防御力+";
            break;
        case yuansujingtong:
            std::cout << "元素精通+";
            break;
        case yuansuchongnengxiaolv:
            std::cout << "元素充能效率+";
            break;
        }
        std::cout << this->fctsz[i];
        switch (this->fctzl[i]) {
        case baojilv:
            std::cout << "%" << std::endl;
            break;
        case baojishanghai:
            std::cout << "%" << std::endl;
            break;
        case dagongji:
            std::cout << "%" << std::endl;
            break;
        case xiaogongji:
            std::cout << std::endl;
            break;
        case dashengming:
            std::cout << "%" << std::endl;
            break;
        case xiaoshengming:
            std::cout << std::endl;
            break;
        case dafangyu:
            std::cout << "%" << std::endl;
            break;
        case xiaofangyu:
            std::cout << std::endl;
            break;
        case yuansujingtong:
            std::cout << std::endl;
            break;
        case yuansuchongnengxiaolv:
            std::cout << "%" << std::endl;
            break;
        }
    }
}

void shengyiwu::setscore(int score) {
    this->score = score;
}

int shengyiwu::getscore() {
    return this->score;
}
