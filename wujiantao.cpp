#include "wujiantao.h"

wujiantao::wujiantao() {
    this->szh = nullptr;
    this->szy = nullptr;
    this->szs = nullptr;
    this->kzb = nullptr;
    this->lzg = nullptr;
}

wujiantao::wujiantao(int szh_score, int szy_score, int szs_score, int kzb_score, int lzg_score) {
    this->szh = new shengzhihua();
    this->szh->setscore(szh_score);
    this->szy = new sizhiyu();
    this->szy->setscore(szy_score);
    this->szs = new shizhisha();
    this->szs->setscore(szs_score);
    this->kzb = new kongzhibei();
    this->kzb->setscore(kzb_score);
    this->lzg = new lizhiguan();
    this->lzg->setscore(lzg_score);
}

shengzhihua* wujiantao::getszh() {
    return this->szh;
}

sizhiyu* wujiantao::getszy() {
    return this->szy;
}

shizhisha* wujiantao::getszs() {
    return this->szs;
}

kongzhibei* wujiantao::getkzb() {
    return this->kzb;
}

lizhiguan* wujiantao::getlzg() {
    return this->lzg;
}

void wujiantao::setszh(shengzhihua* szh) {
    this->szh = szh;
}

void wujiantao::setszy(sizhiyu* szy) {
    this->szy = szy;
}

void wujiantao::setszs(shizhisha* szs) {
    this->szs = szs;
}

void wujiantao::setkzb(kongzhibei* kzb) {
    this->kzb = kzb;
}

void wujiantao::setlzg(lizhiguan* lzg) {
    this->lzg = lzg;
}

int wujiantao::getscore() {
    int score = 0;
    if (this->szh != nullptr) score += this->szh->getscore();
    if (this->szy != nullptr) score += this->szy->getscore();
    if (this->szs != nullptr) score += this->szs->getscore();
    if (this->kzb != nullptr) score += this->kzb->getscore();
    if (this->lzg != nullptr) score += this->lzg->getscore() + 20;
    return score;
}