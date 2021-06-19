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

#include "general_comp_classes.hpp"

namespace dungwich_sandeon
{

namespace game_engine
{

namespace comp
{

std::string Drawable::kind_str() const
{
	return "Drawable";
}

std::string Position::kind_str() const
{
	return "Position";
}

std::string Weight::kind_str() const
{
	return "Weight";
}

std::string BaseStats::kind_str() const
{
	return "BaseStats";
}

} // namespace comp

} // namespace game_engine

} // namespace dungwich_sandeon
