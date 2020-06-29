#include<iostream>
#include<cstring>
#include<iomanip>
#include "BankAccount.h"

using namespace std;

//Default constructor
BankAccount::BankAccount()
{

}

//Alternate constructor
BankAccount::BankAccount(const char* newAccountNumber, const char* newName, double newBalance)
{

	strcpy (account, newAccountNumber);
	strcpy (name, newName);
	balance = newBalance;
}
//Gets the account number
const char* BankAccount::getAccountNumber() const
{
return account;
}

//Gets the name for the account
const char* BankAccount::getName() const
{
return name;
}

//Gets the account balance
double BankAccount::getBalance() const
{
return balance;
}

//Function takes the deposit and adds it to the balance
void BankAccount::processDeposit(double amount)
{

balance = balance + amount;

}

//Function processess the withdrawl request
bool BankAccount::processWithdrawal(double amount)
{
	if(balance < amount)
{
	return false;
}
	else
{
	balance = balance - amount;

	return balance;
}
}

//The function prints out the account number, name and balance
void BankAccount::print() const
{

cout<<"Account Number: " << account <<endl;
cout<<"Name: " << name <<endl;
cout<<"Balance: " << balance <<endl;

}
