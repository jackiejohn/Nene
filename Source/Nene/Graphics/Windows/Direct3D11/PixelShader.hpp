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

#ifndef INCLUDE_NENE_GRAPHICS_WINDOWS_DIERECT3D11_PIXELSHADER_HPP
#define INCLUDE_NENE_GRAPHICS_WINDOWS_DIERECT3D11_PIXELSHADER_HPP

#include "../../../Platform.hpp"
#if defined(NENE_OS_WINDOWS)

#include <d3d11.h>
#include <wrl/client.h>
#include "../../../ArrayView.hpp"
#include "../../../Uncopyable.hpp"
#include "../../IPixelShader.hpp"

namespace Nene::Windows::Direct3D11
{
	/**
	 * @brief      Pixel shader implementation.
	 */
	class PixelShader final
		: public  IPixelShader
		, private Uncopyable
	{
		Microsoft::WRL::ComPtr<ID3D11PixelShader> shader_;

	public:
		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  device          Direct3D11 device.
		 * @param[in]  compiledBinary  The compiled shader binary.
		 */
		explicit PixelShader(const Microsoft::WRL::ComPtr<ID3D11Device>& device, ByteArrayView compiledBinary);

		/**
		 * @brief      Destructor.
		 */
		~PixelShader() =default;

		/**
		 * @brief      Returns Direct3D11 pixel shader object.
		 *
		 * @return     Direct3D11 pixel shader object.
		 */
		[[nodiscard]]
		Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader() const noexcept
		{
			return shader_;
		}
	};
}

#endif

#endif  // #ifndef INCLUDE_NENE_GRAPHICS_WINDOWS_DIERECT3D11_PIXELSHADER_HPP
