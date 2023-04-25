#pragma once
#include "Header.h"

class CFixeddeposit : public  CDeposit {
public:
    void SetMoney(double money);
    void SetMonth(int Month);
    void PrintStats(CFixeddeposit& obj) const;
    CFixeddeposit();
    CFixeddeposit(double Money, double Percentage, int Month); //: CDeposit(Money, Percentage, Month) {}
    virtual ~CFixeddeposit() {}
    virtual double GetProfit() const override;
    virtual double GetProfitForPeriod(int month) const override;
    ostream& print(ostream& out) const override;
    virtual void WriteToFile(ofstream& outFile, const CDeposit& obj) const override;
};
