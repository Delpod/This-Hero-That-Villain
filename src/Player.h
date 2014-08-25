#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Audio.hpp>
#include "GameObject.h"

class Player : public GameObject {
public:
	Player(int index, sf::Vector2f position, float scale = 5.0f);
	void update();
	void run() { m_bRunning = true; m_pBody->SetLinearVelocity(b2Vec2(5.0f, m_pBody->GetLinearVelocity().y));}
	void jump();
	bool isRunning() { return m_bRunning; }
	bool isJumping() { return m_bJumping; }
private:
	sf::SoundBuffer m_buffer;
	sf::SoundBuffer m_bufferObs;
	sf::SoundBuffer m_bufferEnemy;
	sf::Sound m_sound;
	sf::Sound m_soundObs;
	sf::Sound m_soundEnemy;
	sf::Clock m_invClock;
	sf::Time m_time;
	float m_relativeScale;
	float m_colWidth;
	int m_rSide;
	bool m_bRunning;
	bool m_bJumping;
	bool m_bInvulnerable;
};

#endif // PLAYER_H