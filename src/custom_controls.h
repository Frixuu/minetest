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

#include "server.h"
#include <string>
#include <unordered_map>
#include <vector>

struct CustomControlDefinition
{
	std::string name;
	std::string title;
	std::string category;
	std::string description;

	std::string default_bind_kbm;
	std::string default_bind_controller;
};

class ServerCustomControlManager
{
public:
	bool isBaked();
	bool tryRegister(CustomControlDefinition definition);

private:
	friend class Server;
	std::unordered_map<std::string, CustomControlDefinition> m_definitions_unbaked;
	std::vector<CustomControlDefinition> m_definitions;
	bool m_baked = false;
	void bakeDefinitions();
};
