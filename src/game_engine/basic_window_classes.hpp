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

#ifndef src_game_engine_basic_window_classeses_hpp
#define src_game_engine_basic_window_classeses_hpp

// src/game_engine/basic_window_classeses.hpp

#include "../misc_includes.hpp"
#include "../misc_types.hpp"
#include "../input_kind_enum.hpp"
#include "font_color_enum.hpp"
#include "ticker_base_class.hpp"
//#include "engine_class.hpp"

namespace dungwich_sandeon
{
namespace game_engine
{

class Engine;

class LayeredWindow;

// A window made out of `Entity`s
class Window
{
public:		// constants
	// This constant has values in the amount of tilemap entries
	static const SizeVec2 WITH_BORDER_SCREEN_SIZE_2D, SCREEN_SIZE_2D;

	static constexpr int
		BORDER_CORNER_CHAR = '+',
		BORDER_HORIZ_CHAR = '-',
		BORDER_VERT_CHAR = '|';
	static constexpr FgBgColorPair BORDER_COLOR = FontColor::White;
protected:		// variables
	Engine* _engine = nullptr;
	PosVec2 _pos;
	ecs::EntIdVec2d _ent_id_v2d;
public:		// functions
	Window();
	Window(Engine* s_engine, const PosVec2& s_some_pos,
		const SizeVec2& s_some_size_2d,
		bool prev_args_are_with_border=false);
	Window(Engine* s_engine, const PosVec2& s_some_pos,
		const PosVec2& s_some_end_pos,
		bool prev_args_are_with_border=false);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Window);
	virtual ~Window();

	void init_set_border();

	virtual void tick(InputKind input_kind);

	inline auto& with_border_ent_id_at(const PosVec2& index)
	{
		return _ent_id_v2d.at(index.y).at(index.x);
	}
	inline const auto& with_border_ent_id_at(const PosVec2& index) const
	{
		return _ent_id_v2d.at(index.y).at(index.x);
	}
	inline auto& with_border_ent_id_at(const SizeVec2& index)
	{
		return _ent_id_v2d.at(index.y).at(index.x);
	}
	inline const auto& with_border_ent_id_at(const SizeVec2& index) const
	{
		return _ent_id_v2d.at(index.y).at(index.x);
	}

	inline auto& ent_id_at(const PosVec2& index)
	{
		return with_border_ent_id_at(index + PosVec2(1, 1));
	}
	inline const auto& ent_id_at(const PosVec2& index) const
	{
		return with_border_ent_id_at(index + PosVec2(1, 1));
	}
	inline auto& ent_id_at(const SizeVec2& index)
	{
		return with_border_ent_id_at(index + SizeVec2(1, 1));
	}
	inline const auto& ent_id_at(const SizeVec2& index) const
	{
		return with_border_ent_id_at(index + SizeVec2(1, 1));
	}

	inline SizeVec2 with_border_size_2d() const
	{
		return SizeVec2(ent_id_v2d().at(0).size(),
			ent_id_v2d().size());
	}
	inline SizeVec2 size_2d() const
	{
		return SizeVec2(ent_id_v2d().at(1).size() - 2,
			ent_id_v2d().size() - 2);
	}
	void draw(const Window& win);
	//void draw(const LayeredWindow& layered_win);
	//void draw_text(const PosVec2& where, const std::string& what);

	GEN_GETTER_BY_CON_REF(pos);
	GEN_GETTER_BY_CON_REF(ent_id_v2d);
};

//class LayeredWindow
//{
//protected:		// variables
//	std::map<std::string, Window> _layer_map;
//	std::map<std::string, size_t> _layer_prio_map;
//public:		// functions
//	LayeredWindow();
//	LayeredWindow(const PosVec2& s_pos, const SizeVec2& s_size_2d,
//		const std::map<std::string, size_t>& s_layer_prio_map);
//	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(LayeredWindow);
//	virtual ~LayeredWindow();
//
//	virtual void tick(InputKind input_kind);
//
//	inline Window& layer_at(const std::string& key)
//	{
//		return _layer_map.at(key);
//	}
//	inline const Window& layer_at(const std::string& key) const
//	{
//		return _layer_map.at(key);
//	}
//	inline SizeVec2 size_2d() const
//	{
//		for (const auto& pair: layer_map())
//		{
//			// All layers have the same size
//			return pair.second.size_2d();
//		}
//	}
//
//	GEN_GETTER_BY_CON_REF(layer_map);
//	GEN_GETTER_BY_CON_REF(layer_prio_map);
//};

} // namespace game_engine
} // namespace dungwich_sandeon

#endif		// src_game_engine_basic_window_classeses_hpp
