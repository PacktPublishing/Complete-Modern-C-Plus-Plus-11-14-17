#pragma once
int Add(int a, int b);
extern "C" {
double Add(double a, double b);
void Print(int *x);
}
//void Print(const int* x) ;