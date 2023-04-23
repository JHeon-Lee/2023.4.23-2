#pragma once

enum E_ITEM {E_ARMOR, E_WEAPON, E_HP_POTION, E_MP_POTION};

struct tagItem
{
	E_ITEM itemType;
	string strName;

	tagItem() {};

	tagItem(E_ITEM _itemType, string _strName) // 기본 생성자가 없으면 생성자를 사용할 수 없다.
	{
		itemType = _itemType;
		strName = _strName;
	}
};

class cInventory
{
private:
	vector<tagItem> m_vecItem;


public:
	cInventory();
	~cInventory();

	void Add(tagItem newItem);	// 인벤토리에 아이템 넣기
	tagItem* Delete(string name);	// 인벤토리에서 아이템 꺼내기
	void Show();	// 인벤토리에 있는 아이템 목록 보여주기
};

