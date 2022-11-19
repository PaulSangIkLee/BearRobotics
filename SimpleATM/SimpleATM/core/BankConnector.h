#pragma once
#include "../dummies/DummyBankSystem.h"

class CBankConnector
{
public:
	CBankConnector();
	~CBankConnector();

	bool ValidPinNumber(int nInputPIN);
	vector<string> GetAccounts(int nInputPIN);
	const MAP_History_Daily GetBankTransactionHistory(string strAccount);
	void UpdateBackReansaction(string strInDate, string strInAccount, int nInBankingType, int nUpdateCash);

private:
	CDummyBankSystem m_BankSystem;
};

