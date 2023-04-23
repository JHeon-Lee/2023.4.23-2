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
	tagItem* item = NULL; // ���濡 �������� ������� null ������ ��ȯ�ϱ� ���� ������ ���

	vector<tagItem>::iterator vecIter;

	for (vecIter = m_vecItem.begin(); vecIter != m_vecItem.end(); vecIter++) // iterator�� ���ؼ� �����ؾ��ϴ� ����
	{
		if (vecIter->strName == name) // ����ü �ȿ� �ִ� ������ �����ͷ� ���� ����
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
		cout << "������ ���� : ";
		switch (m_vecItem[i].itemType)
		{
		case E_ARMOR:
			cout << "��" << endl;
			break;
		case E_WEAPON:
			cout << "����" << endl;
			break;
		case E_HP_POTION:
			cout << "HP����" << endl;
			break;
		case E_MP_POTION:
			cout << "MP����" << endl;
			break;
		}

		cout << "������ �̸� : " << m_vecItem[i].strName.c_str() << endl;
		cout << "==========================================" << endl;
	}
}
