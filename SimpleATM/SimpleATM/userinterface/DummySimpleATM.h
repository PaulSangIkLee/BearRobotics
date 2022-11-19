#pragma once
#include "../core/WorkProcessing.h"
class CDummySimpleATM
{
public:
	CDummySimpleATM();
	~CDummySimpleATM();

	void Start();
	void InsertPinNumber();
	void InsertAccount();
	void ShowHistory();
	void Withdraw();
	void Deposit();
	void GoToInsertPinNum();

private:
	string m_strAccount;
	CWorkProcessing m_WorkingProcess;
};

