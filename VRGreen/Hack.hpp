#ifndef HACK_H
#define HACK_H



#include "Utils/http.h"

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <vector>
#include <thread>
#include <string>
#include <cstdint>
#include <mutex>
#include <memory>
#include <thread>
#include "ArrayList.hpp"
#include "List.hpp"
#include "Type.hpp"
#include "UnityEngine/Vector3.hpp"
#include "ExtendedAvatars.hpp"
#include "UnityEngine/Quaternion.hpp"

#include "detours/detours.h"

#include "IL2CPP/IL2CPP.hpp"


struct UserInteractMenu;
struct VRCPlayer;
struct EventData;
namespace VRC { struct Player; }
namespace VRC::Core { struct APIUser; struct ApiAvatar; }
namespace UnityEngine { struct GameObject; }
namespace VRC::SDKBase { struct VRC_EventHandler; struct VRCPlayerApi; }

class Hack
{
public:
	float emojiSpamDelay;
	float portalKOSDelay;
	float updateDelay;
	bool lobbyLag;
	bool toggleRPC;
	ExtendedAvatars* avatarFavorites;
	UnityEngine::Vector3 takeMyHeart;

	inline static Hack& getInstance();
	void init();
	void mainLoop();
	void destroy();

	static void* AvatarFav(void* _this, void* list, int sex, char nigger, void* maybe);

	template <typename T>
	static T DictionaryGet(void* dict, void* value, const std::string& typeName);

	template <typename T>
	static T DictionaryGet(void* dict, void* value);
private:

	struct mode;


	// variables
	std::vector<mode> settings;
	std::vector<std::string> clientUsers;
	std::mutex DetourMutex;
	std::string GoToRoomID;
	HANDLE threadId;
	
	
	bool seeBlocked;
	bool gravityHack;
	bool emojiSpam;
	bool disableTriggers;
	bool noGlobal;
	bool isTyping;
	bool menuInitialized;
	//


	void setupVariables();
	void downloadSettings();
	void generateHWID();
	void disableDetours();
	void setupSettings();

	static void* SaveWorlds(void* _this, void* params);
	static void RPCS(void* _this, int xxx, int VrcTargetType, UnityEngine::GameObject* gameObject, IL2CPP::String* RPC, void* bytes);
	static void _InstantiateObject(void* _this, IL2CPP::String* name, UnityEngine::Vector3 position, UnityEngine::Quaternion rotation, int num, VRC::Player* player);
	static void TeleportRPC(void* _this, UnityEngine::Vector3 position, UnityEngine::Quaternion rotation, void* SpawnOrientation, bool xxx, bool xxx1, VRC::Player* player);
	static void TakeOwnership(void* _this, VRC::SDKBase::VRCPlayerApi* vrcplayerapi);
	static void AddURL(void* _this, IL2CPP::String* url);
	static void OnEvent(void* _this, EventData* eventData);
	static void* TransportProtocolGet(void* _this);
	static void  TransportProtocolSet(void* _this, int value);
	static void   RoundTripTimePhoton(void* _this, void* data, int length);
	static void   DisconnectReason(void* _this, int reason);
	static void DestroyObject(void* _this, int xxx);
	static bool test1(void* _this, VRC::Player* player, int broadcastType, void* gameObject, bool xxx);
	static void* AntiWorldTriggers(void* _this, VRC::Player* player, VRC::SDKBase::VRC_EventHandler* eventHandler, void* VRC_EventHandler_VrcEvent, int VRC_EventHandler_VrcBroadcastType, int instagatorId, float xxx);
	static void SwitchAvatar(void* _this, VRC::Core::ApiAvatar* apiavatar, IL2CPP::String* fuzzy, float betterthen, void* tsumiki);
	static void OfflineMode(IL2CPP::String* target, void* responseContainer, void* requestParams, void* credentials);
	static void ReceiveVoteToKickInitiation(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static int Send(void* _this, void* buffer);
	static void Wtf(void* _this, VRC::Player* player);
	static void CloneAvatar(UserInteractMenu* __instance);
	static IL2CPP::String* GetFriendlyDetailedNameForSocialRank(VRC::Core::APIUser* apiuser);
	static void SendRequest(IL2CPP::String* endpoint, int method, void* responseContainer, void* requestParams, bool authenticationRequired, bool disableCache, float cacheLifetime, int retryCount, void* credentials);
	static void CustomPlates(VRCPlayer* __instance, void* aaa);
	static bool Serialize(void* _this);
	static void EventDispatcherExecuteRPCPrefix(void* _this, void* VrcBroadcastType, int aaaa, void* VrcTargetType, UnityEngine::GameObject* gameObject, IL2CPP::String* str, void* byteArray);
	static bool IsKicked2(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static bool JoinWorld(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static bool IsKickedFromWorld(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static void NoKickTrue(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, IL2CPP::String* str3);
	static void ForceLogoutRPC(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void FriendStateChangeRPC(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void ResetShowUserAvatarToDefaultRPC(void* _this, IL2CPP::String* player2, VRC::Player* player);
	static void ModMicGainChangeRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player);
	static void BanPublicOnlyRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player);
	static void BanRPC(void* _this, IL2CPP::String* player2, int date, VRC::Player* player);
	static void MuteChangeRPC(void* _this, IL2CPP::String* player2, bool state, VRC::Player* player);
	static void ModForceOffMicRPC(void* _this, IL2CPP::String* str, VRC::Player* player);
	static void ShowUserAvatarChangedRPC(void* _this, IL2CPP::String* player2, bool state, VRC::Player* player);
	static void SpawnEmojiRPC(void* _this, int emoji, VRC::Player* player);
	static void ShowSocialRankRPC(void* _this, bool state, VRC::Player* player);
	static void GotoRoomTargetUserRPC(void* _this, IL2CPP::String* str1, IL2CPP::String* str2, VRC::Player* player);
	static void PlayEmoteRPC(void* _this, int emote, VRC::Player* player);
	static void GotoRoomRPC(void* _this, IL2CPP::String* worldId, IL2CPP::String* instaceId, VRC::Player* player);
	static void TakePhotoRPC(void* _this, VRC::Player* player);
	static void BlockStateChangeRPC(void* _this, IL2CPP::String* player2, bool blockState, VRC::Player* player);
	static void PlayerLeft(void* _this, VRC::Player* player);
	static void PlayerJoined(void* _this, VRC::Player* player);
	static void* ReceiveAudio(void* _this, long long arr, int length);
	static void OnTriggerEnter(void* _this, void* collider);
	static void KickUserRPC(void* _this, IL2CPP::String* player2, IL2CPP::String* str2, IL2CPP::String* str3, IL2CPP::String* str4, VRC::Player* player);
	static void WarnUserRPC(void* _this, IL2CPP::String* player2, IL2CPP::String* str2, VRC::Player* player);
	static void Update(void* _this);
	static void ConfigurePortal(void* _this, IL2CPP::String* world_id, IL2CPP::String* instance_id, int32_t playersInWorld, VRC::Player* player);
	static void InternalTriggerEvent(VRC::SDKBase::VRC_EventHandler* _this, void* vrc_event, int broadcastType, int instagatorId, float fastForward);
	static int get_RoundTripTimeDetour(void* _this);
	static IL2CPP::String* get_DeviceId();
	void initDetours();
	mode& getSetting(std::string settingName);
	void toggleSetting(std::string settingName);
	static void promptRoomID();
	static void testReturnStrings(std::vector<ptrdiff_t>& vector);
	static std::string getEmoji(int i);

};

template <typename T>
T Hack::DictionaryGet(void* dict, void* value, const std::string& typeName)
{
	auto method = System::Type::GetType(dict)->GetMethod("TryGetValue");

	auto arraylist = System::Collections::ArrayList::ctor();
	arraylist->Add(IL2CPP::ValueBox(typeName, &value));
	arraylist->Add(nullptr);

	auto array_ = arraylist->ToArray();

	method->Invoke(dict, array_);

	List<IL2CPP::String*> objarray((IL2CPP::Array*)array_);

	if (objarray[1] != nullptr)
		return (T)(*(T*)IL2CPP::ObjectUnbox(objarray[1]));
	else
		return NULL;
}

template <typename T>
T Hack::DictionaryGet(void* dict, void* value)
{
	auto method = System::Type::GetType(dict)->GetMethod("TryGetValue");

	auto arraylist = System::Collections::ArrayList::ctor();
	arraylist->Add((Object*)value);
	arraylist->Add(nullptr);

	auto array_ = arraylist->ToArray();

	method->Invoke(dict, array_);

	List<IL2CPP::String*> objarray((IL2CPP::Array*)array_);

	if (objarray[1] != nullptr)
		return (T)objarray[1];
	else
		return NULL;
}

#endif