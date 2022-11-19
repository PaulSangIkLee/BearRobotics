#include "DummySimpleATM.h"
#include <iostream>



CDummySimpleATM::CDummySimpleATM()
{
}


CDummySimpleATM::~CDummySimpleATM()
{
}

void CDummySimpleATM::Start()
{
	cout << "This is SimpleATM" << endl;

	int nInput = 0;

	while(nInput != 1)
	{
		cout << "insert card 1-yes/ 2-no\t:\t";
		cin >> nInput;
	}
	if (nInput == 1)
	{
		InsertPinNumber();
	}
}

void CDummySimpleATM::InsertPinNumber()
{
	m_WorkingProcess.NewSession();
	m_strAccount = "";

	int nInput = 0;
	bool bSW = true;
	
	while(bSW)
	{
		cout << "Insert Pin Number(6 digits)\t:\t";
		cin >> nInput;

		if (m_WorkingProcess.SetPinNumber(nInput) == true)
		{
			bSW = false;
		}
		else
		{
			cout << "Wrong Number" << endl;
		}
	}
	InsertAccount();
}

void CDummySimpleATM::InsertAccount()
{
	vector<string> vecAccounts;
	vecAccounts = m_WorkingProcess.GetAccounts();

	cout << "*** Your Accounts ***" << endl << endl;
	for (int i = 0; i < vecAccounts.size(); i++)
	{
		cout << i + 1 << ". " << vecAccounts[i] << endl;
	}

	int nInput = 0;
	bool bSW = true;

	while (bSW)
	{
		cout << "Select Account(input previous number before full stop) \t:\t";
		cin >> nInput;

		if (nInput <= vecAccounts.size())
		{
			bSW = false;
			m_strAccount = vecAccounts[nInput - 1];
			m_WorkingProcess.SetAccount(m_strAccount);
		}		
	}

	nInput = 0;
	bSW = true;

	while (bSW)
	{
		cout << "1 - Show History / 2 - Withdraw / 3 - deposit please select number\t:\t";
		cin >> nInput;

		if (1 <= nInput && nInput <= 3)
		{
			bSW = false;
		}
	}

	m_WorkingProcess.GetBankTransactionHistory(m_strAccount);
	switch (nInput)
	{
	case 1:
		ShowHistory();
		break;
	case 2:
		Withdraw();
		break;
	case 3:
		Deposit();
		break;
	default:
		break;
	}
}

void CDummySimpleATM::ShowHistory()
{
	MAP_History_Daily mapHistory;
	mapHistory = m_WorkingProcess.GetBankTransactionHistory(m_strAccount);

	cout << endl << endl;
	MAP_History_Daily::reverse_iterator ritr;
	VEC_History vecDaily;
	string strTmp;

	cout << "Balance\t:\t" << m_WorkingProcess.GetBalanceOfAccount()<<endl;
	for (ritr = mapHistory.rbegin(); ritr != mapHistory.rend(); ritr++)
	{
		vecDaily = ritr->second;
		for (int i = 0; i < vecDaily.size(); i++)
		{
			strTmp = "Deposit \t";
			if (vecDaily[i].first == TYPE_OUT)
			{
				strTmp = "WithDraw\t";
			}
			cout << ritr->first << "\t" << strTmp << vecDaily[i].second << endl;
		}
	}

	GoToInsertPinNum();
}

void CDummySimpleATM::Withdraw()
{
	cout << "Balance\t:\t" << m_WorkingProcess.GetBalanceOfAccount() << endl;

	int nInput = 0;
	bool bSW = true;

	int nCnt = 0;
	while (bSW)
	{
		cout << "Input withdraw billls\t:\t";
		cin >> nInput;
		if (m_WorkingProcess.WithdrawBill(nInput))
		{
			cout << "Withdraw success!" << endl;
			bSW = false;
		}
		else
		{
			cout << "can not available!!" << endl;
			nCnt++;
			if (nCnt > 3)
			{
				bSW = false;
			}
		}
	}
	GoToInsertPinNum();

}

void CDummySimpleATM::Deposit()
{
	cout << "Balance\t:\t" << m_WorkingProcess.GetBalanceOfAccount() << endl;

	int nInput = 0;
	bool bSW = true;

	int nCnt = 0;
	while (bSW)
	{
		cout << "Input deposit billls\t:\t";
		cin >> nInput;
		if (m_WorkingProcess.DepositBill(nInput))
		{
			cout << "Depposit success!" << endl;
			bSW = false;
		}
		else
		{
			cout << "can not available!!" << endl;
			nCnt++;
			if (nCnt > 3)
			{
				bSW = false;
			}
		}
	}

	GoToInsertPinNum();
}

void CDummySimpleATM::GoToInsertPinNum()
{
	int nInput = 0;
	bool bSW = true;

	while (bSW)
	{
		cout << "go to pin Number check screen? 1 - yes / 2 - no(will terminate)\t:\t";
		cin >> nInput;

		if (1 == nInput || 2 == nInput)
		{
			bSW = false;
		}
	}
	if (nInput == 1)
	{
		InsertPinNumber();
	}
}
