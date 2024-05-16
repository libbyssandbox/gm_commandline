#include <GarrysMod/Lua/Interface.h>

#include <tier0/icommandline.h>

LUA_FUNCTION(HasParm)
{
	const char* psz = LUA->CheckString(1);

	LUA->PushBool(CommandLine()->HasParm(psz));

	return 1;
}

LUA_FUNCTION(GetParmString)
{
	const char* psz = LUA->CheckString(1);
	const char* szDefault = LUA->CheckString(2);

	LUA->PushString(CommandLine()->ParmValue(psz, szDefault));

	return 1;
}

LUA_FUNCTION(GetParmNumber)
{
	const char* psz = LUA->CheckString(1);
	float flDefault = LUA->CheckNumber(2);

	LUA->PushNumber(CommandLine()->ParmValue(psz, flDefault));

	return 1;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	{
		LUA->PushString("commandline");
		LUA->CreateTable();
		{
			LUA->PushString("HasParm");
			LUA->PushCFunction(HasParm);
			LUA->RawSet(-3);

			LUA->PushString("GetParmString");
			LUA->PushCFunction(GetParmString);
			LUA->RawSet(-3);

			LUA->PushString("GetParmNumber");
			LUA->PushCFunction(GetParmNumber);
			LUA->RawSet(-3);
		}
		LUA->RawSet(-3);
	}
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	{
		LUA->PushString("commandline");
		LUA->PushNil();
		LUA->RawSet(-3);
	}
	LUA->Pop();

	return 0;
}