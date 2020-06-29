//*****************************************************************
   // FILE:      assign2.cpp
   // AUTHOR:    Kenneth Harris 
   // PURPOSE:   This contains the main function for my assignment.
   //*****************************************************************

#include "AccountDB.h"
#include "BankAccount.h"

int main(int argc, char* argv[] )
{
AccountDB acc = AccountDB("accounts");

acc.print();

acc.processTransactions("transactions.txt");

acc.print();
}
