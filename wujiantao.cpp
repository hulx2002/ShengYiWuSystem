#include "wujiantao.h"

wujiantao::wujiantao() {
    this->szh = nullptr;
    this->szy = nullptr;
    this->szs = nullptr;
    this->kzb = nullptr;
    this->lzg = nullptr;
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