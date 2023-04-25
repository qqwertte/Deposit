#include "Header.h"

CDeposit::CDeposit() {
	MoneyAmount = 0;
	MonthTerm = 0;
	PercentageRate = 0;
}

CDeposit::CDeposit(double Money, double Percentage, int Month) {
	MoneyAmount = Money;
	MonthTerm = Month;
	PercentageRate = Percentage;
}

ostream& operator<<(ostream& OutFile, const CDeposit& obj) {
	return obj.print(OutFile);
}