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

#ifndef INCLUDE_NENE_KEYBOARD_WINDOWS_DIRECTINPUT_KEYBOARDINPUT_HPP
#define INCLUDE_NENE_KEYBOARD_WINDOWS_DIRECTINPUT_KEYBOARDINPUT_HPP

#include "../../../Platform.hpp"
#if defined(NENE_OS_WINDOWS)

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <wrl/client.h>
#include "../../../Uncopyable.hpp"
#include "../../IKeyboardInput.hpp"

namespace Nene::Windows::DirectInput
{
	// Forward declarations.
	class Keyboard;

	/**
	 * @brief      DirectInput keyboard input implementation.
	 */
	class KeyboardInput final
		: public  IKeyboardInput
		, private Uncopyable
	{
		Microsoft::WRL::ComPtr<IDirectInput8W> input_;

	public:
		/**
		 * @brief      Constructor.
		 */
		explicit KeyboardInput();

		/**
		 * @brief      Destructor.
		 */
		~KeyboardInput() =default;

		/**
		 * @see        `Nene::IJoypadInput::keyboard()`.
		 */
		[[nodiscard]]
		std::unique_ptr<IKeyboard> keyboard() override;
	};
}

#endif

#endif  // #ifndef INCLUDE_NENE_KEYBOARD_WINDOWS_DIRECTINPUT_KEYBOARDINPUT_HPP
