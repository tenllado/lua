if(CONFIG_LUA)
	zephyr_library_named(liblua)
	zephyr_include_directories(../ .)

	set(liblua_sources
		../lapi.c
		../lauxlib.c
		../lbaselib.c
		../lcode.c
		../lcorolib.c
		../lctype.c
		../ldblib.c
		../ldebug.c
		../ldo.c
		../ldump.c
		../lfunc.c
		../lgc.c
		../linit.c
		../liolib.c
		../llex.c
		../lmathlib.c
		../lmem.c
		../loadlib.c
		../lobject.c
		../lopcodes.c
		../loslib.c
		../lparser.c
		../lstate.c
		../lstring.c
		../lstrlib.c
		../ltable.c
		../ltablib.c
		../ltm.c
		../lundump.c
		../lutf8lib.c
		../lvm.c
		../lzio.c
		# this file should eventually be removed when these stubs are
		# implemented in the libc
		missing_stubs.c
	)

	if (CONFIG_LUA_GLOCK)
		target_compile_definitions(liblua PRIVATE LUA_USER_H="luauser.h")
		set(liblua_sources ${liblua_sources} luauser.c)
	endif()

	zephyr_library_sources(${liblua_sources})
	zephyr_library_link_libraries(zephyr)
endif()
