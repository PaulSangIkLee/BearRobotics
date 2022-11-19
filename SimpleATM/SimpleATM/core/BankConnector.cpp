#include "BankConnector.h"



CBankConnector::CBankConnector()
{
}


CBankConnector::~CBankConnector()
{
}

bool CBankConnector::ValidPinNumber(int nInputPIN)
{
	return m_BankSystem.ValidPinNumber(nInputPIN);
}

std::vector<std::string> CBankConnector::GetAccounts(int nInputPIN)
{
	return m_BankSystem.GetAccounts(nInputPIN);
}

const MAP_History_Daily CBankConnector::GetBankTransactionHistory(string strAccount)
{
	return m_BankSystem.GetBankTransactionHistory(strAccount);
}

void CBankConnector::UpdateBackReansaction(string strInDate, string strInAccount, int nInBankingType, int nUpdateCash)
{
	m_BankSystem.UpdateBackReansaction(strInDate, strInAccount, nInBankingType, nUpdateCash);
}
