#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

class Player : public GameObject {
public:
	Player(int index, sf::Vector2f position, float scale = 5.0f);
	void update();
	
	void run() { m_bRunning = true; m_pBody->SetLinearVelocity(b2Vec2(5.0f, m_pBody->GetLinearVelocity().y));}
	void jump();
	bool isRunning() { return m_bRunning; }
	bool isJumping() { return m_bJumping; }
	void scale(float relativeScale);
private:
	sf::Clock m_invClock;
	sf::Time m_time;
	float m_relativeScale;
	float m_colWidth;
	bool m_bRunning;
	bool m_bJumping;
	bool m_bInvulnerable;
};

#endif // PLAYER_H