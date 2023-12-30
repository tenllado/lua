#include "lua.h"
#include "luauser.h"
#include <pthread.h>

#define _UNUSED(...) (void)(__VA_ARGS__)

#ifdef CONFIG_POSIX_API

static struct {
	pthread_mutex_t m;
	int init;
} glock;

void luauser_stateopen(lua_State *L)
{
	_UNUSED(L);
	if (!glock.init) {
		pthread_mutex_init(&glock.m, NULL);
		glock.init = 1;
	}
}

void luauser_stateclose(lua_State *L)
{
	_UNUSED(L);
	if (glock.init) {
		pthread_mutex_destroy(&glock.m);
		glock.init = 0;
	}
}

void luauser_lock(lua_State *L)
{
	_UNUSED(L);
	pthread_mutex_lock(&glock.m);
}

void luauser_unlock(lua_State *L)
{
	_UNUSED(L);
	pthread_mutex_unlock(&glock.m);
}

#else

static struct {
	struct k_mutex m;
	int init;
} glock;

void luauser_stateopen(lua_State *L)
{
	_UNUSED(L);
	if (!glock.init) {
		k_mutex_init(&glock.m);
		glock.init = 1;
	}
}

void luauser_stateclose(lua_State *L)
{
	_UNUSED(L);
	if (glock.init) {
		glock.init = 0;
	}
}

void luauser_lock(lua_State *L)
{
	_UNUSED(L);
	k_mutex_lock(&glock.m, K_FOREVER);
}

void luauser_unlock(lua_State *L)
{
	_UNUSED(L);
	k_mutex_unlock(&glock.m);
}
#endif

