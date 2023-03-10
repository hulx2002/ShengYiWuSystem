#include <iostream>
#include <vector>
#include <fstream>
#include "pingfensystem.h"
#include "wujiantao.h"

#define naxida
//#define hutao
//#define leidianjiangjun
//#define aierhaisen

#define fixace
//#define fixshuaben

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
#ifdef leidianjiangjun
    case 7:
#endif
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
#ifdef naxida
    case 8:
#endif
#ifdef hutao
    case 8:
#endif
#ifdef aierhaisen
    case 8:
#endif
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

#ifdef naxida
    std::vector<shizhisha::zhucitiao> szs_zct{shizhisha::zhucitiao::z_yuansujingtong};
    std::vector<kongzhibei::zhucitiao> kzb_zct{ kongzhibei::zhucitiao::z_cao };
    std::vector<lizhiguan::zhucitiao> lzg_zct{ lizhiguan::zhucitiao::z_baojilv, lizhiguan::zhucitiao::z_baojishanghai };
    double q_dashengming = 0, q_dagongji = 0.55, q_dafangyu = 0, q_baojilv = 1, q_baojishanghai = 1, q_yuansujingtong = 1, q_yuansuchongnengxiaolv = 0;
    int ace = 210;
    int score_current[5] = { 39, 43, 0, 40, 50 };
#endif

#ifdef hutao
    std::vector<shizhisha::zhucitiao> szs_zct{ shizhisha::zhucitiao::z_dashengming };
    std::vector<kongzhibei::zhucitiao> kzb_zct{ kongzhibei::zhucitiao::z_huo };
    std::vector<lizhiguan::zhucitiao> lzg_zct{ lizhiguan::zhucitiao::z_baojilv, lizhiguan::zhucitiao::z_baojishanghai };
    double q_dashengming = 0.8, q_dagongji = 0.5, q_dafangyu = 0, q_baojilv = 1, q_baojishanghai = 1, q_yuansujingtong = 0.75, q_yuansuchongnengxiaolv = 0;
    int ace = 226;
    int score_current[5] = { 0, 0, 0, 46, 54 };
#endif

#ifdef leidianjiangjun
    std::vector<shizhisha::zhucitiao> szs_zct{ shizhisha::zhucitiao::z_yuansuchongnengxiaolv };
    std::vector<kongzhibei::zhucitiao> kzb_zct{ kongzhibei::zhucitiao::z_dagongji };
    std::vector<lizhiguan::zhucitiao> lzg_zct{ lizhiguan::zhucitiao::z_baojilv, lizhiguan::zhucitiao::z_baojishanghai };
    double q_dashengming = 0, q_dagongji = 0.75, q_dafangyu = 0, q_baojilv = 1, q_baojishanghai = 1, q_yuansujingtong = 0, q_yuansuchongnengxiaolv = 0.75;
    int ace = 215;
    int score_current[5] = { 0, 0, 39, 0, 53 };
#endif

#ifdef aierhaisen
    std::vector<shizhisha::zhucitiao> szs_zct{ shizhisha::zhucitiao::z_yuansujingtong };
    std::vector<kongzhibei::zhucitiao> kzb_zct{ kongzhibei::zhucitiao::z_cao };
    std::vector<lizhiguan::zhucitiao> lzg_zct{ lizhiguan::zhucitiao::z_baojilv, lizhiguan::zhucitiao::z_baojishanghai };
    double q_dashengming = 0, q_dagongji = 0.75, q_dafangyu = 0, q_baojilv = 1, q_baojishanghai = 1, q_yuansujingtong = 1, q_yuansuchongnengxiaolv = 0;
    int ace = 220;
    int score_current[5] = { 0, 0, 0, 0, 59 };
#endif

    pingfensystem pfs(q_dashengming, q_dagongji, q_dafangyu, q_baojilv, q_baojishanghai, q_yuansujingtong, q_yuansuchongnengxiaolv);
    int r;
    srand(time(NULL));
    rand();

#ifdef fixace
    int sum_count_shuaben = 0;
    int count_ace = 10000;
    int score_ace[5] = { 0, 0, 0, 0, 0 };
    std::ofstream file;
    file.open("../../out/fixace_out.txt");
    for (int i = 0; i < count_ace; i++) {
        wujiantao wjt(score_current);
        int count_shuaben = 0;
        while (wjt.getscore() < ace) {
            count_shuaben++;
            double r = 100.0 * rand() / RAND_MAX;
            shuaben(wjt, pfs, szs_zct, kzb_zct, lzg_zct);
            if (r < 7) shuaben(wjt, pfs, szs_zct, kzb_zct, lzg_zct);
        }
        sum_count_shuaben += count_shuaben;
        file << count_shuaben << std::endl;
        score_ace[0] += wjt.getszh()->getscore();
        score_ace[1] += wjt.getszy()->getscore();
        score_ace[2] += wjt.getszs()->getscore();
        score_ace[3] += wjt.getkzb()->getscore();
        score_ace[4] += wjt.getlzg()->getscore();
    }
    file.close();
    std::cout << "平均刷本次数:" << sum_count_shuaben / count_ace << std::endl;
    std::cout << "生之花平均得分:" << score_ace[0] / count_ace << std::endl;
    std::cout << "死之羽平均得分:" << score_ace[1] / count_ace << std::endl;
    std::cout << "时之沙平均得分:" << score_ace[2] / count_ace << std::endl;
    std::cout << "空之杯平均得分:" << score_ace[3] / count_ace << std::endl;
    std::cout << "理之冠平均得分:" << score_ace[4] / count_ace + 20 << std::endl;
#endif

#ifdef fixshuaben
    int count_shuaben = 900;
    int count_shiyan = 10000;
    int count_ace = 0;
    int score_ace[5] = { 0, 0, 0, 0, 0 };

    for (int i = 0; i < count_shiyan; i++) {
        wujiantao wjt(score_current);
        for (int j = 0; j < count_shuaben; j++) {
            double r = 100.0 * rand() / RAND_MAX;
            shuaben(wjt, pfs, szs_zct, kzb_zct, lzg_zct);
            if (r < 7) shuaben(wjt, pfs, szs_zct, kzb_zct, lzg_zct);
        }
        if (wjt.getscore() >= ace) {
            count_ace++;
        }
        score_ace[0] += wjt.getszh()->getscore();
        score_ace[1] += wjt.getszy()->getscore();
        score_ace[2] += wjt.getszs()->getscore();
        score_ace[3] += wjt.getkzb()->getscore();
        score_ace[4] += wjt.getlzg()->getscore();
    }
    std::cout << "ACE概率:" << 100.0 * count_ace / count_shiyan << "%" << std::endl;
    std::cout << "生之花平均得分:" << score_ace[0] / count_shiyan << std::endl;
    std::cout << "死之羽平均得分:" << score_ace[1] / count_shiyan << std::endl;
    std::cout << "时之沙平均得分:" << score_ace[2] / count_shiyan << std::endl;
    std::cout << "空之杯平均得分:" << score_ace[3] / count_shiyan << std::endl;
    std::cout << "理之冠平均得分:" << score_ace[4] / count_shiyan + 20 << std::endl;
#endif
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