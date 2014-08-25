#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy(int index, sf::Vector2f position, float scale = 5.0f);
	void update();
	void run();
private:
	int m_rSide;
};

#endif // ENEMY_H
