#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

void EnemyFactory::Init()
{
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetName("Slime");
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetMaxHealth(100);
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetStrength(3);
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetDexterityh(2);
    myEnemyTypes[static_cast<int>(eEnemyType::Slime)].SetStamina(1);

    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetName("Dragon");
    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetMaxHealth(150);
    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetStrength(5);
    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetDexterityh(1);
    myEnemyTypes[static_cast<int>(eEnemyType::Dragon)].SetStamina(1);

    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetName("Skeleton");
    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetMaxHealth(50);
    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetStrength(1);
    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetDexterityh(1);
    myEnemyTypes[static_cast<int>(eEnemyType::Skeleton)].SetStamina(1);

}

Enemy EnemyFactory::CreatEnemy(const eEnemyType aEnemyType) const
{
    Enemy newEnemy(myEnemyTypes[static_cast<int>(aEnemyType)]);
    return newEnemy;
}
