#pragma once

class shengyiwu {
public:
    enum fucitiaozhonglei {
        baojilv,
        baojishanghai,
        dagongji,
        xiaogongji,
        dashengming,
        xiaoshengming,
        dafangyu,
        xiaofangyu,
        yuansujingtong,
        yuansuchongnengxiaolv,
    };
public:
    void setzhonglei(shengyiwu::fucitiaozhonglei fctzl[]);
    shengyiwu::fucitiaozhonglei* getzhonglei();
    double* getshuzhi();
    void setlevel(int level);
    void initshuzhi();
    void shengji4();
    void shengji20();
    void print0();
    void setscore(int score);
    int getscore();
private:
    int level;
    shengyiwu::fucitiaozhonglei fctzl[4];
    double fctsz[4];
    int score;
};