#pragma once
#include "Header.h"
class CVIPDeposit : public CDeposit {
public:
    CVIPDeposit();
    CVIPDeposit(double Money, double Percentage, int Month);
    virtual ~CVIPDeposit() {}
    double AdditionalPercentages() const;
    double IncreaseBalance(double money) const;
    virtual double GetProfit() const override;
    virtual double GetProfitForPeriod(int months) const override;
    void SetMoney(double money);
    void SetMonth(int Month);
    void PrintStats(CVIPDeposit& obj) const;
    ostream& print(ostream& out) const override;
    virtual void WriteToFile(ofstream& outFile, const CDeposit& obj) const override;
    //virtual void PrintInfo() const override;

};
