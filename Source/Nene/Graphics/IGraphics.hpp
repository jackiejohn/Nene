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

#ifndef INCLUDE_NENE_GRAPHICS_IGRAPHICS_HPP
#define INCLUDE_NENE_GRAPHICS_IGRAPHICS_HPP

#include <memory>
#include "../Size2D.hpp"
#include "../Vertex2D.hpp"

namespace Nene
{
	// Forward declarations.
	class Image;
	class IScreen;
	class ITexture;
	class IWindow;

	template <typename Index>
	class IIndexBuffer;
	template <typename Vertex>
	class IVertexBuffer;

	/**
	 * @brief      Graphics interface.
	 */
	class IGraphics
	{
	public:
		/**
		 * @brief      Constructor.
		 */
		IGraphics() noexcept =default;

		/**
		 * @brief      Destructor.
		 */
		virtual ~IGraphics() =default;

		/**
		 * @brief      Creates the screen instance.
		 *
		 * @param[in]  window  The render target window.
		 *
		 * @return     The screen instance.
		 */
		[[nodiscard]]
		virtual std::shared_ptr<IScreen> screen(const std::shared_ptr<IWindow>& window) =0;

		/**
		 * @brief      Creates the screen instance.
		 *
		 * @param[in]  window  The render target window.
		 * @param[in]  size    The size of the screen.
		 *
		 * @return     The screen instance.
		 */
		[[nodiscard]]
		virtual std::shared_ptr<IScreen> screen(const std::shared_ptr<IWindow>& window, const Size2Di& size) =0;

		/**
		 * @brief      Creates the 2D vertex buffer instance.
		 *
		 * @param[in]  capacity  Capacity of the vertex buffer.
		 *
		 * @return     The vertex buffer instance.
		 */
		[[nodiscard]]
		virtual std::shared_ptr<IVertexBuffer<Vertex2D>> vertexBuffer2D(UInt32 capacity) =0;

		/**
		 * @brief      Creates the index buffer instance.
		 *
		 * @param[in]  capacity  Capacity of the index buffer.
		 *
		 * @return     The index buffer instance.
		 */
		[[nodiscard]]
		virtual std::shared_ptr<IIndexBuffer<UInt32>> indexBuffer(UInt32 capacity) =0;

		/**
		 * @brief      Creates the texture from images.
		 *
		 * @param[in]  image  The source image.
		 *
		 * @return     The texture instance.
		 */
		[[nodiscard]]
		virtual std::shared_ptr<ITexture> texture(const Image& image) =0;
	};
}

#endif  // #ifndef INCLUDE_NENE_GRAPHICS_IGRAPHICS_HPP
