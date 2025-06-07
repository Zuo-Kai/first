#include "StockCalc.h"
#include <cmath> // ���F�ϥ� round()

// �x�Ѥ���O�v
const double feesg = 0.001425;
// �x�ѥ���|�v�]�u�b��X���^
const double taxg = 0.003;

// �|�ˤ��J��Ƥ�
int ff(int ���B) {
    return static_cast<int>(round(���B));
}

// �R�J�`�����G���� * �Ѽ� + ����O�]�|�ˤ��J�^
double cbtm(double price, int stock) {
    double sm = price * stock;
    int fees = ff(sm * feesg);
    return sm + fees;
}

// ��X�`���J�G���� * �Ѽ� - ����O - ����|�]���|�ˤ��J�^
double cstm(double price, int stock) {
    double sm = price * stock;
    int fees = ff(sm * feesg);
    int tax = ff(sm * taxg);
    return sm - fees - tax;
}

double ctt(double �R�J����, double ��X���J) {
    return ��X���J - �R�J����;
}
