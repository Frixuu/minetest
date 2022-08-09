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

#include "custom_controls.h"
#include "client/keycode.h"
#include <string>
#include <utility>

bool ServerCustomControlManager::isBaked()
{
	return m_baked;
}

bool ServerCustomControlManager::tryRegister(CustomControlDefinition definition)
{
	if (isBaked())
		return false;

	if (m_definitions_unbaked.size() >= 60000)
		return false;

	std::string name = definition.name;
	auto result = m_definitions_unbaked.insert(std::make_pair(name, definition));
	return result.second;
}

void ServerCustomControlManager::bakeDefinitions()
{
	size_t definition_count = m_definitions_unbaked.size();
	m_definitions.reserve(definition_count);

	for (auto &entry : m_definitions_unbaked) {
		m_definitions.push_back(entry.second);
	}

	m_definitions_unbaked.clear();
	m_baked = true;
	verbosestream << "Baked " << m_definitions.size() << " control definition(s)" << std::endl;
}

void ClientCustomControlManager::clear(size_t hint = 0)
{
	m_indices_by_event.clear();
	m_definitions_by_index.clear();
	m_definitions_by_index.reserve(hint);
}

void ClientCustomControlManager::pushDefinition(CustomControlDefinition definition)
{
	m_definitions_by_index.push_back(definition);
	if (!definition.default_bind_kbm.empty()) {
		KeyPress kp(definition.default_bind_kbm.c_str());
		if (!kp.m_name.empty()) {
			m_indices_by_event[kp] = m_definitions_by_index.size() - 1;
		}
	}
}
