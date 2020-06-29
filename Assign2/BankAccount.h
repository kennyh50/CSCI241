   #ifndef BANK_ACCOUNT_H
   #define BANK_ACCOUNT_H

   //*****************************************************************
   // FILE:      BankAccount.h
   // AUTHOR:    Kenneth Harris
   // LOGON ID:  z1733721
   // DUE DATE:  9/27/2018
   // 
   // PURPOSE:   Contains the declaration for the BankAccount class.
   //*****************************************************************

   class BankAccount
      {
      // Data members 
	private:

		char account[11]{"\0"};
		char name[21]{"\0"};
		double balance = 0;
	//Function prototypes
	public:
		BankAccount();
		BankAccount(const char* newAccountNumber, const char* newName, double newBalance);
		const char* getAccountNumber() const;
		const char* getName() const;
		double getBalance() const;
		void processDeposit(double amount);
		bool processWithdrawal(double amount);
		void print() const;
      };

   #endif
