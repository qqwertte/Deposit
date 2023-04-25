#include "VIPd.h"


CVIPDeposit::CVIPDeposit() {
	MoneyAmount = 0;
	MonthTerm = 0;
	PercentageRate = 0;
}
CVIPDeposit::CVIPDeposit(double Money, double Percentage, int Month) {
	MoneyAmount = Money;
	MonthTerm = Month;
	PercentageRate = Percentage;
}

double CVIPDeposit::AdditionalPercentages() const {
	double addperc = 0;
	if (this->GetBalance() > 10000) {
		addperc = 0.5;
	}
	else if (this->GetBalance() >= 1000) {
		addperc = 0.25;
	}
	else if (this->GetBalance() > 100) {
		addperc = 0.1;
	}
	return addperc;
}

double CVIPDeposit::GetProfit() const {
	double tempbalance = MoneyAmount, res = 0;
	//double temp = (tempbalance * (PercentageRate / 12)) / 100;// one month
	double monthlyprofit = 0;
	for (int i = 1; i <= MonthTerm; i++) {
		monthlyprofit = ((tempbalance * (PercentageRate + AdditionalPercentages() / 12)) / 100);
		tempbalance += monthlyprofit;
	}
	res = tempbalance;
	return res;
}

double CVIPDeposit::GetProfitForPeriod(int month) const {
	double tempbalance = MoneyAmount, res = 0;
	//double temp = (tempbalance * (PercentageRate / 12)) / 100;// one month
	double monthlyprofit = 0;
	for (int i = 1; i <= month; i++) {
		monthlyprofit = ((tempbalance * (PercentageRate + AdditionalPercentages() / 12)) / 100);
		tempbalance += monthlyprofit;
	}
	res = tempbalance;
	return res;
}

void CVIPDeposit::SetMoney(double money) {
	MoneyAmount = money;
}
void CVIPDeposit::SetMonth(int month) {
	MonthTerm = month;
}

void CVIPDeposit::PrintStats(CVIPDeposit& obj) const {
	cout << "VIP Deposit:" << endl;
	cout << "Balance: " << obj.MoneyAmount << endl;
	cout << "Interest rate: " << obj.PercentageRate << endl;
	cout << "Term: " << obj.MonthTerm << " months" << endl;
}

ostream& CVIPDeposit::print(ostream& OutFile) const {
	OutFile << endl;
	OutFile << "VIP Deposit:" << endl;
	OutFile << "Balance: " << MoneyAmount << endl;
	OutFile << "Interest rate: " << PercentageRate << endl;
	OutFile << "Term: " << MonthTerm << " months" << endl;
	return OutFile;
}

void CVIPDeposit::WriteToFile(ofstream& outFile, const CDeposit& obj) const {
	outFile << obj;
}

double CVIPDeposit::IncreaseBalance(double money) const {
	double tmp = GetBalance();
	tmp += money;
	return tmp;
}