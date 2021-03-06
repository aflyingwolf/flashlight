/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "flashlight/app/asr/criterion/CriterionUtils.h"
#include "flashlight/app/asr/criterion/Defines.h"
#include "flashlight/app/asr/criterion/SequenceCriterion.h"


namespace fl {
namespace app {
namespace asr {

class ConnectionistTemporalClassificationCriterion : public SequenceCriterion {
 public:
  ConnectionistTemporalClassificationCriterion(
      fl::lib::seq::CriterionScaleMode scalemode = fl::lib::seq::CriterionScaleMode::NONE);

  std::vector<fl::Variable> forward(
      const std::vector<fl::Variable>& inputs) override;

  af::array viterbiPath(const af::array& input) override;
  af::array viterbiPath(const af::array& input, const af::array& target)
      override;

  std::string prettyString() const override;

 private:
  fl::lib::seq::CriterionScaleMode scaleMode_;

  FL_SAVE_LOAD_WITH_BASE(SequenceCriterion, scaleMode_)

  void validate(const fl::Variable& input, const fl::Variable& target);
};

typedef ConnectionistTemporalClassificationCriterion CTCLoss;
} // namespace asr
} // namespace app
} // namespace fl

CEREAL_REGISTER_TYPE(
    fl::app::asr::ConnectionistTemporalClassificationCriterion)
