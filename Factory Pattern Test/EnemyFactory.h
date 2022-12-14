#pragma once
#include "Enemy.h"
#include "EnemyType.h"
#include <array>
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();


	void Init();
	//Enemy CreatEnemy(const eEnemyType aEnemyType) const;
	std::shared_ptr<Enemy> CreatEnemy(const eEnemyType aEnemyType) const;
private:
	std::array <EnemyType, static_cast<int>(eEnemyType::Count)> myEnemyTypes;
};

