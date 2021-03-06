#pragma once
/////////////////////////////////////////////////
// Include
#include "gameObject\gameObject.h"
#include "eventSystem/eventListener.h"

/////////////////////////////////////////////////
// Enum
enum HeroSkin
{
	HeroSkin_Chest,
	HeroSkin_Pallet,
	HeroSkin_Present,

	HeroSkin_Count
};

class InputController;

/////////////////////////////////////////////////
// Class Hero
class Hero : public GameObject
{
public:
	Hero();

	virtual void update(float dt);
	virtual void physicsUpdate(float dt);

	virtual void intersect(Collision* collision);
	virtual void collisionEnter(Collision* collision);
	virtual void collisionStay(Collision* collision);
	virtual void collisionExit(Collision* collision);

	void setKeys(int leftKey, int rightKey, int jumpKey);
	void setKeys(std::string leftKey, std::string rightKey, std::string fireKey);

private:
	void spriteUpdate();

private:
	int m_leftKey;
	int m_rightKey;
	int m_jumpKey;

	bool m_isJump; 
	bool m_jump_key_was_pressed;

	HeroSkin m_heroSkin;

	float m_jumpForse;
	float m_moveForse;
	float m_maxHorizontalSpeed;

	float m_averageSpeed;
	float m_currentSpeed;

	InputController* m_inputController;
};