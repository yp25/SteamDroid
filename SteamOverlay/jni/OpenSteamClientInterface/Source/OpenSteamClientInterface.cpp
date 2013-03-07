#include <string.h>
#include <jni.h>

#include "log.h"

#include "OpenSteamClientInterface.h"

OpenSteamClientInterface::OpenSteamClientInterface(void)
{
	client.OnConnect->Add([&](Sc::ConnectEvent ev)
	{
		if (ev.result == Sc::EResult_OK)
		{
			Sc::LoginDetails details;
			details.username = username;
			details.password = password;

			user->LogIn(details);
		}
		else
		{
			// Couldn't connect.
			LOGD("Failed to connect to Steam");
		}
	});

	client.OnDisconnect->Add([&](Sc::DisconnectEvent ev)
	{
		//Got disconnected
		LOGD("Disconnected from Steam");
	});

	user = new Sc::SteamUser(client);
	friends = new Sc::SteamFriends(client);
}

OpenSteamClientInterface::~OpenSteamClientInterface(void)
{
	delete user;
	delete friends;
}

void OpenSteamClientInterface::setCredentials(char* username, char* password)
{
	this->username = username;
	this->password = password;
}

void OpenSteamClientInterface::connect()
{
	client.Connect();
}

void OpenSteamClientInterface::tick(int ms)
{
	client.Run(ms);
}
