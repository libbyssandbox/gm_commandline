#include <GarrysMod/Lua/Interface.h>

#include <tier0/icommandline.h>

LUA_FUNCTION(HasParm)
{
	const char* psz = LUA->CheckString(1);

	LUA->PushBool(CommandLine()->CheckParm(psz));

	return 1;
}

LUA_FUNCTION(GetParm)
{
	const char* psz = LUA->CheckString(1);

	if (!CommandLine()->HasParm(psz))
	{
		LUA->PushNil();
		return 1;
	}

	int index = CommandLine()->FindParm(psz);
	LUA->PushString(CommandLine()->GetParm(index));

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

			LUA->PushString("GetParm");
			LUA->PushCFunction(GetParm);
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