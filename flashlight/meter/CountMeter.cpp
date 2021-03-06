/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <algorithm>
#include <stdexcept>

#include "flashlight/flashlight/meter/CountMeter.h"

namespace fl {

CountMeter::CountMeter(int num) : counts_(num, 0) {}

void CountMeter::add(int id, int64_t val) {
  if (!(id >= 0 && id < counts_.size())) {
    throw std::out_of_range("invalid id to update count for");
  }
  counts_[id] += val;
}

std::vector<int64_t> CountMeter::value() {
  return counts_;
}

void CountMeter::reset() {
  std::fill(counts_.begin(), counts_.end(), 0);
}

} // namespace fl
