#pragma once


// Ό³Έν :
class AInventory 
{
public:
	// constrcuter destructer
	AInventory();
	~AInventory();

	// delete Function
	AInventory(const AInventory& _Other) = delete;
	AInventory(AInventory&& _Other) noexcept = delete;
	AInventory& operator=(const AInventory& _Other) = delete;
	AInventory& operator=(AInventory&& _Other) noexcept = delete;


protected:


private:


};