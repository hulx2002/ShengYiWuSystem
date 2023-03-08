#include <iostream>
#include "pingfensystem.h"
#include "wujiantao.h"

int main() {
    pingfensystem pfs(0, 0.55, 0, 1, 1, 1, 0);
    int ace = 210;
    int r;
    srand(time(NULL));
    rand();
    wujiantao wjt;
    int count = 0;
    shengzhihua* szh;
    sizhiyu* szy;
    shizhisha* szs;
    kongzhibei* kzb;
    lizhiguan* lzg;
    while (wjt.getscore() < ace) {
        count++;
        r = rand() % 2;
        if (r == 1) {
            continue;
        }
        r = rand() % 5;
        switch (r) {
        case 0:
            szh = new shengzhihua();
            szh->shengji20();
            pfs.pingfen(szh);
            if (wjt.getszh() == nullptr || wjt.getszh()->getscore() < szh->getscore()) {
                delete wjt.getszh();
                wjt.setszh(szh);
            }
            else {
                delete szh;
            }
            break;
        case 1:
            szy = new sizhiyu();
            szy->shengji20();
            pfs.pingfen(szy);
            if (wjt.getszy() == nullptr || wjt.getszy()->getscore() < szy->getscore()) {
                delete wjt.getszy();
                wjt.setszy(szy);
            }
            else {
                delete szy;
            }
            break;
        case 2:
            szs = new shizhisha();
            szs->shengji20();
            pfs.pingfen(szs);
            if (szs->getzct() == shizhisha::zhucitiao::z_yuansujingtong && (wjt.getszs() == nullptr || wjt.getszs()->getscore() < szs->getscore())) {
                delete wjt.getszs();
                wjt.setszs(szs);
            }
            else {
                delete szs;
            }
            break;
        case 3:
            kzb = new kongzhibei();
            kzb->shengji20();
            pfs.pingfen(kzb);
            if (kzb->getzct() == kongzhibei::zhucitiao::z_cao && (wjt.getkzb() == nullptr || wjt.getkzb()->getscore() < kzb->getscore())) {
                delete wjt.getkzb();
                wjt.setkzb(kzb);
            }
            else {
                delete kzb;
            }
            break;
        case 4:
            lzg = new lizhiguan();
            lzg->shengji20();
            pfs.pingfen(lzg);
            if ((lzg->getzct() == lizhiguan::zhucitiao::z_baojilv || lzg->getzct() == lizhiguan::zhucitiao::z_baojishanghai) && (wjt.getlzg() == nullptr || wjt.getlzg()->getscore() < lzg->getscore())) {
                delete wjt.getlzg();
                wjt.setlzg(lzg);
            }
            else {
                delete lzg;
            }
            break;
        }
    }
    std::cout << "刷本次数:" << count << std::endl;
    /*
    std::cout << "花:" << wjt.getszh()->getscore() << std::endl;
    std::cout << "羽毛:" << wjt.getszy()->getscore() << std::endl;
    std::cout << "时寄:" << wjt.getszs()->getscore() << std::endl;
    std::cout << "悲子:" << wjt.getkzb()->getscore() << std::endl;
    std::cout << "头:" << wjt.getlzg()->getscore() + 20 << std::endl;*/
    std::cout << std::endl;
    std::cout << "总分:" << wjt.getscore() << std::endl;
    std::cout << std::endl;
    wjt.getszh()->print();
    std::cout << std::endl;
    wjt.getszy()->print();
    std::cout << std::endl;
    wjt.getszs()->print();
    std::cout << std::endl;
    wjt.getkzb()->print();
    std::cout << std::endl;
    wjt.getlzg()->print();
}