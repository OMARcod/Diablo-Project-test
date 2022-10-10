#include <iostream>
#include "EnemyFactory.h"
#include "Enemy.h"


void PrintEnemyInfo(const Enemy& anEnemy)
{
    std::cout << anEnemy.GetName();
    std::cout <<" (HP: " << anEnemy.GetHealth() << "/" << anEnemy.GetMaxHealth() << ")" << std::endl;
}

int main()
{
    EnemyFactory enemyFactory;
    enemyFactory.Init();


    Enemy enemy = enemyFactory.CreatEnemy(eEnemyType::Slime);

    PrintEnemyInfo(enemy);
    enemy.TakeDamage(10);
    std::cout << "You attacked " << enemy.GetName() << " with your Weapon" << std::endl;
    PrintEnemyInfo(enemy);

    std::cout << "Hello World!\n";
}

