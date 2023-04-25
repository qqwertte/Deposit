#include "Header.h"
#include "AccumD.h"
#include"FixedD.h"
#include "VIPd.h"

int main(void) {
	cout << endl << endl;
	double Money=0, Percentage=0,Moneytmp = 0;
	int Month = 0, choice = 0, tmp = 0;
	ofstream OutFile("Output.txt");
	cout <<setw(60)<<"Hi there!\n" << endl;
	cout << "Enter type of deposit you want:" << endl << endl<<endl;
	cout << "1 - Fixed(Interest is paid after the deposit expires)" << endl << endl;
	cout << "2 - Accumulative(capitalization of interest, payment occurs every month)" << endl << endl;
	cout << "3 - VIP(capitalization,payment every month, possibility of replenishment on any day,increaseability of rate with given ratio)" << endl << endl;

	cout << "Enter your choice (number) here: "; cin >> choice;
	string currency;
	while (1) {
		if (choice == 1) {
			cout << "What currency would you like to deposit? (usd,uan,eur): "; cin >> currency;
			if (currency != "usd" && currency != "uan" && currency != "eur") {
				cout << "Please, enter correct currency: "; cin >> currency;
			}
			cout << endl;
			if (currency == "usd") {
				cout << "We can offer you 5% per year" << endl;
				Percentage = 5;
			}
			else if (currency == "uan") {
				cout << "We can offer you 15% per year" << endl;
				Percentage = 15;
			}
			else if (currency == "eur") {
				cout << "We can offer you 3% per year" << endl;
				Percentage = 3;
			}
			cout << "OK, you have chosen a Fixed deposit, now enter the amount of money you want to put on it: "; cin >> Money; Moneytmp = Money;
			if (Money < 0) {
				cout << "We can not put negative amount of money, try again: "; cin >> Money; cout << endl;
			}
			cout << "\nEnter monthes for deposit(3,6,9,12 ...): "; cin >> Month; cout << endl;

			CFixeddeposit fixed(Money, Percentage, Month);
			fixed.WriteToFile(OutFile, fixed);
			fixed.PrintStats(fixed);

			cout << "\nIf you want to figure out profit for a period of time enter a number of monthes: "; cin >> tmp;
			CFixeddeposit fixed2(Moneytmp, Percentage, tmp);
			fixed.SetMoney(fixed2.GetProfitForPeriod(tmp));
			fixed2.WriteToFile(OutFile, fixed2);
			fixed2.PrintStats(fixed2);
			break;
		}
		if (choice == 2) {
			cout << "What currency would you like to deposit? (usd,uan,eur): "; cin >> currency;
			cout << endl;
			if (currency != "usd" && currency != "uan" && currency != "eur") {
				cout << "Please, enter correct currency: "; cin >> currency;
			}
			if (currency == "usd") {
				cout << "We can offer you 5% per year" << endl;
				Percentage = 5;
			}

			else if (currency == "uan") {
				cout << "We can offer you 15% per year" << endl;
				Percentage = 15;
			}
			else if (currency == "eur") {
				cout << "We can offer you 3% per year" << endl;
				Percentage = 3;
			}
			cout << "OK, you have chosen a Accumulative deposit, now enter the amount of money you want to put on it: "; cin >> Money; Moneytmp = Money;
			if (Money < 0) {
				cout << "We can not put negative amount of money, try again: "; cin >> Money; cout << endl;
			}
			cout << "\nEnter monthes for deposit(3,6,9,12 ...): "; cin >> Month; cout << endl;

			CAccumulativeDeposit accum(Money, Percentage, Month);
			accum.WriteToFile(OutFile, accum);
			accum.PrintStats(accum);

			cout << "\nIf you want to figure out profit for a period of time enter a number of monthes: "; cin >> tmp;
			CAccumulativeDeposit  accum2(Moneytmp, Percentage, tmp);
			accum.SetMoney(accum2.GetProfitForPeriod(tmp));
			accum2.WriteToFile(OutFile, accum2);
			accum2.PrintStats(accum2);
			break;
		}
		if (choice == 3) {
			cout << "What currency would you like to deposit? (usd,uan,eur): "; cin >> currency;
			if (currency != "usd" && currency != "uan" && currency != "eur") {
				cout << "Please, enter correct currency: "; cin >> currency;
			}
			cout << endl;
			if (currency == "usd") {
				cout << "We can offer you 5% per year" << endl;
				Percentage = 5;
			}
			else if (currency == "uan") {
				cout << "We can offer you 15% per year" << endl;
				Percentage = 15;
			}
			else if (currency == "eur") {
				cout << "We can offer you 3% per year" << endl;
				Percentage = 3;
			}
			cout << "OK, you have chosen a VIP deposit, now enter the amount of money you want to put on it: "; cin >> Money; Moneytmp = Money;
			if (Money < 0) {
				cout << "We can not put negative amount of money, try again: "; cin >> Money; cout << endl;
			}
			//cout << "\nEnter monthes for deposit(3,6,9,12 ...): "; cin >> Month; cout << endl;
			cout << "\nEnter monthes for deposit before adding new sum: "; cin >> Month; cout << endl;
			int addm = 0;

			CVIPDeposit vip(Money, Percentage, Month);
			vip.SetMoney(vip.GetProfitForPeriod(Month));
			double add = 0;
			cout << "\nYour balance\n";
			vip.PrintStats(vip);
			vip.WriteToFile(OutFile, vip);
			cout << "Now enter  the sum you want to add: "; cin >> add; cout << endl;
			cout << "And amount of monthes you want to put on it: "; cin >> addm; cout << endl;
			vip.SetMoney(vip.IncreaseBalance(add));
			vip.SetMoney(vip.GetProfitForPeriod(addm));
			vip.SetMonth(addm);
			cout << "\nYour balance\n";
			vip.PrintStats(vip);
			vip.WriteToFile(OutFile, vip);
			break;
		}
		else if (choice != 1 && choice != 2 && choice != 3) {
			cout << "You have not chosen any type of deposits =(" << endl;
			cin >> choice;
		}
		OutFile.close();
	}
	return 0;
}