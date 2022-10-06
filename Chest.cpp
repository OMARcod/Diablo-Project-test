#include "Chest.h"


Chest::Chest(int anItemType, bool isLocked)
	:myItemID(anItemType), myLockIsClosed(isLocked)
{
	myItem.SetType(myItemID);
}

Chest::~Chest()
{
}
bool Chest::isChestEmpty()
{
	return myChestIsEmpty;
}

int Chest::EnterChest()
{
	int input = static_cast<int>(SharedFunctions::MyItems::NoItem);
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
				std::cout << myItem.GetItmeName();
				std::cout << "  -->  " << myItem.GetItmeInfo() << std::endl;;
				SharedFunctions::DrawLine();
				std::cout << "1. Take the itme" << std::endl;
				std::cout << "0. Exit" << std::endl;
				input = SharedFunctions::ReadInputInt(0, 1);
			}
			if (input == 1)
			{
				myChestIsEmpty = true;
				return myItemID;
			}
			if (input == 0)
			{
				return static_cast<int>(SharedFunctions::MyItems::NoItem);
			}
			system("pause");

		}
	}
	return static_cast<int>(SharedFunctions::MyItems::NoItem);
}
