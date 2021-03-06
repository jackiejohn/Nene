//=============================================================================
// Copyright (c) 2017 Ryooooooga
// https://github.com/Ryooooooga
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom
// the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//=============================================================================

#ifndef INCLUDE_NENE_GEOMETRY_RECTANGLE_HPP
#define INCLUDE_NENE_GEOMETRY_RECTANGLE_HPP

#include "../Vector2D.hpp"
#include "../Size2D.hpp"

namespace Nene
{
	/**
	 * @brief      Rectangle geometry.
	 *
	 * @tparam     T     Element type.
	 */
	template <typename T>
	class Rectangle
	{
	public:
		using value_type  = T;
		using vector_type = Vector2D<T>;
		using size_type   = Size2D<T>;

		vector_type position;
		size_type   size;

		/**
		 * @brief      Default constructor.
		 */
		constexpr Rectangle() noexcept =default;

		/**
		 * @brief      Copy constructor.
		 */
		constexpr Rectangle(const Rectangle&) noexcept =default;

		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  left     Left location.
		 * @param[in]  top      Top location.
		 * @param[in]  right    Right location.
		 * @param[in]  botttom  Bottom location.
		 */
		constexpr Rectangle(T left, T top, T right, T bottom) noexcept
			: position(left, top), size(right - left, bottom - top) {}

		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  position  Top left location.
		 * @param[in]  size      Rectangle size.
		 */
		constexpr Rectangle(const vector_type& position, const size_type& size) noexcept
			: position(position), size(size) {}

		/**
		 * @brief      Destructor.
		 */
		~Rectangle() =default;

		/**
		 * @brief      Returns left location.
		 *
		 * @return     Left location of the rectangle.
		 */
		[[nodiscard]]
		constexpr T left() const noexcept
		{
			return position.x;
		}

		/**
		 * @brief      Returns top location.
		 *
		 * @return     Top location of the rectangle.
		 */
		[[nodiscard]]
		constexpr T top() const noexcept
		{
			return position.y;
		}

		/**
		 * @brief      Returns right location.
		 *
		 * @return     Right location of the rectangle.
		 */
		[[nodiscard]]
		constexpr T right() const noexcept
		{
			return position.x + size.width;
		}

		/**
		 * @brief      Returns bottom location.
		 *
		 * @return     Bottom location of the rectangle.
		 */
		[[nodiscard]]
		constexpr T bottom() const noexcept
		{
			return position.y + size.height;
		}

		/**
		 * @brief      Returns the width.
		 *
		 * @return     The width.
		 */
		[[nodiscard]]
		constexpr T width() const noexcept
		{
			return size.width;
		}

		/**
		 * @brief      Returns the height.
		 *
		 * @return     The height.
		 */
		[[nodiscard]]
		constexpr T height() const noexcept
		{
			return size.height;
		}

		/**
		 * @brief      Returns the top left location.
		 *
		 * @return     The top left location.
		 */
		[[nodiscard]]
		constexpr vector_type topLeft() const noexcept
		{
			return { left(), top() };
		}

		/**
		 * @brief      Returns the top right location.
		 *
		 * @return     The top right location.
		 */
		[[nodiscard]]
		constexpr vector_type topRight() const noexcept
		{
			return { right(), top() };
		}

		/**
		 * @brief      Returns the bottom left location.
		 *
		 * @return     The bottom left location.
		 */
		[[nodiscard]]
		constexpr vector_type bottomLeft() const noexcept
		{
			return { left(), bottom() };
		}

		/**
		 * @brief      Returns the bottom right location.
		 *
		 * @return     The bottom right location.
		 */
		[[nodiscard]]
		constexpr vector_type bottomRight() const noexcept
		{
			return { right(), bottom() };
		}

		/**
		 * @brief      Returns center location.
		 *
		 * @return     Center location of the rectangle.
		 */
		[[nodiscard]]
		constexpr vector_type center() const noexcept
		{
			return { position.x + size.width / 2, position.y + size.height / 2 };
		}

		/**
		 * @brief      Computes area of the rectangle.
		 *
		 * @return     Area of the rectangle.
		 */
		[[nodiscard]]
		constexpr T area() const noexcept
		{
			return size.area();
		}

		/**
		 * @brief      Copy operator `=`.
		 *
		 * @param[in]  a     Right hand side operand.
		 *
		 * @return     `*this = a`.
		 */
		constexpr Rectangle& operator=(const Rectangle& a) noexcept =default;
	};

	/**
	 * @brief      Binary operator `==`.
	 *
	 * @param[in]  a     Left hand side operand.
	 * @param[in]  b     Right hand side operand.
	 *
	 * @return     `a == b`.
	 */
	template <typename T>
	[[nodiscard]]
	constexpr bool operator==(const Rectangle<T>& a, const Rectangle<T>& b) noexcept
	{
		return a.position == b.position && a.size == b.size;
	}

	/**
	 * @brief      Binary operator `!=`.
	 *
	 * @param[in]  a     Left hand side operand.
	 * @param[in]  b     Right hand side operand.
	 *
	 * @return     `a != b`.
	 */
	template <typename T>
	[[nodiscard]]
	constexpr bool operator!=(const Rectangle<T>& a, const Rectangle<T>& b) noexcept
	{
		return !(a == b);
	}

	using Rectanglei = Rectangle<Int32>;
	using Rectanglef = Rectangle<Float32>;
	using Rectangled = Rectangle<Float64>;
}

#endif  // #ifndef INCLUDE_NENE_GEOMETRY_RECTANGLE_HPP
