#pragma once
#include <string_view>
#include <EngineBase/EngineMath.h>


// 원본 사이즈에서 곱해지는 비율
static const float ScaleRatio = 2.8f;

// 시작 모드
static std::string_view START_MODE = "PLAY";

// 윈도우 창 크기
static const FVector WINDOW_SIZE = { 1280, 720 };
static const FVector HALF_WINDOW_SIZE = WINDOW_SIZE * 0.5;

// 엘리 기본 사이즈
static const FVector ELLIESIZE = { 50.0f, 50.0f, 0.0f };
static const FVector ELLIESIZE_PLUS = ELLIESIZE * ScaleRatio;

// 엘리 애니메이션 스피드
static const float ELLIE_ANIMDEFAULT_SPEED = 0.13f;

// 엘리 걷기, 뛰기 스피드
static float ELLIE_WALK_SPEED = 600.0f;
static float ELLIE_RUN_SPEED = 1000.0f;

// 각 방향 벡터
static const FVector VECTOR_NONE = { 0.0f, 0.0f, 0.0f };
static const FVector VECTOR_UP = { 0.0f, 1.0f, 0.0f };
static const FVector VECTOR_DOWN = { 0.0f, -1.0f, 0.0f };
static const FVector VECTOR_LEFT = { -1.0f, 0.0f, 0.0f };
static const FVector VECTOR_LEFT_UP = { -1.0f, 1.0f, 0.0f };
static const FVector VECTOR_LEFT_DOWN = { -1.0f, -1.0f, 0.0f };
static const FVector VECTOR_RIGHT = { 1.0f, 0.0f, 0.0f };
static const FVector VECTOR_RIGHT_UP = { 1.0f, 1.0f, 0.0f };
static const FVector VECTOR_RIGHT_DOWN = { 1.0f, -1.0f, 0.0f };

// 필드 정보
static const FVector GreenFieldSize = { 720.0f , 608.0f , 0.0f };	// 그린 필드
static const FVector GreenFieldSize_Plus = GreenFieldSize * ScaleRatio;
static const FVector HomeFieldSize = { 480.0f , 464.0f , 0.0f };	// 홈 필드
static const FVector HomeFieldSize_Plus = HomeFieldSize * ScaleRatio;

// 오브젝트 정보
// 나무
static FVector TREE_SIZE_0 = { 112.0f, 128.0f, 0.0f };
static FVector TREE_SIZE_1 = { 144.0f, 138.0f, 0.0f };

// 인벤토리
static FIntPoint InvenSize = {4, 6};
static int OpenSlot = 15;
// 베이스 크기
static FVector INVENTORY_Base = { 108.0f, 156.0f, 0.0f };
// 기본 위치
static FVector INVENTORY_Pos = { -400.0f, 0.0f };



