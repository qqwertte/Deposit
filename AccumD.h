#pragma once
#include "Header.h"

class CAccumulativeDeposit : public CDeposit {
public:
    CAccumulativeDeposit();
    CAccumulativeDeposit(double Money, double Percentage, int Month);
    virtual ~CAccumulativeDeposit() {}
    virtual double GetProfit() const override;
    virtual double GetProfitForPeriod(int months) const override;
    void SetMoney(double money);
    void SetMonth(int Month);
    void PrintStats(CAccumulativeDeposit& obj) const;
    ostream& print(ostream& out) const override;
    virtual void WriteToFile(ofstream& outFile, const CDeposit& obj) const override;
};