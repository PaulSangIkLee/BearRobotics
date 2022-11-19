#include "CashBin.h"



CCashBin::CCashBin()
{
	m_nSurplusBill = WORLD_BILL;
}


CCashBin::~CCashBin()
{
}

bool CCashBin::WithdrawBill(int nCash)
{
	bool bRetval = false;
	if (m_nSurplusBill - nCash > 0)
	{
		m_nSurplusBill = m_nSurplusBill - nCash;
		bRetval = true;
	}
	return bRetval;
}

bool CCashBin::DepositBill(int nCash)
{
	bool bRetval = false;
	if (m_nSurplusBill + nCash <= WORLD_BILL)
	{
		m_nSurplusBill = m_nSurplusBill + nCash;
		bRetval = true;
	}
	return bRetval;
}

