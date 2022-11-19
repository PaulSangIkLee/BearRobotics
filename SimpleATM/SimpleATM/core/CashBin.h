#pragma once

const int WORLD_BILL = 134001;

class CCashBin
{
public:
	CCashBin();
	~CCashBin();
	bool WithdrawBill(int nCash);
	bool DepositBill(int nCash);

private:
	int m_nSurplusBill;
};

