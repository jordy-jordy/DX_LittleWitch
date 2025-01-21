#pragma once
#include <string_view>
#include <EngineBase/EngineMath.h>

static const float ScaleRatio = 2.8f;

static std::string_view START_MODE = "PLAY";

static const FVector WINDOW_SIZE = { 1280, 720 };
static const FVector HALF_WINDOW_SIZE = WINDOW_SIZE * 0.5;

static const FVector ELLIESIZE = { 50.0f, 50.0f, 0.0f };
static const FVector ELLIESIZE_PLUS = ELLIESIZE * ScaleRatio;

static const float ELLIE_ANIMDEFAULT_SPEED = 0.13f;

static float ELLIE_WALK_SPEED = 500.0f;
static float ELLIE_RUN_SPEED = 800.0f;

static const FVector VECTOR_NONE = { 0.0f, 0.0f, 0.0f };
static const FVector VECTOR_UP = { 0.0f, 1.0f, 0.0f };
static const FVector VECTOR_DOWN = { 0.0f, -1.0f, 0.0f };
static const FVector VECTOR_LEFT = { -1.0f, 0.0f, 0.0f };
static const FVector VECTOR_LEFT_UP = { -1.0f, 1.0f, 0.0f };
static const FVector VECTOR_LEFT_DOWN = { -1.0f, -1.0f, 0.0f };
static const FVector VECTOR_RIGHT = { 1.0f, 0.0f, 0.0f };
static const FVector VECTOR_RIGHT_UP = { 1.0f, 1.0f, 0.0f };
static const FVector VECTOR_RIGHT_DOWN = { 1.0f, -1.0f, 0.0f };

static const FVector GreenFieldSize = { 720.0f , 604.0f , 0.0f };
static const FVector GreenFieldSize_Plus = GreenFieldSize * ScaleRatio;


