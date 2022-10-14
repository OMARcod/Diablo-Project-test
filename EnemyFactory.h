#pragma once
#include "EnemyType.h"
#include "Enemy.h"
#include <array>
#include <memory>
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();

	void Init();



	std::shared_ptr<Enemy> CreatEnemy(const eEnemyType aEnemyType) const;
private:

	std::array <EnemyType, static_cast<int>(eEnemyType::Count)> myEnemyTypes;
};

