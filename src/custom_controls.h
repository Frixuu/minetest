/*
Minetest
Copyright (C) 2022 Frixuu <kontakt@lukasz.xyz>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once

#include "client/client.h"
#include "client/keycode.h"
#include "script/lua_api/l_object.h"
#include "client/game.h"
#include "script/lua_api/l_mainmenu.h"
#include "server.h"
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class Game;
class KeyPress;

struct CustomControlDefinition
{
	std::string name;
	std::string title;
	std::string category;
	std::string description;

	std::string default_bind_kbm;
	std::string default_bind_controller;
};

class ServerCustomControlManager final
{
public:
	bool isBaked();
	bool tryRegister(CustomControlDefinition definition);

private:
	friend class Server;
	friend class ObjectRef;
	std::unordered_map<std::string, CustomControlDefinition> m_definitions_unbaked;
	std::vector<CustomControlDefinition> m_definitions;
	bool m_baked = false;
	void bakeDefinitions();
};

class ClientCustomControlManager final
{
private:
	friend class Client;
	friend class Game;
	friend class ModApiMainMenu;
	std::vector<CustomControlDefinition> m_definitions_by_index;
	std::map<irr::EKEY_CODE, size_t> m_indices_by_event;
	void clear(size_t hint);
	void pushDefinition(CustomControlDefinition definition);
};
