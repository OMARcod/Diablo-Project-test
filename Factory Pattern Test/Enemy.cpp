#include "Enemy.h"

Enemy::Enemy(const EnemyType& aEnemyType)
    :myEnemyType(&aEnemyType)
{
    myHealth = myEnemyType->GetMaxHealth();
}

Enemy::~Enemy()
{
}

bool Enemy::IsAlive() const
{
    return myHealth > 0;
}

int Enemy::GetHealth() const
{
    return myHealth;
}

int Enemy::GetMaxHealth() const
{
    return myEnemyType->GetMaxHealth();
}

std::string Enemy::GetName() const
{
    return myEnemyType->GetName();
}

void Enemy::TakeDamage(const int aDamage)
{
    if (myHealth > 0)
    {
        myHealth -= aDamage;
    }
    else
    {
        myHealth = 0;
    }
}
