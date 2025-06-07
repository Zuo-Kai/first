#  第14組 資工1B
### 成員
#### 蕭祚愷
####  張凱勛
####  劉彥廷
###  小專題題目
####  台股股票買賣手續費計算
###  使用方法
##### 輸入買入價，選擇買入張數/股數，再輸入賣出價，賣出張數/股數後會產生最後損益的價格
### 程式碼介紹
###### main.cpp
程式碼
#include <iostream>
#include <iomanip>
#include "StockInput.h"
#include "StockCalc.h"

using namespace std;

int main() {
    cout << "\n📥 買入交易\n";

    double 買入價 = 輸入價格("買入");
    int 買入股數 = 輸入股數("買入");

    double 總買入 = 計算買入總成本(買入價, 買入股數);

    cout << "\n📤 賣出交易\n";

    double 賣出價 = 輸入價格("賣出");
    int 賣出股數 = 輸入股數("賣出");

    double 總賣出 = 計算賣出總收入(賣出價, 賣出股數);

    double 盈虧 = 計算盈虧(總買入, 總賣出);

    cout << fixed << setprecision(2);

    cout << "\n📊 結果顯示：\n";
    cout << "買入總成本（含手續費）： " << 總買入 << " 元\n";
    cout << "賣出總收入（扣手續費及交易稅）： " << 總賣出 << " 元\n";
    cout << "盈虧金額： " << 盈虧 << " 元\n";

    return 0;
}
逐行解說
第1行：引入標準輸入輸出庫，提供 cout 和 cin 功能
第2行：引入格式控制庫，能設定輸出小數點位數
第3行：引入自訂的輸入函式宣告，用於讀取價格與股數
第4行：引入自訂的計算函式宣告，用於計算成本與盈虧
第6行：使用標準命名空間，免去每次寫 std::
第8行：主程式進入點，回傳整數型態
第9行：輸出買入交易提示，換行
第11行：呼叫輸入價格函式，讀取買入價格，並存入變數
第12行：呼叫輸入股數函式，讀取買入股數（或張數轉股數），存入變數
第14行：計算買入時總成本（含手續費），存入變數
第16行：輸出賣出交易提示，換行
第18行：呼叫輸入價格函式，讀取賣出價格，並存入變數
第19行：呼叫輸入股數函式，讀取賣出股數，存入變數
第21行：計算賣出時總收入（扣除手續費與交易稅），存入變數
第23行：計算賣出收入減去買入成本的盈虧金額
第25行：設定輸出格式為固定小數點，保留兩位小數
第27行：輸出結果標題並換行
第28行：顯示買入總成本
第29行：顯示賣出總收入
第30行：顯示盈虧結果
第32行：程式正常結束回傳0
StockInput.h
程式碼
#ifndef STOCK_INPUT_H
#define STOCK_INPUT_H

double 輸入價格(const std::string& 動作);

int 輸入股數(const std::string& 動作);

#endif
逐行解說
第1行：#ifndef ... #define ... #endif 是防止重複包含標頭檔的標準寫法
第3行：宣告一個函式，傳入操作名稱，回傳價格（double）
第5行：宣告一個函式，傳入操作名稱，回傳股數（int）
StockInput.cpp
程式碼
#include <iostream>
#include "StockInput.h"

using namespace std;

double 輸入價格(const string& 動作) {
    double 價格;
    cout << 動作 << "價格：";
    cin >> 價格;
    return 價格;
}

int 輸入股數(const string& 動作) {
    int 股數;
    cout << 動作 << "股數（或張數）：";
    cin >> 股數;
    return 股數;
}
逐行解說
第1行：引入輸入函式的標頭與 iostream
第3行：使用標準命名空間，方便用 cout, cin
第5行：輸入價格函式：提示用戶輸入操作價格，讀取並回傳
第9行：輸入股數函式：提示用戶輸入操作股數，讀取並回傳
StockCalc.h
程式碼
#ifndef STOCK_CALC_H
#define STOCK_CALC_H

double 計算買入總成本(double 價格, int 股數);

double 計算賣出總收入(double 價格, int 股數);

double 計算盈虧(double 買入成本, double 賣出收入);

#endif
逐行解說
第1行：防止重複包含標頭檔的標準寫法
第3行：宣告計算買入成本函式，含手續費
第5行：宣告計算賣出收入函式，扣手續費及交易稅
第7行：宣告計算盈虧函式
StockCalc.cpp
程式碼
#include "StockCalc.h"
#include <cmath>

const double 手續費率 = 0.001425;
const double 交易稅率 = 0.003;

int 四捨五入(double 金額) {
    return static_cast<int>(round(金額));
}

double 計算買入總成本(double 價格, int 股數) {
    double 成交金額 = 價格 * 股數;
    int 手續費 = 四捨五入(成交金額 * 手續費率);
    return 成交金額 + 手續費;
}

double 計算賣出總收入(double 價格, int 股數) {
    double 成交金額 = 價格 * 股數;
    int 手續費 = 四捨五入(成交金額 * 手續費率);
    int 交易稅 = 四捨五入(成交金額 * 交易稅率);
    return 成交金額 - 手續費 - 交易稅;
}

double 計算盈虧(double 買入成本, double 賣出收入) {
    return 賣出收入 - 買入成本;
}
逐行解說
第1行：引入標頭與 cmath 用來呼叫 round 函式
第3行：定義台股手續費率 (0.1425%)
第4行：定義台股交易稅率 (賣出時收 0.3%)
第6行：四捨五入到整數元，將 double 轉成 int
第10行：計算買入總成本 = 成交價 * 股數 + 手續費（四捨五入）
第15行：計算賣出總收入 = 成交價 * 股數 - 手續費 - 交易稅（皆四捨五入）
第22行：盈虧 = 賣出收入 - 買入成本

