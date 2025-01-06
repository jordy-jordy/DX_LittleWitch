#pragma once

// Ό³Έν :
class AField_Home
{
public:
	// constrcuter destructer
	AField_Home();
	~AField_Home();

	// delete Function
	AField_Home(const AField_Home& _Other) = delete;
	AField_Home(AField_Home&& _Other) noexcept = delete;
	AField_Home& operator=(const AField_Home& _Other) = delete;
	AField_Home& operator=(AField_Home&& _Other) noexcept = delete;

protected:

private:

};
