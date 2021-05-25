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

#include "real_main_class.hpp"

namespace dungwich_sandeon
{

const Vec2<int> RealMain::SCREEN_SIZE_2D(Vec2<int>(640, 480)),
	RealMain::TILE_SIZE_2D(Vec2<int>(8, 8));
const std::map<RealMain::FontColor, std::string> RealMain::COLOR_TO_STR_MAP
= {
	{RealMain::FontColor::White, "White"},
	{RealMain::FontColor::Red, "Red"},
	{RealMain::FontColor::Green, "Green"},
	{RealMain::FontColor::Brown, "Brown"},
	{RealMain::FontColor::Yellow, "Yellow"},
	{RealMain::FontColor::Blue, "Blue"},
	{RealMain::FontColor::Purple, "Purple"},
	{RealMain::FontColor::Cyan, "Cyan"},
	{RealMain::FontColor::Gray, "Gray"},
	{RealMain::FontColor::Lim, "Lim"},
};
int RealMain::run()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't initialize SDL: %s", SDL_GetError());
		return 1;
	}
	sdl::QuitUponDtor quit_upon_dtor;

	sdl::prevent_dpi_scaling_issues();

	if (SDL_CreateWindowAndRenderer(SCREEN_SIZE_2D.x, SCREEN_SIZE_2D.y,
		SDL_WINDOW_RESIZABLE, &_window.self(), &_renderer.self()))
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't create window and renderer: %s", SDL_GetError());
		return 1;
	}

	{
		_font_surface.self() = SDL_LoadBMP("gfx/font.bmp");
		if (!_font_surface.self())
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"Couldn't create window and renderer: %s", SDL_GetError());
			return 1;
		}

		for (auto font_color=FontColor::White;
			font_color!=FontColor::Lim;
			font_color=font_color_add(font_color, 1u))
		{
			_font_texture_map[font_color]
				= sdl::Texture(SDL_CreateTextureFromSurface(_renderer,
					_font_surface));
		}
	}

	//--------
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Red],
		0xcc, 0x00, 0x00) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font red: %s", SDL_GetError());
	}
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Green],
		0x00, 0xcc, 0x00) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font green: %s", SDL_GetError());
	}
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Brown],
		0xaa, 0x55, 0x00) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font brown: %s", SDL_GetError());
	}
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Yellow],
		0xcc, 0xcc, 0x00) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font yellow: %s", SDL_GetError());
	}
	//--------
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Blue],
		0x00, 0x00, 0xcc) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font blue: %s", SDL_GetError());
	}
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Purple],
		0xcc, 0x00, 0xcc) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font purple: %s", SDL_GetError());
	}
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Cyan],
		0x00, 0xcc, 0xcc) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font cyan: %s", SDL_GetError());
	}
	if (SDL_SetTextureColorMod(_font_texture_map[FontColor::Gray],
		0xaa, 0xaa, 0xaa) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't font_color the font gray: %s", SDL_GetError());
	}
	//--------

	return 0;
}
void RealMain::_draw_char(int c, FontColor color,
	const Vec2<int>& draw_pos)
{
	const auto draw_char_font_surface_size_2d
		= _get_draw_char_font_surface_size_2d();
	const Vec2<int> c_tilemap_pos(c % draw_char_font_surface_size_2d.x,
		c / draw_char_font_surface_size_2d.x);
	const Vec2<int> c_real_pos(c_tilemap_pos.x * TILE_SIZE_2D.x,
		c_tilemap_pos.y * TILE_SIZE_2D.y);

	//const SDL_Rect 
	//SDL_RenderCopy(_renderer, )
}

} // namespace dungwich_sandeon