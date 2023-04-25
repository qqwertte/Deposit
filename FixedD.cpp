#include "FixedD.h"

CFixeddeposit::CFixeddeposit() {
	MoneyAmount = 0;
	MonthTerm = 0;
	PercentageRate = 0;
}

CFixeddeposit::CFixeddeposit(double Money, double Percentage, int Month) {
	MoneyAmount = Money;
	MonthTerm = Month;
	PercentageRate = Percentage;
}

double CFixeddeposit::GetProfit() const {
	double temp = (MoneyAmount * (PercentageRate / 12)) / 100;
	return MoneyAmount + (temp * MonthTerm);
}

double CFixeddeposit::GetProfitForPeriod(int month) const {
	//double temp = MoneyAmount * pow((1 + ((PercentageRate / 100) / 12)), month) - MoneyAmount;
	double temp = (MoneyAmount * (PercentageRate / 12)) / 100;
	return MoneyAmount + (temp * month);
}

ostream& CFixeddeposit::print(ostream& OutFile) const {
	OutFile << endl;
	OutFile << "Fixed Deposit:" << endl;
	OutFile << "Balance: " << this->GetProfit() << endl;
	OutFile << "Interest rate: " << PercentageRate << endl;
	OutFile << "Term: " << MonthTerm << " months" << endl;
	return OutFile;
}
//
//ostream& operator<<(ostream& OutFile, const CDeposit& obj) {
//	return obj.print(OutFile);
//}

void CFixeddeposit::WriteToFile(ofstream& outFile, const CDeposit& obj) const {
	outFile << obj;
}
void CFixeddeposit::SetMoney(double money) {
	MoneyAmount = money;
}
void CFixeddeposit::SetMonth(int Month) {
	MonthTerm = Month;
}

void CFixeddeposit::PrintStats(CFixeddeposit& obj) const {
	obj.SetMoney(obj.GetProfit());
	obj.SetMonth(obj.GetMonthTerm());
	cout << "Fixed Deposit:" << endl;
	cout << "Balance: " << obj.MoneyAmount << endl;
	cout << "Interest rate: " << obj.PercentageRate << endl;
	cout << "Term: " << obj.MonthTerm << " months" << endl;

}