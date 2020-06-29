#ifndef ACCOUNT_DB_H
#define ACCOUNT_DB_H
#include "BankAccount.h"

//*****************************************************************
   // FILE:      AccountDB.h
   // AUTHOR:    Kenneth Harris
   // LOGON ID:  z1733721
   // DUE DATE:  10/2/2018
   // 
   // PURPOSE:   Contains the declaration for the account database class.
   //*****************************************************************

class AccountDB
{
	private:

		char bankName[31]= {"First National Bank"};
		BankAccount BankAccountObjects[300];
		int numofaccounts = 0;

	public:
		AccountDB();
		AccountDB(const char* fileName);
		void print() const; 
		void sortAccounts();
		int searchForAccount(const char* searchNumber) const;
		void processTransactions(const char* fileName);
		
};

#endif
