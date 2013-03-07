#ifndef __OPENSTEAMCLIENTINTERFACE_H
#define __OPENSTEAMCLIENTINTERFACE_H

#include "OpenSteamClient/SteamClient.hpp"
#include "OpenSteamClient/SteamFriends.hpp"
#include "OpenSteamClient/SteamUser.hpp"
#include <string>

class OpenSteamClientInterface
{
	public:
		OpenSteamClientInterface();
		~OpenSteamClientInterface();

		Sc::SteamClient client;
		Sc::SteamUser* user;
		Sc::SteamFriends* friends;

		void setCredentials(char* username, char* password);
		void connect();
		void tick(int ms);

	protected:
		void onConnectHandler();
		void onDisconnectHandler();

		std::string username;
		std::string password;
};

#endif
