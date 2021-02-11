// -*- mode: c++ -*-
/* Kaleidoscope - Firmware for computer input devices
 * Copyright (C) 2021  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "kaleidoscope_internal/device.h"
#include "kaleidoscope/KeyAddr.h"
#include "kaleidoscope/key_defs.h"

namespace kaleidoscope {

class Bindings {
 public:
  Bindings() {}

  static Key activeBinding(KeyAddr key_addr) {
    return active_bindings_[key_addr.toInt()];
  }
  static void updateActiveBinding(KeyAddr key_addr, Key key) {
    active_bindings_[key_addr.toInt()] = key;
  }

 private:
  static Key active_bindings_[kaleidoscope_internal::device.numKeys()];
};

} // namespace kaleidoscope

extern kaleidoscope::Bindings Bindings;
