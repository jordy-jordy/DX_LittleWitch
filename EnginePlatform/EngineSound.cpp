#include "PreCompile.h"
#include "EngineSound.h"
#include <EngineBase/EngineString.h>
#include <EngineBase/EngineDebug.h>

std::map<std::string, UEngineSound*> UEngineSound::Sounds;
std::list<USoundPlayer> UEngineSound::Players;

// 사운드를 제어하기위한 핸들
FMOD::System* SoundSystem = nullptr;

#ifdef _DEBUG
#pragma comment(lib, "fmodL_vc.lib")
#else
#pragma comment(lib, "fmod_vc.lib")
#endif

USoundPlayer::USoundPlayer()
{

}
USoundPlayer::~USoundPlayer()
{
	// Stop();
}

void USoundPlayer::On()
{
	Control->setPaused(false);
}

void USoundPlayer::Off()
{
	Control->setPaused(true);
}

void USoundPlayer::Stop()
{
	Control->stop();
	Control = nullptr;
}

bool USoundPlayer::IsPlaying()
{
	bool Check = true;
	Control->isPlaying(&Check);
	return Check;
}

void USoundPlayer::SetVolume(float _Volume)
{
	_Volume = UEngineMath::Clamp(_Volume, 0.0f, 1.0f);

	Control->setVolume(_Volume);
}

void USoundPlayer::OnOffSwtich()
{
	bool Check = false;
	Control->getPaused(&Check);

	if (true == Check)
	{
		Control->setPaused(false);
	}
	else
	{
		Control->setPaused(true);
	}
}

void USoundPlayer::SetPosition(unsigned int _Value)
{
	Control->setPosition(_Value, FMOD_TIMEUNIT_MS);
}

void USoundPlayer::Loop(int Count/* = -1*/)
{
	Control->setLoopCount(Count);
}

void USoundPlayer::ReStart()
{
	SetPosition(0);
}

unsigned int USoundPlayer::LengthMs()
{
	unsigned int ResultLength = 0;
	SoundHandle->getLength(&ResultLength, FMOD_TIMEUNIT_MS);
	return ResultLength;
}

void UEngineSound::Init()
{
	if (FMOD_RESULT::FMOD_OK != FMOD::System_Create(&SoundSystem))
	{
		MSGASSERT("FMOD 시스템 이닛에 실패했습니다.");
		return;
	}

	// 사운드 채널설정
	// int maxchannels, 동시에 몇개까지 사운드 재생이 되는가?
	// FMOD_INITFLAGS flags, 지정사항이 있냐인데
	// void* extradriverdata 지정사항에 대한 데이터넣어줄게 있냐.
	if (FMOD_RESULT::FMOD_OK != SoundSystem->init(32, FMOD_DEFAULT, nullptr))
	{
		MSGASSERT("FMOD 시스템 이닛에 실패했습니다.");
		return;
	}

}

void UEngineSound::AllSoundStop()
{
	std::list<USoundPlayer>::iterator StartIter = Players.begin();
	std::list<USoundPlayer>::iterator EndIter = Players.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		USoundPlayer& CurSoundPlayer = *StartIter;
		CurSoundPlayer.Stop();
	}
}

void UEngineSound::AllSoundOn()
{
	std::list<USoundPlayer>::iterator StartIter = Players.begin();
	std::list<USoundPlayer>::iterator EndIter = Players.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		USoundPlayer& CurSoundPlayer = *StartIter;
		CurSoundPlayer.On();
	}
}

void UEngineSound::AllSoundOff()
{
	std::list<USoundPlayer>::iterator StartIter = Players.begin();
	std::list<USoundPlayer>::iterator EndIter = Players.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		USoundPlayer& CurSoundPlayer = *StartIter;
		CurSoundPlayer.Off();
	}
}


void UEngineSound::Update()
{
	if (nullptr == SoundSystem)
	{
		return;
	}

	std::list<USoundPlayer>::iterator StartIter = Players.begin();
	std::list<USoundPlayer>::iterator EndIter = Players.end();

	for (; StartIter != EndIter; )
	{
		USoundPlayer& CurSoundPlayer = *StartIter;

		if (true == CurSoundPlayer.IsPlaying())
		{
			++StartIter;
			continue;
		}

		StartIter = Players.erase(StartIter);
		
	}

	if (FMOD_RESULT::FMOD_OK != SoundSystem->update())
	{
		MSGASSERT("FMOD 시스템 업데이트에 이상이 감지되었습니다.");
	}
}

// 엔진이 끝날때 직접 호출
void UEngineSound::Release()
{
	std::map<std::string, UEngineSound*>::iterator StartIter = Sounds.begin();
	std::map<std::string, UEngineSound*>::iterator EndIter = Sounds.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}

	Sounds.clear();

	if (nullptr != SoundSystem)
	{
		SoundSystem->release();
		SoundSystem = nullptr;
	}
}

UEngineSound::UEngineSound()
{
}

UEngineSound::~UEngineSound()
{
	
	
	if (nullptr != SoundHandle)
	{
		SoundHandle->release();
		SoundHandle = nullptr;
	}
}

void UEngineSound::Load(std::string_view _Path)
{
	UEnginePath EnginePath = UEnginePath(_Path);
	std::string FileName = EnginePath.GetFileName();

	UEngineSound::Load(FileName.data(), _Path);
}

void UEngineSound::Load(std::string_view _Name, std::string_view _Path)
{
	// 이녀석은 UTF-8로 경로를 바꿔줘야 할수 있다.
	std::string UpperString = UEngineString::ToUpper(_Name);

	UEngineSound* NewSound = new UEngineSound();

	if (false != UEngineSound::Sounds.contains(UpperString))
	{
		delete NewSound;
		MSGASSERT("이미 로드한 사운드를 또 로드하려고 했습니다." + UpperString);
		return;
	}

	if (false == NewSound->ResLoad(_Path))
	{
		delete NewSound;
		MSGASSERT("사운드 로드에 실패했습니다" + UpperString);
		return;
	}

	UEngineSound::Sounds.insert({ UpperString, NewSound });
	// Load(FileName, Path);
}

UEngineSound* UEngineSound::Find(std::string_view _Name)
{
	std::string UpperString = UEngineString::ToUpper(_Name);

	if (false == Sounds.contains(UpperString))
	{
		return nullptr;
	}

	return Sounds[UpperString];
}

USoundPlayer UEngineSound::Play(std::string_view _Name)
{
	std::string UpperString = UEngineString::ToUpper(_Name);

	UEngineSound* FindSound = Find(_Name);

	if (nullptr == FindSound)
	{
		MSGASSERT("로드하지 않은 사운드를 재생하려고 했습니다" + UpperString);
	}


	// 그냥 단순히 재생하는게 아니라면 채널을 얻어와야 속략이나 피치 볼륨 믹싱 등등을 조절할수 있다.
	FMOD::Channel* Ch = nullptr;

	SoundSystem->playSound(FindSound->SoundHandle, nullptr, false, &Ch);

	// 이 재생에 관련된 모든 사항에 대한 
	// WINproc => 
	// Ch->setCallback();

	// 1번 재생
	Ch->setLoopCount(0);

	// 볼륨 1로
	Ch->setVolume(1.0f);

	USoundPlayer NewPlayer;
	NewPlayer.Control = Ch;
	NewPlayer.SoundHandle = FindSound->SoundHandle;

	Players.push_back(NewPlayer);

	return NewPlayer;
}


bool UEngineSound::ResLoad(std::string_view _Path)
{
	// 유니코드로 넣어도
	// 멀티바이트로 넣어도 제대로 안될때가 있다.
	// 그러면 UTF시리즈로 인코딩해서 넣어줘야할때가 있다.
	// FMOD를 사용하는 부분
	// 해봤더니 된다 UTF시리즈로 안해줘도 됐다.
	SoundSystem->createSound(_Path.data(), FMOD_LOOP_NORMAL, nullptr, &SoundHandle);

	if (nullptr == SoundHandle)
	{
		MSGASSERT("사운드 로딩에 실패했습니다" + std::string(_Path));
		return false;
	}

	return true;
}