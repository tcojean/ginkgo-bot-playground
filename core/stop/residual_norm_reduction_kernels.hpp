/*******************************<GINKGO LICENSE>******************************
Copyright 2017-2018

Karlsruhe Institute of Technology
Universitat Jaume I
University of Tennessee

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************<GINKGO LICENSE>*******************************/

#ifndef GKO_CORE_STOP_RESIDUAL_NORM_REDUCTION_KERNELS_HPP_
#define GKO_CORE_STOP_RESIDUAL_NORM_REDUCTION_KERNELS_HPP_


#include "core/base/array.hpp"
#include "core/base/math.hpp"
#include "core/base/types.hpp"
#include "core/matrix/dense.hpp"
#include "core/stop/stopping_status.hpp"


namespace gko {
namespace kernels {
namespace residual_norm_reduction {


#define GKO_DECLARE_RESIDUAL_NORM_REDUCTION_KERNEL(_type)                      \
    void residual_norm_reduction(                                              \
        std::shared_ptr<const DefaultExecutor> exec,                           \
        const matrix::Dense<_type> *tau, const matrix::Dense<_type> *orig_tau, \
        remove_complex<_type> rel_residual_goal, uint8 stoppingId,             \
        bool setFinalized, Array<stopping_status> *stop_status,                \
        bool *all_converged, bool *one_changed)


#define DECLARE_ALL_AS_TEMPLATES  \
    template <typename ValueType> \
    GKO_DECLARE_RESIDUAL_NORM_REDUCTION_KERNEL(ValueType)


}  // namespace residual_norm_reduction


namespace omp {
namespace residual_norm_reduction {

DECLARE_ALL_AS_TEMPLATES;

}  // namespace residual_norm_reduction
}  // namespace omp


namespace gpu {
namespace residual_norm_reduction {

DECLARE_ALL_AS_TEMPLATES;

}  // namespace residual_norm_reduction
}  // namespace gpu


namespace reference {
namespace residual_norm_reduction {

DECLARE_ALL_AS_TEMPLATES;

}  // namespace residual_norm_reduction
}  // namespace reference


#undef DECLARE_ALL_AS_TEMPLATES

}  // namespace kernels
}  // namespace gko

#endif  // GKO_CORE_STOP_RESIDUAL_NORM_REDUCTION_KERNELS_HPP_
