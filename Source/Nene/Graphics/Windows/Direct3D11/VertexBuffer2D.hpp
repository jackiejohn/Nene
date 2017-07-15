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

#ifndef INCLUDE_NENE_GRAPHICS_WINDOWS_DIRECT3D11_VERTEXBUFFER2D_HPP
#define INCLUDE_NENE_GRAPHICS_WINDOWS_DIRECT3D11_VERTEXBUFFER2D_HPP

#include "../../../Platform.hpp"
#if defined(NENE_OS_WINDOWS)

#include "../../IVertexBuffer2D.hpp"
#include "VertexBuffer.hpp"

namespace Nene::Windows::Direct3D11
{
	/**
	 * @brief      Direct3D11 2D vertex buffer implementation.
	 */
	class VertexBuffer2D final
		: public  IVertexBuffer2D
		, private Uncopyable
	{
		VertexBuffer buffer_;

	public:
		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  device    Direct3D11 device.
		 * @param[in]  capacity  Max number of indices contains.
		 */
		explicit VertexBuffer2D(const Microsoft::WRL::ComPtr<ID3D11Device>& device, UInt32 capacity)
			:buffer_(device, sizeof(vertex_type), capacity) {}

		/**
		 * @brief      Destructor.
		 */
		~VertexBuffer2D() =default;

		/**
		 * @see        `Nene::IVertexBuffer::vertexSize()`.
		 */
		[[nodiscard]]
		UInt32 vertexSize() const noexcept override
		{
			return buffer_.vertexSize();
		}

		/**
		 * @see        `Nene::IVertexBuffer::capacity()`.
		 */
		[[nodiscard]]
		UInt32 capacity() const noexcept override
		{
			return buffer_.capacity();
		}

		/**
		 * @see        `Nene::IVertexBuffer::stride()`.
		 */
		[[nodiscard]]
		UInt32 stride() const noexcept override
		{
			return buffer_.stride();
		}

		/**
		 * @brief      Returns Direct3D11 vertex buffer.
		 *
		 * @return     Direct3D11 vertex buffer.
		 */
		[[nodiscard]]
		const Microsoft::WRL::ComPtr<ID3D11Buffer>& buffer() const noexcept
		{
			return buffer_.buffer();
		}
	};
}

#endif

#endif  // #ifndef INCLUDE_NENE_GRAPHICS_WINDOWS_DIRECT3D11_VERTEXBUFFER2D_HPP