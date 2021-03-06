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

#ifndef INCLUDE_NENE_EXCEPTIONS_WINDOWS_WINDOWSAPIEXCEPTION_HPP
#define INCLUDE_NENE_EXCEPTIONS_WINDOWS_WINDOWSAPIEXCEPTION_HPP

#include "../../Platform.hpp"
#if defined(NENE_OS_WINDOWS)

#include <string_view>
#include <fmt/ostream.h>
#include "../EngineException.hpp"
#include "SystemErrorMessage.hpp"

namespace Nene::Windows
{
	/**
	 * @brief      Exception for signaling Windows API errors.
	 */
	class WindowsApiException
		: public EngineException
	{
	public:
		/**
		 * @brief      Constructor.
		 *
		 * @param[in]  message    Error message.
		 * @param[in]  errorCode  Error code.
		 */
		explicit WindowsApiException(DWORD errorCode, std::string_view message)
			: EngineException(fmt::format(u8"{0}\nError code: {1:08X}\nDescription: {2}", message, errorCode, getSystemErrorMessage(errorCode))) {}

		/**
		 * @brief      Destructor.
		 */
		virtual ~WindowsApiException() =default;
	};
}

#endif

#endif  // #ifndef INCLUDE_NENE_EXCEPTIONS_WINDOWS_WINDOWSAPIEXCEPTION_HPP
