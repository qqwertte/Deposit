#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

class CDeposit {
protected:
    double MoneyAmount;
    double PercentageRate;
    int MonthTerm;
public:
    CDeposit();
    CDeposit(double Money, double Percentage, int Month);
    virtual ~CDeposit() {}
    virtual double GetProfit() const = 0;
    virtual double GetProfitForPeriod(int month) const = 0;
    virtual ostream& print(ostream& out) const = 0;
    friend ostream& operator<<(ostream& out, const CDeposit& obj);
    virtual void WriteToFile(ofstream& outFile, const CDeposit& obj) const = 0;
    double GetBalance() const { return MoneyAmount; }
    double GetPercentageRate() const { return PercentageRate; }
    int GetMonthTerm() const { return MonthTerm; }
};