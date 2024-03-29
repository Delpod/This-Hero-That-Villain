#ifndef LEVEL_H
#define LEVEL_H
#include <list>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Level {
public:
	Level();
	void create(int diff);
	~Level();
	b2World*				 getWorld()	{ return m_pWorld; }
	Player*					 getPlayer()	{ return m_pPlayer; }
	Enemy*					 getEnemy()	{ return m_pEnemy; }
	GameObject*				 getGround()	{ return m_pGround; }
	std::list<GameObject*>*	 getObstacles() { return &m_obstacles; }
	void					 draw();
	void					 update();
private:
	void 					 generateObstacles(unsigned int diff);
	void					 generateOthers(unsigned int index);
	sf::Font				 m_pplFont;
	sf::Text				 m_pplText;
	sf::Clock				 m_clock;
	sf::Time				 m_time;
	GameObject				 *m_pBackground;
	std::vector<GameObject*> m_foreground;
	std::list<GameObject*>	 m_obstacles;
	std::mt19937			 m_random;
	GameObject				 *m_pGround;
	Player					 *m_pPlayer;
	Enemy					 *m_pEnemy;
	b2World					 *m_pWorld;
	unsigned int			m_size;
};

#endif // LEVEL_H