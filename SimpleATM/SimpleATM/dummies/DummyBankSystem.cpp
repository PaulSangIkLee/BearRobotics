#include "DummyBankSystem.h"

CDummyBankSystem::CDummyBankSystem()
{
	//make pin list;
	vector<string> vecAccount;
	vecAccount = { "1002123123", "1002345345", "1002567567" };
	m_mapPIN.insert(make_pair(123456, vecAccount));
	vecAccount.clear();
	vecAccount = { "1002789789", "1002321321"};
	m_mapPIN.insert(make_pair(234567, vecAccount));
	vecAccount.clear();

	//make dummy transaction data.
	MAP_History_Daily mapAccount1, mapAccount2, mapAccount3, mapAccount4, mapAccount5;	
	VEC_History vecTmpDaily;	
	//dummy date insert to dummy account 1
	vecTmpDaily = {make_pair(TYPE_IN, 250000)};
	mapAccount1.insert(make_pair("2022-11-01", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 5000)};
	mapAccount1.insert(make_pair("2022-11-02", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_OUT, -54000), make_pair(TYPE_IN, 32000) };
	mapAccount1.insert(make_pair("2022-11-03", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 638) };
	mapAccount1.insert(make_pair("2022-11-10", vecTmpDaily));
	vecTmpDaily.clear();
	m_mapDefaultData.insert(make_pair("1002123123", mapAccount1));


	//dummy date insert to dummy account 2
	vecTmpDaily = {make_pair(TYPE_IN, 22000) };
	mapAccount2.insert(make_pair("2022-11-10", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 30), make_pair(TYPE_IN, 16000) };
	mapAccount2.insert(make_pair("2022-11-13", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 3100) };
	mapAccount2.insert(make_pair("2022-11-14", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 27000), make_pair(TYPE_IN, 8) };
	mapAccount2.insert(make_pair("2022-11-19", vecTmpDaily));
	vecTmpDaily.clear();
	m_mapDefaultData.insert(make_pair("1002345345", mapAccount2));

	//dummy date insert to dummy account 3
	vecTmpDaily = {make_pair(TYPE_IN, 30000)};
	mapAccount3.insert(make_pair("2022-11-01", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 6000), make_pair(TYPE_IN, 10000), make_pair(TYPE_IN, 5000) };
	mapAccount3.insert(make_pair("2022-11-16", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 12000), make_pair(TYPE_IN, 33000), make_pair(TYPE_OUT, -25362) };
	mapAccount3.insert(make_pair("2022-11-17", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_OUT, -10000), make_pair(TYPE_IN, 3000) };
	mapAccount3.insert(make_pair("2022-11-19", vecTmpDaily));
	vecTmpDaily.clear();
	m_mapDefaultData.insert(make_pair("1002567567", mapAccount3));

	//dummy date insert to dummy account 4
	vecTmpDaily = {make_pair(TYPE_OUT, 200000) };
	mapAccount4.insert(make_pair("2022-11-07", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_OUT, -7900) };
	mapAccount4.insert(make_pair("2022-11-09", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_OUT, -15252) };
	mapAccount4.insert(make_pair("2022-11-10", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_OUT, -3410), make_pair(TYPE_OUT, -50000), make_pair(TYPE_IN, 10000) };
	mapAccount4.insert(make_pair("2022-11-11", vecTmpDaily));
	vecTmpDaily.clear();
	m_mapDefaultData.insert(make_pair("1002789789", mapAccount4));

	//dummy date insert to dummy account 5
	vecTmpDaily = {make_pair(TYPE_IN, 78000), make_pair(TYPE_IN, 55000) };
	mapAccount5.insert(make_pair("2022-11-04", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_IN, 400000), make_pair(TYPE_IN, 65000) };
	mapAccount5.insert(make_pair("2022-11-08", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = {make_pair(TYPE_OUT, -50000) };
	mapAccount5.insert(make_pair("2022-11-10", vecTmpDaily));
	vecTmpDaily.clear();
	vecTmpDaily = { make_pair(TYPE_IN, 6822), make_pair(TYPE_OUT, -53184) };
	mapAccount5.insert(make_pair("2022-11-17", vecTmpDaily));
	vecTmpDaily.clear();
	m_mapDefaultData.insert(make_pair("1002321321", mapAccount5));

	m_mapDefaultData;
}


CDummyBankSystem::~CDummyBankSystem()
{
}

bool CDummyBankSystem::ValidPinNumber(int nInputPIN)
{
	bool bRetval = false;
	MAP_PIN::iterator itr;
	itr = m_mapPIN.find(nInputPIN);
	if (itr != m_mapPIN.end())
	{
		bRetval = true;
	}
	return bRetval;
}

std::vector<std::string> CDummyBankSystem::GetAccounts(int nInputPIN)
{
	vector<string> vecRetAccounts;
	MAP_PIN::iterator itr;
	itr = m_mapPIN.find(nInputPIN);
	if (itr != m_mapPIN.end())
	{
		vecRetAccounts = itr->second;
	}
	return vecRetAccounts;
}

const MAP_History_Daily CDummyBankSystem::GetBankTransactionHistory(string strAccount)
{
	MAP_History_Daily vecRetHistoryDaily;
	MAP_Dummy_Data::iterator itr;

	itr = m_mapDefaultData.find(strAccount);

	if (itr != m_mapDefaultData.end())
	{
		vecRetHistoryDaily = itr->second;
	}
	return vecRetHistoryDaily;
}

void CDummyBankSystem::UpdateBackReansaction(string strInDate, string strInAccount, int nInBankingType, int nUpdateCash)
{
	MAP_Dummy_Data::iterator itrDefaultData;
	itrDefaultData = m_mapDefaultData.find(strInAccount);

	MAP_History_Daily* pmapDaily;
	MAP_History_Daily::iterator itrDaily;
	pmapDaily = &(itrDefaultData->second);


	VEC_History vecTmpDaily;
	itrDaily = pmapDaily->find(strInDate);

	if (itrDaily != pmapDaily->end())
	{
		vecTmpDaily = itrDaily->second;
	}

	vecTmpDaily.push_back(make_pair(nInBankingType, nUpdateCash));

	if (itrDaily != pmapDaily->end())
	{
		itrDaily->second = vecTmpDaily;
	}
	else
	{
		pmapDaily->insert(make_pair(strInDate, vecTmpDaily));
	}
}
