#include "AccountDB.h"
#include "BankAccount.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

//Default Constructor
AccountDB::AccountDB()
{

}

//Opens the file
AccountDB::AccountDB(const char* fileName)
{
ifstream inFile;

inFile.open("fileName");
	if(! inFile)
{
	cout << "Error opening file.";
	exit(1);
}

inFile.read((char*) this, sizeof(AccountDB));

inFile.close();

sortAccounts();
}

void AccountDB::print() const
{

	cout << "Account Listing for First National Bank" << endl << endl;

	for(int i = 0; i < numofaccounts; i++)
{
	BankAccountObjects[i].print();
	cout << endl;
}
}

//Sorts  through the valid accounts that can have transactions
void AccountDB::sortAccounts()
{
int i, j;
BankAccount bankAccount;


   for (i = 1; i < numofaccounts; i++)
      {
      bankAccount = BankAccountObjects[i];

      for (j = i; (j > 0) && (strcmp(BankAccountObjects[j-1].getAccountNumber(), bankAccount.getAccountNumber()) > 0); j--)
         BankAccountObjects[j] = BankAccountObjects[j-1];

      BankAccountObjects[j] = bankAccount;
      }

}

//Searches through the accounts and finds the correct one
int AccountDB::searchForAccount(const char* searchNumber) const
{
int low = 0;
int high = numofaccounts - 1;
int mid;

while(low <= high)
{
	mid = (low + high) / 2;

		if(strcmp(searchNumber, BankAccountObjects[mid].getAccountNumber())==0)
			return mid;

		if(strcmp(searchNumber, BankAccountObjects[mid].getAccountNumber()) < 0)
			high = mid - 1;
		else
			low = mid + 1;
}
	return -1;
}

//Opens the file and process the transactions with the proper amount of money
void AccountDB::processTransactions(const char* fileName)
{
ifstream inFile;
char transactionDate[6];
char accountNumber[11];
char transactionType;
double transactionAmount;
bool withdrawalAccepted;

inFile.open("fileName");
	if(! inFile)
{
	cout << "Error opening file";
	exit(1);
}

	while(inFile)
{
		inFile >> transactionDate;
		inFile >> accountNumber;
		inFile >> transactionType;
		inFile >> transactionAmount;

		cout << "Date" << transactionDate ;
		cout << "Account" << accountNumber;
		cout << "Type" << transactionType;

		int index = searchForAccount(accountNumber);
		if (index == -1)
			cout << "account not found";

		else
			if (transactionType == 'D'){
				BankAccountObjects[index].processDeposit(transactionAmount);
				cout << BankAccountObjects[index].getBalance();
}
			else
{
				BankAccountObjects[index].processWithdrawal(transactionAmount);

				if(false)
					cout << "Insufficient funds";
				else
					cout << BankAccountObjects[index].getBalance();
}
}

		inFile >> transactionDate;

inFile.close();

}



