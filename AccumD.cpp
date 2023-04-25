#include "AccumD.h"

CAccumulativeDeposit::CAccumulativeDeposit(double Money, double Percentage, int Month) {
	MoneyAmount = Money;
	MonthTerm = Month;
	PercentageRate = Percentage;
}

CAccumulativeDeposit::CAccumulativeDeposit() {
	MoneyAmount = 0;
	MonthTerm = 0;
	PercentageRate = 0;
}
double CAccumulativeDeposit::GetProfit() const {
	double tempbalance = MoneyAmount, res = 0;
	double monthlyprofit = 0;
	for (int i = 1; i <= MonthTerm; i++) {
		monthlyprofit = ((tempbalance * (PercentageRate / 12)) / 100);
		tempbalance += monthlyprofit;
	}
	res = tempbalance;
	return res;
}

double CAccumulativeDeposit::GetProfitForPeriod(int months) const {
	double profit = 0;
	double tempbalance = MoneyAmount, res = 0;
	double monthlyprofit = 0;
	for (int i = 1; i <= months; i++) {
		monthlyprofit = ((tempbalance * (PercentageRate / 12)) / 100);
		tempbalance += monthlyprofit;
	}
	res = tempbalance;
	return res;
}

void CAccumulativeDeposit::WriteToFile(ofstream& outFile, const CDeposit& obj) const {
	outFile << obj;
}
void CAccumulativeDeposit::SetMoney(double money) {
	MoneyAmount = money;
}
void CAccumulativeDeposit::SetMonth(int month) {
	MonthTerm = month;
}

void CAccumulativeDeposit::PrintStats(CAccumulativeDeposit& obj) const {
	obj.SetMoney(obj.GetProfit());
	obj.SetMonth(obj.GetMonthTerm());
	cout << "Accumulative Deposit:" << endl;
	cout << "Balance: " << obj.MoneyAmount << endl;
	cout << "Interest rate: " << obj.PercentageRate << endl;
	cout << "Term: " << obj.MonthTerm << " months" << endl;
}

ostream& CAccumulativeDeposit::print(ostream& OutFile) const {
	OutFile << endl;
	OutFile << "Accumulative Deposit:" << endl;
	OutFile << "Balance: " << this->GetProfit() << endl;
	OutFile << "Interest rate: " << PercentageRate << endl;
	OutFile << "Term: " << MonthTerm << " months" << endl;
	return OutFile;
}