// This file is part of Dunwich Sandgeon.
// 
// Copyright 2022 FL4SHK
//
// Dunwich Sandgeon is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the
// Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
// 
// Dunwich Sandgeon is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along
// with Dunwich Sandgeon.  If not, see <https://www.gnu.org/licenses/>.

#ifndef src_game_engine_global_shape_constants_hpp
#define src_game_engine_global_shape_constants_hpp

// src/game_engine/global_shape_constants.hpp

#include "../misc_includes.hpp"
#include "../misc_types.hpp"
#include "misc_constants.hpp"

namespace dunwich_sandgeon
{
namespace game_engine
{
//--------
// This constant has values in the amount of tilemap entries
static constexpr IntVec2
	WITH_BORDER_SCREEN_SIZE_2D
		//{.x=82, .y=62},
		{.x=80, .y=60},
		//{.x=62, .y=42},
		//{.x=42, .y=42},
	SCREEN_SIZE_2D(WITH_BORDER_SCREEN_SIZE_2D - IntVec2{2, 2});
//static constexpr IntRect2
//	SCREEN_RECT2{.pos{0, 0}, .size_2d=SCREEN_SIZE_2D},
//	WITH_BORDER_SCREEN_RECT2
//		{.pos{0, 0}, .size_2d=WITH_BORDER_SCREEN_SIZE_2D};
//--------
static constexpr IntVec2
	PFIELD_WINDOW_POS{.x=0, .y=0},
	PFIELD_WINDOW_END_POS
		{.x=WITH_BORDER_SCREEN_SIZE_2D.x - 1 - 20,
		.y=WITH_BORDER_SCREEN_SIZE_2D.y - 1 - 10};
		//{.x=WITH_BORDER_SCREEN_SIZE_2D.x - 1 - 10,
		//.y=WITH_BORDER_SCREEN_SIZE_2D.y - 1 - 10};
static constexpr IntRect2
	PFIELD_WINDOW_RECT2=IntRect2::build_in_grid_r2_w_end_pos
		(PFIELD_WINDOW_POS, PFIELD_WINDOW_END_POS);

//extern const IntVec2Ex
//	PFIELD_WINDOW_EX_RANGE;
static constexpr IntVec2
	PFIELD_WINDOW_SIZE_2D
		//{.x=PFIELD_WINDOW_END_POS.x - PFIELD_WINDOW_POS.x + 1,
		//.y=PFIELD_WINDOW_END_POS.y - PFIELD_WINDOW_POS.y + 1};
		= PFIELD_WINDOW_RECT2.size_2d;
//--------
static constexpr IntVec2
	LOG_WINDOW_POS{.x=0, .y=PFIELD_WINDOW_END_POS.y},
	LOG_WINDOW_END_POS{.x=PFIELD_WINDOW_END_POS.x,
		.y=WITH_BORDER_SCREEN_SIZE_2D.y - 1},

	HUD_WINDOW_POS{.x=PFIELD_WINDOW_END_POS.x, .y=PFIELD_WINDOW_POS.y},
	HUD_WINDOW_END_POS
		{.x=WITH_BORDER_SCREEN_SIZE_2D.x - 1,
		.y=WITH_BORDER_SCREEN_SIZE_2D.y - 1},

	POPUP_WINDOW_POS{.x=13, .y=10},
	POPUP_WINDOW_END_POS
		{.x=HUD_WINDOW_POS.x - 1, .y=WITH_BORDER_SCREEN_SIZE_2D.y - 15},

	YES_NO_WINDOW_POS{.x=2, .y=WITH_BORDER_SCREEN_SIZE_2D.y / 2},
	YES_NO_WINDOW_END_POS
		{.x=YES_NO_WINDOW_POS.x + 3
			+ MSG_LOG_WIDGET_SELECTED_SPACING_SIZE
			+ MSG_LOG_WIDGET_SPACING_SIZE
			+ 1,
		.y=YES_NO_WINDOW_POS.y + 2 + 1 + 2},

	TEXT_YES_NO_WINDOW_POS{.x=2, .y=WITH_BORDER_SCREEN_SIZE_2D.y / 2},
	TEXT_YES_NO_WINDOW_END_POS
		{.x=TEXT_YES_NO_WINDOW_POS.x + 30 + 1 + 2,
		.y=TEXT_YES_NO_WINDOW_POS.y + 4 + 1 + 2};
//--------
} // namespace game_engine
} // namespace dunwich_sandgeon

#endif		// src_game_engine_global_shape_constants_hpp