#include "shengzhihua.h"
#include "sizhiyu.h"
#include "shizhisha.h"
#include "kongzhibei.h"
#include "lizhiguan.h"

class wujiantao {
public:
    wujiantao();
    wujiantao(int score_current[]);
    shengzhihua* getszh();
    sizhiyu* getszy();
    shizhisha* getszs();
    kongzhibei* getkzb();
    lizhiguan* getlzg();
    void setszh(shengzhihua* szh);
    void setszy(sizhiyu* szy);
    void setszs(shizhisha* szs);
    void setkzb(kongzhibei* kzb);
    void setlzg(lizhiguan* lzg);
    int getscore();
private:
    shengzhihua* szh;
    sizhiyu* szy;
    shizhisha* szs;
    kongzhibei* kzb;
    lizhiguan* lzg;
};