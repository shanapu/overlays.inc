#if defined _overlays_included_
	#endinput
#endif
#define _overlays_included_


//Easy precache & prepare download for decals
stock void PrecacheDecalAnyDownload(char[] sDecal)
{
	char sBuffer[256];
	Format(sBuffer, sizeof(sBuffer), "%s.vmt", sDecal);
	PrecacheDecal(sBuffer, true);
	Format(sBuffer, sizeof(sBuffer), "materials/%s.vmt", sDecal);
	AddFileToDownloadsTable(sBuffer);
	
	Format(sBuffer, sizeof(sBuffer), "%s.vtf", sDecal);
	PrecacheDecal(sBuffer, true);
	Format(sBuffer, sizeof(sBuffer), "materials/%s.vtf", sDecal);
	AddFileToDownloadsTable(sBuffer);
}


//Easy show overlay to a client with lifetime | 0.0 = no auto remove
stock void ShowOverlay(int client, char [] path, float lifetime)
{
	if (IsClientInGame(client) && !IsFakeClient(client) && !IsClientSourceTV(client) && !IsClientReplay(client))
	{
		int iFlag = GetCommandFlags( "r_screenoverlay" ) & ( ~FCVAR_CHEAT ); 
		SetCommandFlags( "r_screenoverlay", iFlag ); 
		ClientCommand( client, "r_screenoverlay \"%s.vtf\"", path);
		if (lifetime != 0.0) CreateTimer(lifetime, DeleteOverlay, client);
	}
}


//Easy show overlay to all clients with lifetime | 0.0 = no auto remove
stock void ShowOverlayAll(char [] path, float lifetime)
{
	for (int i = 1; i <= MaxClients; i++)
	{
		if (IsClientInGame(i) && !IsFakeClient(i) && !IsClientSourceTV(i) && !IsClientReplay(i))
		{
			int iFlag = GetCommandFlags( "r_screenoverlay" ) & ( ~FCVAR_CHEAT); 
			SetCommandFlags( "r_screenoverlay", iFlag ); 
			ClientCommand(i, "r_screenoverlay \"%s.vtf\"", path);
			if (lifetime != 0.0) CreateTimer(lifetime, DeleteOverlay, i);
		}
	}
}


//Remove overlay from a client
stock Action DeleteOverlay(Handle timer, any client)
{
	if (IsClientInGame(client) && !IsFakeClient(client) && !IsClientSourceTV(client) && !IsClientReplay(client))
	{
		int iFlag = GetCommandFlags( "r_screenoverlay" ) & ( ~FCVAR_CHEAT ); 
		SetCommandFlags( "r_screenoverlay", iFlag ); 
		ClientCommand( client, "r_screenoverlay \"\"" );
	}
}