#include "StockInput.h"
#include "StockUtils.h"
#include <iostream>

using namespace std;

int ipstock(const string& 動作) {
    int num;
    char uni;    

    cout << "請輸入" << 動作 << "數量（z=張 / s=股）：";
    cin >> uni;
    cout << "請輸入數量：";
    cin >> num;

    if (uni == 'z' || uni == 'Z') return num * 一張股數;
    else return num;
}

double ipprice(const string& 類型) {
    double price;
    cout << "請輸入每股" << 類型 << "價：";
    cin >> price;
    return price;
}
