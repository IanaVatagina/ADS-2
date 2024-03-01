// Copyright 2022 NNTU-CS
#include "alg.h"


double pown(double value, uint16_t n) {
    long double result = 1;
    for (uint64_t i=1; i <= n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    unsigned long long result = 1;
    for (uint64_t i=1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0;
    for (uint16_t i = 0; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    long double result = 0;
    bool flag = true;
    for (uint16_t i = 1; i <= count; i++) {
        if(flag) {
            result += calcItem(x, 2*i-1)*pown(-1, i-1);
            flag = false;
        }
        else {
            result += calcItem(x, 2*i-1)*pown(-1, i-1);
            flag = true;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0;
    bool flag = true;
    for (uint16_t i = 1; i <= count; i++) {
        if(flag) {
            /*result += pown(x, 2*i-2)/fact(2*i-2)*pown(-1, i-1);*/
            result += calcItem(x, 2*i-2)*pown(-1, i-1);
            flag = false;
        }
        else {
            /*result += pown(x, 2*i-2)/fact(2*i-2)*pown(-1, i-1);*/
            result += calcItem(x, 2*i-2)*pown(-1, i-1);
            flag = true;
        }
    }
    return result;
}
