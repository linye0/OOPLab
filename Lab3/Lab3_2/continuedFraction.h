#ifndef CONTINUEDFRACTION_H
#define CONTINUEDFRACTION_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

int gcd(int, int);

class ContinuedFraction{
public:
    ContinuedFraction(double x, int maxLen = 30) {
        for (int i = 0; i < maxLen; i++){
            int floorNum = floor(x);
            a.push_back(floorNum);
            x = 1 / (x - floorNum);
            if (x == 0) break;
        }
    }
    int get_ai(int i) const{
        if (i >= a.size()) return 0;
        return a[i];
    }
    void get_first_i(int i) const{
        cout << "前" << i << "项为: ";
        for (int cnt = 0; cnt < i; cnt++) {
            if (cnt != 0) {
                cout << "+";
            }
            cout << a[cnt];
        }
        cout << endl;
    }
    void frac_i(int i) const{
        int p = 0, q = 1;
        for (int cnt = i - 1; cnt >= 0; cnt--) {
            int curp = a[cnt];
            int curq = 1;
            p = p * curq + curp * q;
            q = q * curq;
            int mgcd = gcd(p, q);
            p = p / mgcd;
            q = q / mgcd;
            if (cnt != 0) {
                int tmp = p;
                p = q;
                q = tmp;
            }
        }
        cout << "前" << i << "项对应分数为" << p << "/" << q << endl;
    }
    void approx_i(int i) const {
        double v = 0;
        for (int cnt = i - 1; cnt >= 0; cnt--) {
            v += a[cnt];
            if (cnt != 0) {
                v = 1 / v;
            }
        }
        cout << "前" << i << "项对应分数的值为" << fixed << setprecision(15) << v << endl;
    }
    double get_approx_i(int i) const {
        double v = 0;
        for (int cnt = i - 1; cnt >= 0; cnt--) {
            v += a[cnt];
            if (cnt != 0) {
                v = 1 / v;
            }
        }
        return v;
    }
    void bias_i(int i) const {
        cout << "前" << i <<"项对应分数与" << fixed << setprecision(15) << M_PI << "的差为" << fixed << setprecision(15) << M_PI - get_approx_i(i) << endl;
    }
    void display(int i) const{
        get_first_i(i);
        frac_i(i);
        approx_i(i);
        bias_i(i);
    }
private:
    vector<int> a;
};

#endif // CONTINUEDFRACTION_H
