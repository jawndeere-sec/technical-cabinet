#include <raylib.h> // allows us access to all the good raylib stuff
#include <raymath.h> // allows for matrix transform for dice rotation
#include <cmath> // for fabs
#include <cstdio>   // <-- for sprintf


int main () {
    // init window
    const char *windowTitle = "RollHighOrDie";
    int screenHeight = 800;
    int screenWidth = 800;
    InitWindow(screenWidth, screenHeight, windowTitle);  // Initialize window and OpenGL context

    // establish frame rate
    SetTargetFPS(60);

    // game plane values
    Vector2 planeSize = {10000,10000};
    Vector3 planeCenter = {0,0,0};

    // dice values
    Vector3 spherePos = {0,1,0};
    float speed = 7.0f;
    float sphereRadius = 1.0f;
    Mesh mesh = GenMeshSphere(sphereRadius, 4, 4);
    Model model = LoadModelFromMesh(mesh);

    // dice rotation
    float rotationX = 0.0f;
    float rotationZ = 0.0f;

    // camera definition - values are x axis, y axis, z axis. Y is up, z is forwards/backwards, x is left/right
    // moving to following camera
    Camera3D camera = {0};
    float heightOffset = 4.0f;
    float fixedCameraHeight = 7.0f;
    float distanceBehind = 8.0f;
    camera.position.x = spherePos.x;
    camera.position.y = fixedCameraHeight;
    camera.position.z = spherePos.z - distanceBehind;
    camera.target = spherePos;
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.projection = CAMERA_PERSPECTIVE;  // dice should get smaller as it gets further away
    camera.fovy = 45.0f; // field of view

    //platform struct - allows for move to procedural level generation and object-oriented design
    struct Platform {
        float platformWidth;
        float platformHeight;
        float platformLength;
        Vector3 platformCenter;
        float Left() const {return platformCenter.x - platformWidth/2;}
        float Right() const {return platformCenter.x + platformWidth/2;}
        float Back() const {return platformCenter.z - platformLength/2;}
        float Front() const {return platformCenter.z + platformLength/2;}
        float Top() const {return platformCenter.y + platformHeight/2;}
        bool ContainsXZ(Vector3 spherePos, float sphereRadius) const
        {
            return
                spherePos.x >= Left() &&
                spherePos.x <= Right() &&
                spherePos.z >= Back() &&
                spherePos.z <= Front();
        }
    };

    //Procedural level generation through gaps and offsets from the LAST platform.
    Platform platforms[200];
    const int platformCount = 200;

    platforms[0] = {2.5f, 1.0f, 2.5f, planeCenter };   // spawn

    for (int i = 1; i < platformCount; i++)
    {
        float difficulty = i / 40.f;
        float minGap = 6.0f + difficulty * 2.0f;
        float maxGap = 12.0f + difficulty * 3.0f;
        float minX = -4.0f;
        float maxX = 4.0f;


        float gap = GetRandomValue(minGap * 100, maxGap * 100) / 100.0f;
        float offsetX = GetRandomValue(minX * 100, maxX * 100) / 100.0f;
    
        platforms[i].platformWidth  = 3.0;
        platforms[i].platformHeight = 1.0f;
        platforms[i].platformLength = 3.0f;
    
        platforms[i].platformCenter.z =
            platforms[i-1].platformCenter.z + gap;
        platforms[i].platformCenter.x = offsetX;
        platforms[i].platformCenter.y = 1.0f;
    };
    
    // physics values
    // place sphere properly on spawn platform
    spherePos.y = platforms[0].Top() + sphereRadius;
    float VelocityY = 0.0f;
    float gravity = 13.0f;
    float jumpForce = 10.5f;
    bool onGround = true;

    // death logic
    bool isDead = false;
    float deathTimer = 0.0f;
    
    int currentPlatform = -1;
    spherePos.y = platforms[0].Top() + sphereRadius;
    float currentScore = 0.0f;
    float lastScore = 0.0f;

    // =====================================================
    // GAME LOOP
    // =====================================================
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // =============================================
        // UPDATE
        // =============================================

        if (!isDead)
        {
            currentScore = spherePos.z; // increment score on directional movement

            // ---- INPUT ----
            if (IsKeyPressed(KEY_SPACE) && onGround)
            {
                VelocityY = jumpForce;
                onGround = false;
            }

            if (IsKeyDown(KEY_UP))
            {
                float moveZ = speed * dt;
                spherePos.z += moveZ;
                rotationX += moveZ / sphereRadius;
            }

            if (IsKeyDown(KEY_DOWN))
            {
                float moveZ = speed * dt;
                spherePos.z -= moveZ;
                rotationX -= moveZ / sphereRadius;
            }

            if (IsKeyDown(KEY_LEFT))
            {
                float moveX = speed * dt;
                spherePos.x += moveX;
                rotationZ += moveX / sphereRadius;
            }

            if (IsKeyDown(KEY_RIGHT))
            {
                float moveX = speed * dt;
                spherePos.x -= moveX;
                rotationZ -= moveX / sphereRadius;
            }

            // ---- GRAVITY ----
            VelocityY -= gravity * dt;
            spherePos.y += VelocityY * dt;

            // ---- COLLISION (simple + stable) ----
            onGround = false;

            for (int i = 0; i < platformCount; i++)
            {
                float top = platforms[i].Top();
                float bottom = spherePos.y - sphereRadius;

                if (
                    VelocityY <= 0 && // only when falling
                    platforms[i].ContainsXZ(spherePos, sphereRadius) &&
                    bottom <= top &&
                    bottom >= top - 0.4f   // landing tolerance
                )
                {
                    spherePos.y = top + sphereRadius;
                    VelocityY = 0;
                    onGround = true;
                    break;
                }
            }
        }

        // ---- DEATH ----
        if (spherePos.y <= -5 && !isDead)
        {
            isDead = true;
            deathTimer = 0.0f;
            lastScore = currentScore;
        }

        if (isDead)
        {
            deathTimer += dt;

            if (deathTimer > 1.0f)
            {
                spherePos.x = platforms[0].platformCenter.x;
                spherePos.z = platforms[0].platformCenter.z;
                spherePos.y = platforms[0].Top() + sphereRadius;
                VelocityY = 0;
                onGround = true;
                isDead = false;
                currentScore = 0.0f;
            }
        }

        // ---- CAMERA ----
        camera.position.x = spherePos.x;
        camera.position.y = fixedCameraHeight;
        camera.position.z = spherePos.z - distanceBehind;
        camera.target = spherePos;

        // =============================================
        // DRAW
        // =============================================

        BeginDrawing();
        ClearBackground({15, 5, 25, 255});

        BeginMode3D(camera);

            model.transform = MatrixMultiply(
                MatrixRotateX(rotationX),
                MatrixRotateZ(rotationZ)
            );

            DrawModel(model, spherePos, 1.0f, GRAY);
            DrawPlane(planeCenter, planeSize, ORANGE);

            for (int i = 0; i < platformCount; i++)
            {
                float progress = platforms[i].platformCenter.z / 500.0f;
                float hue = 210 + progress * 180;
                while (hue > 360) hue -= 360;

                Color color = (i == 0) ? GREEN :
                            ColorFromHSV(hue, 0.85f, 1.0f);



                DrawCube(
                    platforms[i].platformCenter,
                    platforms[i].platformWidth,
                    platforms[i].platformHeight,
                    platforms[i].platformLength,
                    color
                );
            }

        EndMode3D();

        char scoreText[64];
        snprintf(scoreText, sizeof(scoreText), "DISTANCE: %.1f", currentScore);
        DrawText(scoreText, 20, 20, 30, WHITE);

        char lastScoreText[64];
        snprintf(lastScoreText, sizeof(lastScoreText), "LAST RUN: %.1f", lastScore);
        DrawText(lastScoreText, 20, 60, 30, GRAY);


        DrawText("ROLL HIGH OR DIE!", screenWidth/2 - 175, screenHeight/2 + 300, 40, WHITE);

        if (isDead)
            DrawText("OH NO, YOU DIED!", screenWidth/2 - 175, screenHeight/2 + 200, 40, RED);

        EndDrawing();
    }
}
