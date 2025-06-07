#include "StockCalc.h"
#include <cmath> // 為了使用 round()

// 台股手續費率
const double feesg = 0.001425;
// 台股交易稅率（只在賣出收）
const double taxg = 0.003;

// 四捨五入整數元
int ff(int 金額) {
    return static_cast<int>(round(金額));
}

// 買入總成本：價格 * 股數 + 手續費（四捨五入）
double cbtm(double price, int stock) {
    double sm = price * stock;
    int fees = ff(sm * feesg);
    return sm + fees;
}

// 賣出總收入：價格 * 股數 - 手續費 - 交易稅（都四捨五入）
double cstm(double price, int stock) {
    double sm = price * stock;
    int fees = ff(sm * feesg);
    int tax = ff(sm * taxg);
    return sm - fees - tax;
}

double ctt(double 買入成本, double 賣出收入) {
    return 賣出收入 - 買入成本;
}
