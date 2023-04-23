#include "pch.h"
#include "cInventory.h"

cInventory::cInventory()
{
}

cInventory::~cInventory()
{
}

void cInventory::Add(tagItem newItem)
{
	m_vecItem.push_back(newItem);
}

tagItem* cInventory::Delete(string name)
{
	tagItem* item = NULL; // 가방에 아이템이 없을경우 null 값으로 반환하기 위해 포인터 사용

	vector<tagItem>::iterator vecIter;

	for (vecIter = m_vecItem.begin(); vecIter != m_vecItem.end(); vecIter++) // iterator를 통해서 접근해야하는 이유
	{
		if (vecIter->strName == name) // 구조체 안에 있는 내용을 포인터로 지정 가능
		{
			item = new tagItem(vecIter->itemType, vecIter->strName);
			m_vecItem.erase(vecIter);
			break;
		}
	}

	return item;
}

void cInventory::Show()
{
	for (int i = 0; i < m_vecItem.size(); i++)
	{
		cout << "아이템 종류 : ";
		switch (m_vecItem[i].itemType)
		{
		case E_ARMOR:
			cout << "방어구" << endl;
			break;
		case E_WEAPON:
			cout << "무기" << endl;
			break;
		case E_HP_POTION:
			cout << "HP포션" << endl;
			break;
		case E_MP_POTION:
			cout << "MP포션" << endl;
			break;
		}

		cout << "아이템 이름 : " << m_vecItem[i].strName.c_str() << endl;
		cout << "==========================================" << endl;
	}
}
