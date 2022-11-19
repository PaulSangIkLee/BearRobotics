#include "WorkProcessing.h"
#include <ctime> 

CWorkProcessing::CWorkProcessing()
{
}


CWorkProcessing::~CWorkProcessing()
{
}

void CWorkProcessing::NewSession()
{
	ClearData();
}

bool CWorkProcessing::SetPinNumber(int nInputNumber)
{
	bool bRetVal = false;
	if (m_BankConnentor.ValidPinNumber(nInputNumber))
	{
		m_nPinNumber = nInputNumber;
		bRetVal = true;
	}
	return bRetVal;
}

void CWorkProcessing::SetAccount(string strInputAccount)
{
	m_strAccount = strInputAccount;
}

std::vector<std::string> CWorkProcessing::GetAccounts()
{
	return m_BankConnentor.GetAccounts(m_nPinNumber);
}

const MAP_History_Daily CWorkProcessing::GetBankTransactionHistory(string strAccount)
{
	//return m_BankConnentor.GetBankTransactionHistory(strAccount);

	MAP_History_Daily::iterator itr;
	MAP_History_Daily mapBankingHistory;
	mapBankingHistory = m_BankConnentor.GetBankTransactionHistory(m_strAccount);

	int nTmpBalance = 0;
	VEC_History vecTmpDay;
	for (itr = mapBankingHistory.begin(); itr != mapBankingHistory.end(); itr++)
	{
		vecTmpDay = itr->second;
		int DaySize = vecTmpDay.size();

		for (int i = 0; i < DaySize; i++)
		{
			nTmpBalance += vecTmpDay[i].second;
		}
	}
	m_nBalanceOfAccount = nTmpBalance;
	
	return mapBankingHistory;
}

int CWorkProcessing::GetBalanceOfAccount()
{
	return m_nBalanceOfAccount;
}

bool CWorkProcessing::WithdrawBill(int nCash)
{
	bool bRetval = false;
	if (m_CashBin.WithdrawBill(nCash) == true)
	{
		bRetval = true;

		time_t t_Time = time(NULL);
		struct tm* tmDate = localtime(&t_Time);

		char arDate[11];
		sprintf(arDate, "%04d-%02d-%02d",tmDate->tm_year+1900, tmDate->tm_mon+1, tmDate->tm_mday);
		string strDate = arDate;

		m_BankConnentor.UpdateBackReansaction(strDate, m_strAccount, TYPE_OUT, nCash*-1);
	}

	return bRetval;
}

bool CWorkProcessing::DepositBill(int nCash)
{
	bool bRetval = false;
	if (m_CashBin.DepositBill(nCash) == true)
	{
		bRetval = true;

		time_t t_Time = time(NULL);
		struct tm* tmDate = localtime(&t_Time);

		char arDate[11];
		sprintf(arDate, "%04d-%02d-%02d", tmDate->tm_year + 1900, tmDate->tm_mon + 1, tmDate->tm_mday);
		string strDate = arDate;

		m_BankConnentor.UpdateBackReansaction(strDate, m_strAccount, TYPE_IN, nCash);
	}

	return bRetval;
}

void CWorkProcessing::ClearData()
{
	m_nPinNumber = 0;
	m_nBalanceOfAccount = 0;
	m_strAccount.clear();
}
