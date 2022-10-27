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

#ifndef src_game_engine_dijkstra_map_gen_class_hpp
#define src_game_engine_dijkstra_map_gen_class_hpp

// src/game_engine/dijkstra_map_gen_class.hpp

#include "../../misc_includes.hpp"
#include "../../misc_types.hpp"
#include "../global_shape_constants_etc.hpp"
#include "bfs_funcs.hpp"
#include "bg_tile_enum.hpp"
//#include "path_class.hpp"
//#include "floor_layout_class.hpp"

namespace dunwich_sandgeon {
namespace game_engine {
namespace level_gen_etc {
//--------
class Path;
class FloorLayout;
//--------
//class DijkstraPathFind final {
//public:		// types
//	using AtFunc = std::function<float(
//		const IntVec2Uset&, // explored_uset
//		const IntVec2& // pos
//	)>;
//public:		// constant
//	static constexpr float
//		VERY_HIGH_NUM = INFINITY;
//public:		// functions
//	DijkstraPathFind();
//	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DijkstraPathFind);
//	~DijkstraPathFind();
//};
//--------
// See the below links for more information:
// http://www.roguebasin.com/index.php/The_Incredible_Power_of_Dijkstra_Maps
// http://www.roguebasin.com/index.php/Dijkstra_Maps_Visualized
class DijkstraMapGen;
class DijkstraMap final {
	friend class DijkstraMapGen;
public:		// types
	using Data = std::vector<std::vector<float>>;
public:		// constants
	static constexpr IntRect2
		// Note: might need to change `BOUNDS_R2` to a non-constant at some
		// point
		BOUNDS_R2 = PFIELD_PHYS_NO_BRDR_RECT2;
	static constexpr IntVec2
		SIZE_2D = BOUNDS_R2.size_2d;
	//static constexpr IntVec2 SIZE_2D = PFIELD_PHYS_NO_BRDR_RECT2.size_2d;
	static constexpr float
		//DEFAULT_FLIP_SCALE = 1.2f;
		DEFAULT_FLIP_BONUS = -0.2f,
		VERY_HIGH_NUM
			//= PFIELD_PHYS_SIZE_2D.x + PFIELD_PHYS_SIZE_2D.y + 50.0f;
			= INFINITY;
private:		// variables
	Data _data;
public:		// functions
	DijkstraMap();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DijkstraMap);
	~DijkstraMap();
	DijkstraMap& flip(float bonus=DEFAULT_FLIP_BONUS);
	// Make a `Path` to the first `Goal` we can find.
	// This is potentially useful when we only have one `Goal`.
	// It's best not to call this function on 
	std::optional<Path> make_path(
		const IntVec2& start_phys_pos, float stop_when_le_val=0.0f
	) const;
	//DijkstraMap(IntVec2 s_size_2d);
	//inline size_t size() const {
	//	return data().size();
	//}
	constexpr inline IntVec2 size_2d() const {
		//return IntVec2(data().front().size(), data().size());
		return SIZE_2D;
	}
private:		// functions
	constexpr inline float& _raw_at(const IntVec2& pos) {
		return _data.at(pos.y).at(pos.x);
	}
	constexpr inline float& _raw_phys_at(const IntVec2& phys_pos) {
		return _raw_at(phys_pos - BOUNDS_R2.tl_corner());
	}
public:		// functions
	constexpr inline const float& at(const IntVec2& pos) const {
		return _data.at(pos.y).at(pos.x);
	}
	constexpr inline const float& phys_at(const IntVec2& phys_pos) const {
		return at(phys_pos - BOUNDS_R2.tl_corner());
	}
	//static std::ostream& osprint_dmap(std::ostream& os, const Dmap& dmap);
};
std::ostream& operator << (std::ostream& os, const DijkstraMap& self);
class DijkstraMapGen final {
public:		// types
	//using Goal = std::pair<IntVec2, float>;
	//using DmapV2d = std::vector<std::vector<float>>;
	//using Dmap
	//	//= std::vector<std::vector<float>>;
	//	= DijkstraMap;
	//using Path = std::vector<IntVec2>;

	class Goal final {
	public:		// variables
		IntVec2 pos;
		float val;
	};
public:		// constants
	//static const BgTileUset
	//	DEFAULT_NO_PASS_USET;
private:		// variables
	//std::unordered_map<IntVec2, Goal> _goal_umap;
	std::vector<Goal> _goal_vec;
	std::unordered_map<IntVec2, size_t> _goal_pos_to_index_umap;
public:		// functions
	DijkstraMapGen();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DijkstraMapGen);
	~DijkstraMapGen();

	// add a goal
	DijkstraMapGen& add(const IntVec2& pos, float val=0.0f);

	DijkstraMap gen_basic(
		const FloorLayout& floor_layout,
		const BgTileUset& no_pass_uset=BgTileUset()
	) const;
	DijkstraMap gen_flipped(
		const FloorLayout& floor_layout,
		const BgTileUset& no_pass_uset=BgTileUset(),
		float bonus=DijkstraMap::DEFAULT_FLIP_BONUS
	) const;

	//static DijkstraMap& flip(
	//	DijkstraMap& dmap, float bonus=DEFAULT_FLIP_BONUS
	//);
	//Path make_path(
	//	const DijkstraMap& dmap, //const FloorLayout& floor_layout,
	//	const IntVec2& start_phys_pos
	//) const;

	//GEN_GETTER_BY_CON_REF(goal_umap);
	GEN_GETTER_BY_CON_REF(goal_vec);
	GEN_GETTER_BY_CON_REF(goal_pos_to_index_umap);
};
//--------
} // namespace level_gen_etc
} // namespace game_engine
} // namespace dunwich_sandgeon

#endif		// src_game_engine_dijkstra_map_gen_class_hpp
