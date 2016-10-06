#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include"SpaceshipController.h"

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
	   	 end = { 900, 800 },
		 mid = { 0, 1100 };

	Transform playerTransform(200, 200);
	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;

	playerTransform.scale = { 24,24 };

	while (sfw::stepContext())
	{ 
		float deltaTime = sfw::getDeltaTime();

		if (playerTransform.position.x > SCREEN_WIDTH)
			playerTransform.position.x = 0.0f;
		else if (playerTransform.position.x < 0.0f)
			playerTransform.position.x = SCREEN_WIDTH;

		if (playerTransform.position.y > SCREEN_HEIGHT)
			playerTransform.position.y = 0.0f;
		else if (playerTransform.position.y < 0.0f)
			playerTransform.position.y = SCREEN_HEIGHT;

		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();
		playerRigidbody.debugDraw(playerTransform);
	}
	sfw::termContext();
}