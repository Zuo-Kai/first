#include "StockInput.h"
#include "StockUtils.h"
#include <iostream>

using namespace std;

int ipstock(const string& �ʧ@) {
    int num;
    char uni;    

    cout << "�п�J" << �ʧ@ << "�ƶq�]z=�i / s=�ѡ^�G";
    cin >> uni;
    cout << "�п�J�ƶq�G";
    cin >> num;

    if (uni == 'z' || uni == 'Z') return num * �@�i�Ѽ�;
    else return num;
}

double ipprice(const string& ����) {
    double price;
    cout << "�п�J�C��" << ���� << "���G";
    cin >> price;
    return price;
}
