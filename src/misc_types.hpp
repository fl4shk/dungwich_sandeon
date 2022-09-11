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

#ifndef src_misc_types_hpp
#define src_misc_types_hpp

// src/misc_types.hpp

#include "misc_includes.hpp"
#include "misc_funcs.hpp"

namespace dunwich_sandgeon
{

using IntVec2 = math::Vec2<int>;
using IntVec3 = math::Vec3<int>;
////using PosVec2 = binser::Vec2Ex<int>;
////using PosVec3 = binser::Vec3Ex<int>;
using IntVec2Ex = binser::Vec2Ex<int>;
using IntVec3Ex = binser::Vec3Ex<int>;

using IntHit2 = math::Hit2<int>;
using IntSweep2 = math::Sweep2<int>;
using IntLineSeg2 = math::LineSeg2<int>;
using IntRect2 = math::Rect2<int>;

//using SizeVec2 = math::Vec2<u32>;
////using SizeVec2 = binser::Vec2Ex<u32>;
//using SizeVec2Ex = binser::Vec2Ex<u32>;
//
//using DblVec2 = math::Vec2<double>;
//using DblVec2Ex = binser::Vec2Ex<double>;
using DblVec2 = math::Vec2<double>;
using DblVec3 = math::Vec3<double>;

using DblVec2Ex = binser::Vec2Ex<double>;
using DblVec3Ex = binser::Vec3Ex<double>;

using DblHit2 = math::Hit2<double>;
using DblSweep2 = math::Sweep2<double>;
using DblLineSeg2 = math::LineSeg2<double>;
using DblRect2 = math::Rect2<double>;


//template<typename FirstT, typename OtherT>
//inline void set_vec2(Vec2<FirstT>& self, const Vec2<OtherT>& other)
//{
//	self.x = other.x;
//	self.y = other.y;
//}

} // namespace dunwich_sandgeon

#endif		// src_misc_types_hpp
