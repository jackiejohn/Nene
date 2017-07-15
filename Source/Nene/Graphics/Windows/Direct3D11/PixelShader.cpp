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

#include "../../../Platform.hpp"
#if defined(NENE_OS_WINDOWS)

#include "PixelShader.hpp"
#include "ShaderCompiler.hpp"
#include "../../../Exceptions/Windows/DirectXException.hpp"

namespace Nene::Windows::Direct3D11
{
	namespace
	{
		const char* shaderModel(D3D_FEATURE_LEVEL featureLevel)
		{
			return featureLevel >= D3D_FEATURE_LEVEL_11_0 ? u8"ps_5_0" : u8"ps_4_0";
		}
	}

	PixelShader::PixelShader(const Microsoft::WRL::ComPtr<ID3D11Device>& device, const std::string& name, const std::string& entryPoint, ByteArrayView source)
		: device_(device)
		, shader_()
		, name_(name)
		, binary_()
	{
		assert(device);

		// Compile pixel shader.
		binary_ = Shader::compile(name, entryPoint, shaderModel(device->GetFeatureLevel()), source);

		HRESULT hr = device_->CreatePixelShader(
			binary_.data(),
			binary_.size(),
			nullptr,
			shader_.GetAddressOf());

		if (FAILED(hr))
		{
			const auto message = fmt::format(
				u8"Failed to create pixel shader.\n"
				u8"Name: {}\n"
				u8"Entry point: {}\n",
				name,
				entryPoint);

			throw DirectXException { hr, message };
		}
	}

	ByteArrayView PixelShader::compiledBinary() const noexcept
	{
		return binary_;
	}

	const Microsoft::WRL::ComPtr<ID3D11PixelShader>& PixelShader::shader() const noexcept
	{
		return shader_;
	}
}

#endif
