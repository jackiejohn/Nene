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

#ifndef INCLUDE_NENE_GRAPHICS_WINDOWS_DIRECT3D11_DYNAMICTEXTURE_HPP
#define INCLUDE_NENE_GRAPHICS_WINDOWS_DIRECT3D11_DYNAMICTEXTURE_HPP

#include "../../../Platform.hpp"
#if defined(NENE_OS_WINDOWS)

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <memory>
#include <d3d11.h>
#include <wrl/client.h>
#include "../../IDynamicTexture.hpp"
#include "Texture.hpp"

namespace Nene::Windows::Direct3D11
{
	/**
	 * @brief      Direct3D11 dynamic texture implementation.
	 */
	class DynamicTexture final
		: public TextureBase
		, public IDynamicTexture
	{
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTarget_;

	public:
		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  texture  Direct3D11 texture.
		 */
		explicit DynamicTexture(const Microsoft::WRL::ComPtr<ID3D11Texture2D>& texture);

		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  device  Direct3D11 device.
		 * @param[in]  size    The texture size.
		 */
		explicit DynamicTexture(const Microsoft::WRL::ComPtr<ID3D11Device>& device, const Size2Di& size);

		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  device   Direct3D11 device.
		 * @param[in]  image    The source image.
		 */
		explicit DynamicTexture(const Microsoft::WRL::ComPtr<ID3D11Device>& device, const Image& image);

		/**
		 * @brief      Destructor.
		 */
		~DynamicTexture() =default;

		/**
		 * @see        `Nene::ITexture::width()`.
		 */
		[[nodiscard]]
		Int32 width() const noexcept override
		{
			return size_.width;
		}

		/**
		 * @see        `Nene::ITexture::height()`.
		 */
		[[nodiscard]]
		Int32 height() const noexcept override
		{
			return size_.height;
		}

		/**
		 * @see        `Nene::ITexture::size()`.
		 */
		[[nodiscard]]
		Size2Di size() const noexcept override
		{
			return size_;
		}

		/**
		 * @brief      Returns Direct3D11 render target view.
		 *
		 * @return     Direct3D11 render target view.
		 */
		[[nodiscard]]
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView() const noexcept
		{
			return renderTarget_;
		}
	};
}

#endif

#endif  // #ifndef INCLUDE_NENE_GRAPHICS_WINDOWS_DIRECT3D11_DYNAMICTEXTURE_HPP
