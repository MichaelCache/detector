// C++ template meta-function debug tool
// Copyright (C) 2020  Michael_Cache
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Contact email <faith_gentoo@163.com>

#ifndef DETECTOR_H
#define DETECTOR_H

#include <type_traits>

template <typename T>
struct false_value : public std::false_type {};

/**
 * @brief C++ template meta-function debug tool
 *
 * @note usage:
 *       when template arg CONDITION is true, detector will help print type
 *       while compiling like "detector.h: In instantiation of ‘struct 
 *       detector<true, XXX>’:". The XXX is the real type you want to inspect.
 */
template <bool CONDITION = false, typename... T>
struct detector {
  using type = void;
};

template <typename T, typename... RT>
struct detector<true, T, RT...> {
  static_assert(false_value<T>::value, "Type Detector");
  using type = T;
};

#endif
