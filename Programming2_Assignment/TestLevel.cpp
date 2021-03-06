#include "TestLevel.h"
#include "Font.h"

TestLevel::TestLevel() : GameScene()
{
	std::cout << glGetString(GL_VERSION) << std::endl;

	/*
	====================================================================================================
	SCENE SETUP
	====================================================================================================
	*/
	{
		GameObject* cameraGameObject = new GameObject(this);

		// Transform
		sceneCamera = cameraGameObject->addComponent<Camera>();
		sceneCamera->Init(70.0f, (DISPLAY_WIDTH / DISPLAY_HEIGHT), 0.01f, 1000.0f);
		cameraGameObject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.5f, -5.0f));
	}

	/*
	====================================================================================================
	CW SHADER 1 - EXPLODING SHADER
	====================================================================================================
	*/
	{
		GameObject* explodingGameobject = new GameObject(this);
		sceneGameObjects.push_back(explodingGameobject);

		// Transform
		explodingGameobject->thisTransform->SetGlobalPos(glm::vec3(4.0f, 0.0f, 7.5f));
		explodingGameobject->thisTransform->SetGlobalRot(glm::vec3(0.0f, (3.14f * 0.75f), 0.0f));

		// Movement
		MeshMovement* mm = explodingGameobject->addComponent<MeshMovement>();
		mm->SetMovementDirection(glm::vec3(0.0f, 0.0f, 1.0f));
		mm->SetMovementMagnitude(5.0f);
		mm->SetRotationMagnitude(3.14f * 0.33f);

		// Rendering
		MeshRenderer* renderer = explodingGameobject->addComponent<MeshRenderer>();
		string meshFilePath = "..\\res\\saxophone.obj";
		string textureFilePath = "..\\res\\gradient.jpg";
		string shaderFilePath = "..\\res\\shaderGeoText";
		renderer->Init(meshFilePath, textureFilePath, shaderFilePath);

		// Shader Handling
		ExplosionHandler* eh = explodingGameobject->addComponent<ExplosionHandler>();
		eh->SetMaxSize(10.0f);
	}


	/*
	====================================================================================================
	CW SHADER 2 - ENVIRONMENT REFLECTION SHADER
	====================================================================================================
	*/
	{
		// Skybox
		GameObject* skyboxGameobject = new GameObject(this);
		sceneGameObjects.push_back(skyboxGameobject);
		SkyboxRenderer* sr = skyboxGameobject->addComponent<SkyboxRenderer>();
		vector<std::string> skyboxFaces
		{
			"..\\res\\skybox\\right.jpg",
			"..\\res\\skybox\\left.jpg",
			"..\\res\\skybox\\top.jpg",
			"..\\res\\skybox\\bottom.jpg",
			"..\\res\\skybox\\front.jpg",
			"..\\res\\skybox\\back.jpg"
		};
		sr->Init(skyboxFaces, "..\\res\\shaderSkybox");


		// Gameobject
		GameObject* reflectionGameobject = new GameObject(this);
		sceneGameObjects.push_back(reflectionGameobject);

		// Transform
		reflectionGameobject->thisTransform->SetGlobalPos(glm::vec3(-2.75f, -0.75f, 3.0f));
		reflectionGameobject->thisTransform->SetGlobalRot(glm::vec3(0.0f, (3.14f * 0.75f), 0.0f));

		// Movement
		MeshMovement* mm = reflectionGameobject->addComponent<MeshMovement>();
		mm->SetMovementDirection(glm::vec3(0.0f, 0.0f, 0.0f));
		mm->SetMovementMagnitude(7.5f);
		mm->SetRotationMagnitude(3.14f * 0.1f);

		// Rendering
		MeshRenderer* renderer = reflectionGameobject->addComponent<MeshRenderer>();
		string meshFilePath = "..\\res\\piano.obj";
		string shaderFilePath = "..\\res\\shaderReflection";
		Skybox* skybox = sr->GetSkybox();
		renderer->Init(meshFilePath, skybox, shaderFilePath);
	}


	/*
	====================================================================================================
	CW SHADER 3 - ADDITIONAL GRAPHICAL TECHNIQUE - RAYMARCHING
	====================================================================================================
	*/
	{
		// Cube GameObject
		GameObject* cube = new GameObject(this);
		sceneGameObjects.push_back(cube);
		cube->thisTransform->SetGlobalPos(glm::vec3(0.0f, -2.5f, 0.0f));

		MeshMovement* cubeMR = cube->addComponent<MeshMovement>();
		cubeMR->SetMovementDirection(glm::vec3(1.0f, 0.0f, 0.0f));
		cubeMR->SetMovementMagnitude(0.0f);

		// Sphere Gameobject
		GameObject* sphere = new GameObject(this);
		sceneGameObjects.push_back(sphere);
		sphere->thisTransform->SetGlobalPos(glm::vec3(0.0f, -2.5f, 0.0f));

		MeshMovement* sphereMR = sphere->addComponent<MeshMovement>();
		sphereMR->SetMovementDirection(glm::vec3(1.0f, 0.0f, 0.0f));
		sphereMR->SetMovementMagnitude(1.75f);



		// Raymarching Gameobject
		GameObject* raymarchGameobject = new GameObject(this);
		raymarchGameobject->thisTransform->SetGlobalPos(glm::vec3(0.0f, 0.0f, 1.0f));
		sceneGameObjects.push_back(raymarchGameobject);

		// Compute Shader Test
		RaymarchHandler* rh = raymarchGameobject->addComponent<RaymarchHandler>();
		rh->Init(sphere, cube);
		
	}
}