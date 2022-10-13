#include "Chest.h"
#include "ItemFactory.h"

Chest::Chest(bool isLocked)
	: myLockIsClosed(isLocked), myChestIsEmpty(false)
{
}

Chest::~Chest()
{
}

void Chest::AddItem(std::shared_ptr<Items> aItem)
{
	myItem = aItem;
}

bool Chest::isChestEmpty()
{
	return myChestIsEmpty;
}
std::shared_ptr<Items> Chest::GetChestItem()
{
	return myItem;
}
bool Chest::EnterChest()
{
	int input = -1;
	int exit = 0;
	if (!myChestIsEmpty)
	{
		while (input != exit)
		{
			if (!myLockIsClosed)
			{
				system("cls");
				std::cout << "------The Chest-------" << std::endl;
				std::cout << "ITEM!:" << std::endl;
				std::cout << myItem->GetName();
				std::cout << "  -->  ";
				myItem->GetItemInfo();
				SharedFunctions::DrawLine();
				std::cout << "1. Take the itme" << std::endl;
				std::cout << "0. Exit" << std::endl;
				input = SharedFunctions::ReadInputInt(0, 1);
			}
			if (input == 1)
			{
				myChestIsEmpty = true;
				return true;
			}
			if (input == 0)
			{
				return false;
			}
			system("pause");

		}
	}
	return false;
}
