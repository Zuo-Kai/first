#include <iostream>
#include <iomanip>
#include "StockInput.h"
#include "StockCalc.h"

using namespace std;

int main() {
    cout << "\n買入交易\n";

    double bp = ipprice("買入");
    int bs = ipstock("買入");

    double tb = cbtm(bp, bs);

    cout << "\n 賣出交易\n";

    double sp = ipprice("賣出");
    int ss = ipstock("賣出");

    double ts = cstm(sp, ss);

    double tt = ctt(tb, ts);

    cout << fixed << setprecision(2);

    cout << "\n結果顯示：\n";
    cout << "買入總成本（含手續費）： " << tb << " 元\n";
    cout << "賣出總收入（扣手續費及交易稅）： " << ts << " 元\n";
    cout << "盈虧金額： " << tt << " 元\n";

    return 0;
}
