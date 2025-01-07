#pragma once
#include <string_view>
#include <EngineBase/EngineMath.h>


static std::string_view START_MODE = "PLAY";

static FVector WINDOW_SIZE = { 1280, 720 };
static FVector HALF_WINDOW_SIZE = WINDOW_SIZE * 0.5;

static float ELLIE_ANIMDEFAULT_SPEED = 0.13f;

static float ELLIE_WALK_SPEED = 650.0f;
static float ELLIE_RUN_SPEED = 800.0f;

static FVector VECTOR_UP = { 0.0f, 1.0f, 0.0f };
static FVector VECTOR_DOWN = { 0.0f, -1.0f, 0.0f };
static FVector VECTOR_LEFT = { -1.0f, 0.0f, 0.0f };
static FVector VECTOR_LEFT_UP = { -1.0f, 1.0f, 0.0f };
static FVector VECTOR_LEFT_DOWN = { -1.0f, -1.0f, 0.0f };
static FVector VECTOR_RIGHT = { 1.0f, 0.0f, 0.0f };
static FVector VECTOR_RIGHT_UP = { 1.0f, 1.0f, 0.0f };
static FVector VECTOR_RIGHT_DOWN = { 1.0f, -1.0f, 0.0f };


