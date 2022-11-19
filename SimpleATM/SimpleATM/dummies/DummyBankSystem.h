#pragma once
/********************************/
//
// This class was created to mimic a real banking system.
// May differ from actual banking system.
//
/********************************/

#include <vector>
#include <string>
#include <map>

using namespace std;

const int TOTALMONEY = 133638;
enum BANKING_TYPE
{
	TYPE_IN,
	TYPE_OUT,
};


typedef map<int, vector<string>> MAP_PIN;
typedef vector<pair<int,int>> VEC_History;
typedef map<string, VEC_History > MAP_History_Daily;
typedef map<string, MAP_History_Daily> MAP_Dummy_Data;


class CDummyBankSystem
{
public:
	CDummyBankSystem();
	~CDummyBankSystem();

	bool ValidPinNumber(int nInputPIN);
	vector<string> GetAccounts(int nInputPIN);
	const MAP_History_Daily GetBankTransactionHistory(string strAccount);
	void UpdateBackReansaction(string strInDate, string strInAccount, int nInBankingType, int nUpdateCash);
	
private:
	int m_nBalance;
	MAP_PIN m_mapPIN;
	VEC_History m_vecTransactionHistory;
	MAP_Dummy_Data m_mapDefaultData;

};

