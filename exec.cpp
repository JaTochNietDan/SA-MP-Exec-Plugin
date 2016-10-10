//----------------------------------------------------------
//
//   SA:MP Multiplayer Modification For GTA:SA
//   Copyright 2004-2007 SA:MP Team
//
//----------------------------------------------------------
#if defined(_WIN32)
	#include "../SDK/amxplugin.cpp"
#else
	#include "../SDK/amx/amx.h"
	#include "../SDK/plugincommon.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

//----------------------------------------------------------

typedef void (*logprintf_t)(char* format, ...);

logprintf_t logprintf;
void **ppPluginData;
extern void *pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load( void **ppData ) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf( "[PLUGIN]: Exec got loaded" );
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload( )
{
	logprintf( "[PLUGIN]: Exec got unloaded" );
}


static cell AMX_NATIVE_CALL n_exec( AMX* amx, cell* params )
{
	char *cmd;

	amx_StrParam(amx, params[1], cmd);

	system(cmd);
	return 1;
}

AMX_NATIVE_INFO HelloWorldNatives[ ] =
{
	{ "exec",			n_exec },
	{ 0,					0 }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx ) 
{
	return amx_Register( amx, HelloWorldNatives, -1 );
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx ) 
{
	return AMX_ERR_NONE;
}
