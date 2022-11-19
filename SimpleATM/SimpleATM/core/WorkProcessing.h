#pragma once
#include <string>
#include "BankConnector.h"
#include "CashBin.h"

using namespace std;

class CWorkProcessing
{
public:
	CWorkProcessing();
	~CWorkProcessing();

	void NewSession();
	bool SetPinNumber(int nInputNumber);
	void SetAccount(string strInputAccount);
	vector<string> GetAccounts();
	const MAP_History_Daily GetBankTransactionHistory(string strAccount);
	int GetBalanceOfAccount();
	bool WithdrawBill(int nCash);
	bool DepositBill(int nCash);

private:
	void ClearData();

	int m_nPinNumber;
	string m_strAccount;
	int m_nBalanceOfAccount;
	CBankConnector m_BankConnentor;
	CCashBin m_CashBin;
};

