// 2023.4.23,2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "cInventory.h"

void InitStore(cInventory* inven);

int main()
{
	cInventory* pPlayerInven = new cInventory;
	cInventory* pStore = new cInventory;

	InitStore(pStore);

	cout << "======== 상점 ========" << endl;
	pStore->Show();
	cout << endl;

	tagItem* buyItem = pStore->Delete("대검");
	if (buyItem != NULL)
	{
		pPlayerInven->Add(*buyItem);
		delete buyItem;
	}

	cout << "======== 플레이어 ========" << endl;
	pPlayerInven->Show();
	cout << endl;

	cout << "======== 상점 ========" << endl;
	pStore->Show();
	cout << endl;

	delete pStore;
	delete pPlayerInven;

	system("pause");

	return 0;
}

void InitStore(cInventory* inven)
{
	tagItem stItem;

	stItem = tagItem(E_ARMOR, "판금 방어구");
	inven->Add(stItem);

	stItem = tagItem(E_WEAPON, "대검");
	inven->Add(stItem);

	stItem = tagItem(E_HP_POTION, "소형 HP포션");
	inven->Add(stItem);

	stItem = tagItem(E_MP_POTION, "소형 MP포션");
	inven->Add(stItem);
}
