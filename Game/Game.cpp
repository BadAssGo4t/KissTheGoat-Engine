#include "Game.h"

Game::Game()
{
	downAnim = nullptr;
	idleDownAnim = nullptr;
	leftAnim = nullptr;
	idleLeftAnim = nullptr;
	idleRightAnim = nullptr;
	rightAnim = nullptr;
	upAnim = nullptr;
	idleUpAnim = nullptr;
	iddleBoardAnim = nullptr;

	/*shape = Shape(ShapeType::Triangle);
	squareAuto = Shape(ShapeType::Square);*/

}

void Game::Play()
{
	EngineInit(800, 800, "Padoru Season");
	UpdateEngine();
}

enum State
{
	Sleft, Sright, Sup, Sdown
};
State sonnehState = Sdown;

void Game::Start()
{
	/*shape.SetPosition(1.0f, 0.0f, 0.0f);
	squareAuto.SetPosition(1.0f, 0.0f, 0.0f);*/
	Board = Sprite("Res/Sprites/sonic_mania_sprites.png");
	fast = Sprite("Res/Sprites/R.png");
	sonneh = Sprite("Res/Sprites/sonic_mania_sprites.png");
	
	


	Board.canCollision = true;
	sonneh.canCollision = true;
	Board.weight = 2;
	sonneh.strength = 1;


	iddleBoardAnim = new Animation();
	iddleBoardAnim->AddFrame(132, 94, 49, 48, 830, 465, 0.0008, 5);
	rightAnim = new Animation();
	rightAnim->AddFrame(272, 307, 35.8, 39, 830, 465, 0.001, 12);
	upAnim = new Animation();
	upAnim->AddFrame(272, 307, 35.8, 39, 830, 465, 0.001, 12);
	leftAnim = new Animation();
	leftAnim->AddFrame(272, 307, 35.8, 39, 830, 465, 0.001, 12);
	downAnim = new Animation();
	downAnim->AddFrame(272, 307, 36.3, 39, 830, 465, 0.001, 12);
	idleDownAnim = new Animation();
	idleDownAnim->AddFrame(45, 399, 30.8, 39, 830, 465, 0.001, 7);

	Board.SetAnimation(iddleBoardAnim);
	Board.SetPosition(5.5f, 0.0f, -1.0f);

	

	sonneh.SetAnimation(idleDownAnim);
	sonneh.SetPosition(1.0f, 0.0f, -1.0f);

	fast.SetPosition(0.0f, 2.1f, -1.0f);
	fast.Scale(20.0f, 20.0f, 20.0f);
	
	
	
}
float a = 1.0f;
float cameraX = 1.0f;
float cameraY = 2.4f;
float cameraZ = 15.0f;

const float valueModif = 0.1f;

float testX = -0.5f;
void Game::Update()
{
	a += 0.0001;
	////shape.Rotate(0, 0, a);
	///*shape.Scale(0.1 + a, 1, 1);
	//shape.SetPosition(-1 + a, 0, 0);
	//squareAuto.Draw();*/

	CameraMove(cameraX, cameraY, cameraZ);

	//squareAuto.Rotate(0.0f, 0.0f, 0.0f + a);

	//squareAuto.Draw();
	//shape.Draw();

	Input(KEYCODE_Z, cameraX, -valueModif);
	Input(KEYCODE_X, cameraY, -valueModif);
	Input(KEYCODE_C, cameraZ, -valueModif);

	Input(KEYCODE_V, cameraX, valueModif);
	Input(KEYCODE_B, cameraY, valueModif);
	Input(KEYCODE_N, cameraZ, valueModif);

	Input(KEYCODE_1, testX, valueModif);

	//sonneh.Rotate(0, 0, a);

	if (GetKey(KEYCODE_A))
	{
		sonnehState = Sleft;
		sonneh.SetAnimation(leftAnim);
		sonneh.SetPosition(sonneh.GetPositionX() - 0.1f, sonneh.GetPositionY(), sonneh.GetPositionZ());
	}
	else if (sonnehState == Sleft)
	{
		sonneh.SetAnimation(idleDownAnim);
	}
	if (GetKey(KEYCODE_D))
	{
		sonnehState = Sright;
		sonneh.SetAnimation(rightAnim);
		sonneh.SetPosition(sonneh.GetPositionX() + 0.1f, sonneh.GetPositionY(), sonneh.GetPositionZ());
	}
	else if (sonnehState == Sright)
	{
		sonneh.SetAnimation(idleDownAnim);
	}
	if (GetKey(KEYCODE_W))
	{
		sonnehState = Sup;
		sonneh.SetAnimation(upAnim);
		sonneh.SetPosition(sonneh.GetPositionX(), sonneh.GetPositionY() + 0.1f, sonneh.GetPositionZ());
	}
	else if (sonnehState == Sup)
	{
		sonneh.SetAnimation(idleDownAnim);
	}
	if (GetKey(KEYCODE_S))
	{
		sonnehState = Sdown;
		sonneh.SetAnimation(downAnim);
		sonneh.SetPosition(sonneh.GetPositionX(), sonneh.GetPositionY() - 0.1f, sonneh.GetPositionZ());
	}
	else if (sonnehState == Sdown)
	{
		sonneh.SetAnimation(idleDownAnim);
	}

	
	
	fast.Draw();
	Board.Update();
	Board.Draw();
	sonneh.CheckCollisionAABB(Board);
	sonneh.Update();
	sonneh.Draw();

}

bool Game::Input(int keycode, float& variable, float modif)
{
	if (GetKey(keycode))
	{
		variable += modif;
		return true;
	}
	return false;
}

void Game::Delete()
{
	if (iddleBoardAnim) delete iddleBoardAnim;
	if (rightAnim) delete rightAnim;
	if (leftAnim) delete leftAnim;
	if (upAnim) delete upAnim;
	if (downAnim) delete downAnim;
	if (idleRightAnim) delete idleRightAnim;
	if (idleUpAnim) delete idleUpAnim;
	if (idleLeftAnim) delete idleLeftAnim;
	if (idleDownAnim) delete idleDownAnim;
}