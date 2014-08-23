#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy(int index, sf::Vector2f position, float scale = 5.0f);
	void update();
};

#endif // ENEMY_H
