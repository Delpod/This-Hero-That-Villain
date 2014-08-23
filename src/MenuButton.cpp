#include "MenuButton.h"

MenuButton::MenuButton(sf::Font &font, std::string text, int callback) : m_callback(callback) {
	m_text.setColor(sf::Color::Black);
	if(m_callback == 0)
		m_text.setCharacterSize(250);
	else 
		m_text.setCharacterSize(150);
	m_text.setFont(font);
	m_text.setString(text);
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setScale(0.5f, 0.5f);
	m_big = false;
}