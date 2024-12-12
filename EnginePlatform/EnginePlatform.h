#pragma once

// Ό³Έν :
class EnginePlatform
{
public:
	// constrcuter destructer
	EnginePlatform();
	~EnginePlatform();

	// delete Function
	EnginePlatform(const EnginePlatform& _Other) = delete;
	EnginePlatform(EnginePlatform&& _Other) noexcept = delete;
	EnginePlatform& operator=(const EnginePlatform& _Other) = delete;
	EnginePlatform& operator=(EnginePlatform&& _Other) noexcept = delete;

protected:

private:

};
