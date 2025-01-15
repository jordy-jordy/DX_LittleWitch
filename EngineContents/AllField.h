#pragma once
#include <EngineCore/Actor.h>

#include "GlobalVar.h"


// Ό³Έν :
class AAllField : public AActor
{
public:
	// constrcuter destructer
	AAllField();
	virtual ~AAllField();

	// delete Function
	AAllField(const AAllField& _Other) = delete;
	AAllField(AAllField&& _Other) noexcept = delete;
	AAllField& operator=(const AAllField& _Other) = delete;
	AAllField& operator=(AAllField&& _Other) noexcept = delete;

	virtual void InitializeField(std::shared_ptr<class USpriteRenderer> _Image, std::shared_ptr<class USpriteRenderer> _ColImage, std::shared_ptr<class UCollision> _Collision)
	{
		FieldImage = _Image;
		FieldColIamge = _ColImage;
		FieldCol = _Collision;
	}


protected:
	std::shared_ptr<class USpriteRenderer> FieldImage;
	std::shared_ptr<class USpriteRenderer> FieldColIamge;
	std::shared_ptr<class UCollision> FieldCol;


private:

};
