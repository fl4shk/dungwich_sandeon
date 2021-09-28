// This file is part of Dungwich Sandeon.
// 
// Dungwich Sandeon is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the
// Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
// 
// Dungwich Sandeon is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along
// with Dungwich Sandeon.  If not, see <https://www.gnu.org/licenses/>.

#include "gm_aux_title_screen_class.hpp"
#include "../engine_class.hpp"

namespace dungwich_sandeon
{
namespace game_engine
{
namespace sys
{

const std::string
	GmAuxTitleScreen::KIND_STR("GmAuxTitleScreen");

std::string GmAuxTitleScreen::kind_str() const
{
	return KIND_STR;
}

void GmAuxTitleScreen::init(ecs::Engine* ecs_engine)
{
	did_init = true;

	//engine->aux_menu = 
}
void GmAuxTitleScreen::tick(ecs::Engine* ecs_engine)
{
	auto engine = game_engine::engine;

	if (engine->game_mode == GameMode::AuxTitleScreen)
	{
		printout("GmAuxTitleScreen::tick(): testificate\n");

		if (!did_init)
		{
			init(ecs_engine);
		}

		auto
			& screen_window = engine->screen_window,
			& aux_window = engine->aux_window;

		auto& aux_menu = engine->aux_menu;

		aux_window.clear();
		aux_window.draw(aux_menu);

		screen_window.clear();
		screen_window.draw(aux_window);
	}
}

} // namespace sys
} // namespace game_engine
} // namespace dungwich_sandeon
