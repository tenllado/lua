#ifndef _LUA_USER_H_
#define _LUA_USER_H_

#define lua_lock(L) luauser_lock(L)
#define lua_unlock(L) luauser_unlock(L)
#define luai_userstateopen(L) luauser_stateopen(L)
#define luai_userstateclose(L) luauser_stateclose(L)


void luauser_lock(lua_State *L);
void luauser_unlock(lua_State *L);
void luauser_stateopen(lua_State *L);
void luauser_stateclose(lua_State *L);

#endif
