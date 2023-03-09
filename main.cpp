#include <iostream>
#include <vector>
#include "pingfensystem.h"
#include "wujiantao.h"

void shuaben(wujiantao& wjt, pingfensystem& pfs, std::vector<shizhisha::zhucitiao> szs_zct, std::vector<kongzhibei::zhucitiao> kzb_zct, std::vector<lizhiguan::zhucitiao> lzg_zct) {
    int r;
    r = rand() % 10;
    shengzhihua* szh;
    sizhiyu* szy;
    shizhisha* szs;
    kongzhibei* kzb;
    lizhiguan* lzg;
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
        if (std::find(szs_zct.begin(), szs_zct.end(), szs->getzct()) == szs_zct.end()) {
            delete szs;
            break;
        }
        szs->shengji20();
        pfs.pingfen(szs);
        if (wjt.getszs() == nullptr || wjt.getszs()->getscore() < szs->getscore()) {
            delete wjt.getszs();
            wjt.setszs(szs);
        }
        else {
            delete szs;
        }
        break;
    case 3:
    case 8:
        kzb = new kongzhibei();
        if (std::find(kzb_zct.begin(), kzb_zct.end(), kzb->getzct()) == kzb_zct.end()) {
            delete kzb;
            break;
        }
        kzb->shengji20();
        pfs.pingfen(kzb);
        if (wjt.getkzb() == nullptr || wjt.getkzb()->getscore() < kzb->getscore()) {
            delete wjt.getkzb();
            wjt.setkzb(kzb);
        }
        else {
            delete kzb;
        }
        break;
    case 4:
        lzg = new lizhiguan();
        if (std::find(lzg_zct.begin(), lzg_zct.end(), lzg->getzct()) == lzg_zct.end()) {
            delete lzg;
            break;
        }
        lzg->shengji20();
        pfs.pingfen(lzg);
        if (wjt.getlzg() == nullptr || wjt.getlzg()->getscore() < lzg->getscore()) {
            delete wjt.getlzg();
            wjt.setlzg(lzg);
        }
        else {
            delete lzg;
        }
        break;
    }
}

int main() {
    std::vector<shizhisha::zhucitiao> szs_zct{shizhisha::zhucitiao::z_yuansujingtong};
    std::vector<kongzhibei::zhucitiao> kzb_zct{kongzhibei::zhucitiao::z_cao, kongzhibei::zhucitiao::z_yuansujingtong};
    std::vector<lizhiguan::zhucitiao> lzg_zct{lizhiguan::zhucitiao::z_baojilv, lizhiguan::zhucitiao::z_baojishanghai, lizhiguan::zhucitiao::z_yuansujingtong};
    double q_dashengming = 0, q_dagongji = 0.55, q_dafangyu = 0, q_baojilv = 1, q_baojishanghai = 1, q_yuansujingtong = 1, q_yuansuchongnengxiaolv = 0;
    int ace = 210;
    pingfensystem pfs(q_dashengming, q_dagongji, q_dafangyu, q_baojilv, q_baojishanghai, q_yuansujingtong, q_yuansuchongnengxiaolv);
    int r;
    srand(time(NULL));
    rand();
    int count_shuaben = 0;
    int count_ace = 100;
    int szh_score_ace = 0;
    int szy_score_ace = 0;
    int szs_score_ace = 0;
    int kzb_score_ace = 0;
    int lzg_score_ace = 0;

    for (int i = 0; i < count_ace; i++) {
        wujiantao wjt;
        while (wjt.getscore() < ace) {
            count_shuaben++;
            shuaben(wjt, pfs, szs_zct, kzb_zct, lzg_zct);
        }
        szh_score_ace += wjt.getszh()->getscore();
        szy_score_ace += wjt.getszy()->getscore();
        szs_score_ace += wjt.getszs()->getscore();
        kzb_score_ace += wjt.getkzb()->getscore();
        lzg_score_ace += wjt.getlzg()->getscore();
    }
    std::cout << "平均刷本次数:" << count_shuaben / count_ace << std::endl;
    std::cout << "生之花平均得分:" << szh_score_ace / count_ace << std::endl;
    std::cout << "死之羽平均得分:" << szy_score_ace / count_ace << std::endl;
    std::cout << "时之沙平均得分:" << szs_score_ace / count_ace << std::endl;
    std::cout << "空之杯平均得分:" << kzb_score_ace / count_ace << std::endl;
    std::cout << "理之冠平均得分:" << lzg_score_ace / count_ace << std::endl;
    /*
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
    */
}