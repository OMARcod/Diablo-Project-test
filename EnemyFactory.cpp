#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::Init()
{
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetName("Ghost");
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetMaxHealth(100);
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetStrength(30);

    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetName("Dog");
    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetMaxHealth(150);
    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetStrength(50);

    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetName("Rat");
    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetMaxHealth(50);
    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetStrength(10);
}

std::shared_ptr<Enemy> EnemyFactory::CreatEnemy(const eEnemyType aEnemyType) const
{
    Enemy newEnemy(myEnemyTypes[static_cast<int>(aEnemyType)]);
    return std::make_shared<Enemy>(newEnemy);
}
