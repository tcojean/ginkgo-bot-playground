/*******************************<GINKGO LICENSE>******************************
Copyright (c) 2017-2020, the Ginkgo authors
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************<GINKGO LICENSE>*******************************/

#include <ginkgo/core/base/exception_helpers.hpp>


#include "core/components/absolute_array.hpp"
#include "core/components/fill_array.hpp"
#include "core/components/precision_conversion.hpp"
#include "core/components/prefix_sum.hpp"
#include "core/factorization/factorization_kernels.hpp"
#include "core/factorization/ilu_kernels.hpp"
#include "core/factorization/par_ict_kernels.hpp"
#include "core/factorization/par_ilu_kernels.hpp"
#include "core/factorization/par_ilut_kernels.hpp"
#include "core/matrix/coo_kernels.hpp"
#include "core/matrix/csr_kernels.hpp"
#include "core/matrix/dense_kernels.hpp"
#include "core/matrix/diagonal_kernels.hpp"
#include "core/matrix/ell_kernels.hpp"
#include "core/matrix/hybrid_kernels.hpp"
#include "core/matrix/sellp_kernels.hpp"
#include "core/matrix/sparsity_csr_kernels.hpp"
#include "core/preconditioner/isai_kernels.hpp"
#include "core/preconditioner/jacobi_kernels.hpp"
#include "core/reorder/rcm_kernels.hpp"
#include "core/solver/bicg_kernels.hpp"
#include "core/solver/bicgstab_kernels.hpp"
#include "core/solver/cg_kernels.hpp"
#include "core/solver/cgs_kernels.hpp"
#include "core/solver/fcg_kernels.hpp"
#include "core/solver/gmres_kernels.hpp"
#include "core/solver/ir_kernels.hpp"
#include "core/solver/lower_trs_kernels.hpp"
#include "core/solver/upper_trs_kernels.hpp"
#include "core/stop/criterion_kernels.hpp"
#include "core/stop/residual_norm_kernels.hpp"


#ifndef GKO_HOOK_MODULE
#error "Need to define GKO_HOOK_MODULE variable before including this file"
#endif  // GKO_HOOK_MODULE


namespace gko {
namespace kernels {
namespace GKO_HOOK_MODULE {
namespace components {


template <typename SourceType, typename TargetType>
GKO_DECLARE_CONVERT_PRECISION_KERNEL(SourceType, TargetType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_CONVERSION(GKO_DECLARE_CONVERT_PRECISION_KERNEL);

template <typename IndexType>
GKO_DECLARE_PREFIX_SUM_KERNEL(IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_INDEX_TYPE(GKO_DECLARE_PREFIX_SUM_KERNEL);
// explicitly instantiate for size_type, as this is used in the SellP format
template GKO_DECLARE_PREFIX_SUM_KERNEL(size_type);

template <typename IndexType>
GKO_DECLARE_FILL_ARRAY_KERNEL(IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_INDEX_TYPE(GKO_DECLARE_FILL_ARRAY_KERNEL);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_FILL_ARRAY_KERNEL);
template GKO_DECLARE_FILL_ARRAY_KERNEL(size_type);

template <typename ValueType>
GKO_DECLARE_INPLACE_ABSOLUTE_ARRAY_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_INPLACE_ABSOLUTE_ARRAY_KERNEL);

template <typename ValueType>
GKO_DECLARE_OUTPLACE_ABSOLUTE_ARRAY_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_OUTPLACE_ABSOLUTE_ARRAY_KERNEL);


}  // namespace components


namespace dense {


template <typename ValueType>
GKO_DECLARE_DENSE_SIMPLE_APPLY_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_SIMPLE_APPLY_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_APPLY_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_APPLY_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_SCALE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_SCALE_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_ADD_SCALED_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_ADD_SCALED_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_ADD_SCALED_DIAG_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_ADD_SCALED_DIAG_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_COMPUTE_DOT_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_COMPUTE_DOT_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_COMPUTE_NORM2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_COMPUTE_NORM2_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_CONVERT_TO_COO_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_CONVERT_TO_COO_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_CONVERT_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_CONVERT_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_CONVERT_TO_ELL_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_CONVERT_TO_ELL_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_CONVERT_TO_HYBRID_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_CONVERT_TO_HYBRID_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_CONVERT_TO_SELLP_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_CONVERT_TO_SELLP_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_CONVERT_TO_SPARSITY_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_CONVERT_TO_SPARSITY_CSR_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_COUNT_NONZEROS_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_COUNT_NONZEROS_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_CALCULATE_MAX_NNZ_PER_ROW_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(
    GKO_DECLARE_DENSE_CALCULATE_MAX_NNZ_PER_ROW_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_CALCULATE_NONZEROS_PER_ROW_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(
    GKO_DECLARE_DENSE_CALCULATE_NONZEROS_PER_ROW_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_CALCULATE_TOTAL_COLS_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(
    GKO_DECLARE_DENSE_CALCULATE_TOTAL_COLS_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_TRANSPOSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_TRANSPOSE_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_CONJ_TRANSPOSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_CONJ_TRANSPOSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_ROW_GATHER_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_ROW_GATHER_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_COLUMN_PERMUTE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_COLUMN_PERMUTE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_INV_ROW_PERMUTE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_INV_ROW_PERMUTE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DENSE_INV_COLUMN_PERMUTE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DENSE_INV_COLUMN_PERMUTE_KERNEL);

template <typename ValueType>
GKO_DECLARE_DENSE_EXTRACT_DIAGONAL_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DENSE_EXTRACT_DIAGONAL_KERNEL);

template <typename ValueType>
GKO_DECLARE_INPLACE_ABSOLUTE_DENSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_INPLACE_ABSOLUTE_DENSE_KERNEL);

template <typename ValueType>
GKO_DECLARE_OUTPLACE_ABSOLUTE_DENSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_OUTPLACE_ABSOLUTE_DENSE_KERNEL);

template <typename ValueType>
GKO_DECLARE_MAKE_COMPLEX_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_MAKE_COMPLEX_KERNEL);

template <typename ValueType>
GKO_DECLARE_GET_REAL_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_GET_REAL_KERNEL);

template <typename ValueType>
GKO_DECLARE_GET_IMAG_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_GET_IMAG_KERNEL);


}  // namespace dense


namespace diagonal {


template <typename ValueType>
GKO_DECLARE_DIAGONAL_APPLY_TO_DENSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DIAGONAL_APPLY_TO_DENSE_KERNEL);

template <typename ValueType>
GKO_DECLARE_DIAGONAL_RIGHT_APPLY_TO_DENSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(
    GKO_DECLARE_DIAGONAL_RIGHT_APPLY_TO_DENSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DIAGONAL_APPLY_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DIAGONAL_APPLY_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DIAGONAL_RIGHT_APPLY_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DIAGONAL_RIGHT_APPLY_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_DIAGONAL_CONVERT_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_DIAGONAL_CONVERT_TO_CSR_KERNEL);

template <typename ValueType>
GKO_DECLARE_DIAGONAL_CONJ_TRANSPOSE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_DIAGONAL_CONJ_TRANSPOSE_KERNEL);


}  // namespace diagonal


namespace cg {


template <typename ValueType>
GKO_DECLARE_CG_INITIALIZE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CG_INITIALIZE_KERNEL);

template <typename ValueType>
GKO_DECLARE_CG_STEP_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CG_STEP_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_CG_STEP_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CG_STEP_2_KERNEL);


}  // namespace cg


namespace bicg {


template <typename ValueType>
GKO_DECLARE_BICG_INITIALIZE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICG_INITIALIZE_KERNEL);

template <typename ValueType>
GKO_DECLARE_BICG_STEP_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICG_STEP_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_BICG_STEP_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICG_STEP_2_KERNEL);


}  // namespace bicg


namespace lower_trs {


GKO_DECLARE_LOWER_TRS_SHOULD_PERFORM_TRANSPOSE_KERNEL()
GKO_NOT_COMPILED(GKO_HOOK_MODULE);

GKO_DECLARE_LOWER_TRS_INIT_STRUCT_KERNEL()
GKO_NOT_COMPILED(GKO_HOOK_MODULE);

template <typename ValueType, typename IndexType>
GKO_DECLARE_LOWER_TRS_GENERATE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_LOWER_TRS_GENERATE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_LOWER_TRS_SOLVE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_LOWER_TRS_SOLVE_KERNEL);


}  // namespace lower_trs


namespace upper_trs {


GKO_DECLARE_UPPER_TRS_SHOULD_PERFORM_TRANSPOSE_KERNEL()
GKO_NOT_COMPILED(GKO_HOOK_MODULE);

GKO_DECLARE_UPPER_TRS_INIT_STRUCT_KERNEL()
GKO_NOT_COMPILED(GKO_HOOK_MODULE);

template <typename ValueType, typename IndexType>
GKO_DECLARE_UPPER_TRS_GENERATE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_UPPER_TRS_GENERATE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_UPPER_TRS_SOLVE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_UPPER_TRS_SOLVE_KERNEL);


}  // namespace upper_trs


namespace fcg {


template <typename ValueType>
GKO_DECLARE_FCG_INITIALIZE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_FCG_INITIALIZE_KERNEL);

template <typename ValueType>
GKO_DECLARE_FCG_STEP_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_FCG_STEP_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_FCG_STEP_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_FCG_STEP_2_KERNEL);


}  // namespace fcg


namespace bicgstab {


template <typename ValueType>
GKO_DECLARE_BICGSTAB_INITIALIZE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICGSTAB_INITIALIZE_KERNEL);

template <typename ValueType>
GKO_DECLARE_BICGSTAB_STEP_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICGSTAB_STEP_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_BICGSTAB_STEP_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICGSTAB_STEP_2_KERNEL);

template <typename ValueType>
GKO_DECLARE_BICGSTAB_STEP_3_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICGSTAB_STEP_3_KERNEL);

template <typename ValueType>
GKO_DECLARE_BICGSTAB_FINALIZE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_BICGSTAB_FINALIZE_KERNEL);


}  // namespace bicgstab


namespace cgs {


template <typename ValueType>
GKO_DECLARE_CGS_INITIALIZE_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CGS_INITIALIZE_KERNEL);

template <typename ValueType>
GKO_DECLARE_CGS_STEP_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CGS_STEP_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_CGS_STEP_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CGS_STEP_2_KERNEL);

template <typename ValueType>
GKO_DECLARE_CGS_STEP_3_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_CGS_STEP_3_KERNEL);


}  // namespace cgs


namespace gmres {


template <typename ValueType>
GKO_DECLARE_GMRES_INITIALIZE_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_GMRES_INITIALIZE_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_GMRES_INITIALIZE_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_GMRES_INITIALIZE_2_KERNEL);

template <typename ValueType>
GKO_DECLARE_GMRES_STEP_1_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_GMRES_STEP_1_KERNEL);

template <typename ValueType>
GKO_DECLARE_GMRES_STEP_2_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_TYPE(GKO_DECLARE_GMRES_STEP_2_KERNEL);


}  // namespace gmres


namespace ir {


GKO_DECLARE_IR_INITIALIZE_KERNEL
GKO_NOT_COMPILED(GKO_HOOK_MODULE);


}  // namespace ir


namespace sparsity_csr {


template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_ADVANCED_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_ADVANCED_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_COUNT_NUM_DIAGONAL_ELEMENTS_KERNEL(ValueType,
                                                            IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_COUNT_NUM_DIAGONAL_ELEMENTS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_REMOVE_DIAGONAL_ELEMENTS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_REMOVE_DIAGONAL_ELEMENTS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_TRANSPOSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_TRANSPOSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_SORT_BY_COLUMN_INDEX(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_SORT_BY_COLUMN_INDEX);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SPARSITY_CSR_IS_SORTED_BY_COLUMN_INDEX(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SPARSITY_CSR_IS_SORTED_BY_COLUMN_INDEX);


}  // namespace sparsity_csr


namespace csr {


template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_CSR_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_ADVANCED_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_ADVANCED_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_SPGEMM_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_CSR_SPGEMM_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_ADVANCED_SPGEMM_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_ADVANCED_SPGEMM_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_SPGEAM_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_CSR_SPGEAM_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CONVERT_TO_DENSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CONVERT_TO_DENSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CONVERT_TO_COO_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CONVERT_TO_COO_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CONVERT_TO_ELL_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CONVERT_TO_ELL_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CONVERT_TO_HYBRID_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CONVERT_TO_HYBRID_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CONVERT_TO_SELLP_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CONVERT_TO_SELLP_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CALCULATE_TOTAL_COLS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CALCULATE_TOTAL_COLS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_TRANSPOSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_CSR_TRANSPOSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CONJ_TRANSPOSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CONJ_TRANSPOSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_ROW_PERMUTE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_ROW_PERMUTE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_INVERSE_COLUMN_PERMUTE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_INVERSE_COLUMN_PERMUTE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_INVERSE_ROW_PERMUTE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_INVERSE_ROW_PERMUTE_KERNEL);

template <typename IndexType>
GKO_DECLARE_INVERT_PERMUTATION_KERNEL(IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_INDEX_TYPE(GKO_DECLARE_INVERT_PERMUTATION_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CALCULATE_MAX_NNZ_PER_ROW_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CALCULATE_MAX_NNZ_PER_ROW_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_CALCULATE_NONZEROS_PER_ROW_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_CALCULATE_NONZEROS_PER_ROW_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_SORT_BY_COLUMN_INDEX(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_SORT_BY_COLUMN_INDEX);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_IS_SORTED_BY_COLUMN_INDEX(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_CSR_IS_SORTED_BY_COLUMN_INDEX);

template <typename ValueType, typename IndexType>
GKO_DECLARE_CSR_EXTRACT_DIAGONAL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_CSR_EXTRACT_DIAGONAL);


}  // namespace csr


namespace coo {


template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_COO_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_ADVANCED_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_COO_ADVANCED_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_SPMV2_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_COO_SPMV2_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_ADVANCED_SPMV2_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_COO_ADVANCED_SPMV2_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_CONVERT_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_COO_CONVERT_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_CONVERT_TO_DENSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_COO_CONVERT_TO_DENSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_COO_EXTRACT_DIAGONAL_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_COO_EXTRACT_DIAGONAL_KERNEL);


}  // namespace coo


namespace ell {


template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_ELL_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_ADVANCED_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ELL_ADVANCED_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_CONVERT_TO_DENSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ELL_CONVERT_TO_DENSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_CONVERT_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ELL_CONVERT_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_COUNT_NONZEROS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ELL_COUNT_NONZEROS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_CALCULATE_NONZEROS_PER_ROW_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ELL_CALCULATE_NONZEROS_PER_ROW_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ELL_EXTRACT_DIAGONAL_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ELL_EXTRACT_DIAGONAL_KERNEL);


}  // namespace ell


namespace hybrid {


template <typename ValueType, typename IndexType>
GKO_DECLARE_HYBRID_CONVERT_TO_DENSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_HYBRID_CONVERT_TO_DENSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_HYBRID_CONVERT_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_HYBRID_CONVERT_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_HYBRID_COUNT_NONZEROS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_HYBRID_COUNT_NONZEROS_KERNEL);


}  // namespace hybrid


namespace sellp {


template <typename ValueType, typename IndexType>
GKO_DECLARE_SELLP_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_SELLP_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SELLP_ADVANCED_SPMV_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SELLP_ADVANCED_SPMV_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SELLP_CONVERT_TO_DENSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SELLP_CONVERT_TO_DENSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SELLP_CONVERT_TO_CSR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SELLP_CONVERT_TO_CSR_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SELLP_COUNT_NONZEROS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SELLP_COUNT_NONZEROS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_SELLP_EXTRACT_DIAGONAL_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_SELLP_EXTRACT_DIAGONAL_KERNEL);


}  // namespace sellp


namespace jacobi {


template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_FIND_BLOCKS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_JACOBI_FIND_BLOCKS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_GENERATE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_JACOBI_GENERATE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_APPLY_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(GKO_DECLARE_JACOBI_APPLY_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_SIMPLE_APPLY_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_JACOBI_SIMPLE_APPLY_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_TRANSPOSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_JACOBI_TRANSPOSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_CONJ_TRANSPOSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_JACOBI_CONJ_TRANSPOSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_JACOBI_CONVERT_TO_DENSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_JACOBI_CONVERT_TO_DENSE_KERNEL);

GKO_DECLARE_JACOBI_INITIALIZE_PRECISIONS_KERNEL()
GKO_NOT_COMPILED(GKO_HOOK_MODULE);


}  // namespace jacobi


namespace isai {


template <typename ValueType, typename IndexType>
GKO_DECLARE_ISAI_GENERATE_TRI_INVERSE_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ISAI_GENERATE_TRI_INVERSE_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ISAI_GENERATE_EXCESS_SYSTEM_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ISAI_GENERATE_EXCESS_SYSTEM_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_ISAI_SCATTER_EXCESS_SOLUTION_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ISAI_SCATTER_EXCESS_SOLUTION_KERNEL);


}  // namespace isai


namespace factorization {


template <typename ValueType, typename IndexType>
GKO_DECLARE_FACTORIZATION_ADD_DIAGONAL_ELEMENTS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_FACTORIZATION_ADD_DIAGONAL_ELEMENTS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_FACTORIZATION_INITIALIZE_ROW_PTRS_L_U_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_FACTORIZATION_INITIALIZE_ROW_PTRS_L_U_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_FACTORIZATION_INITIALIZE_L_U_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_FACTORIZATION_INITIALIZE_L_U_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_FACTORIZATION_INITIALIZE_ROW_PTRS_L_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_FACTORIZATION_INITIALIZE_ROW_PTRS_L_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_FACTORIZATION_INITIALIZE_L_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_FACTORIZATION_INITIALIZE_L_KERNEL);


}  // namespace factorization


namespace ilu_factorization {


template <typename ValueType, typename IndexType>
GKO_DECLARE_ILU_COMPUTE_LU_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_ILU_COMPUTE_LU_KERNEL);


}  // namespace ilu_factorization


namespace par_ict_factorization {


template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ICT_ADD_CANDIDATES_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ICT_ADD_CANDIDATES_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ICT_COMPUTE_FACTOR_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ICT_COMPUTE_FACTOR_KERNEL);


}  // namespace par_ict_factorization


namespace par_ilu_factorization {


template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ILU_COMPUTE_L_U_FACTORS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ILU_COMPUTE_L_U_FACTORS_KERNEL);


}  // namespace par_ilu_factorization


namespace par_ilut_factorization {


template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ILUT_ADD_CANDIDATES_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ILUT_ADD_CANDIDATES_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ILUT_COMPUTE_LU_FACTORS_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ILUT_COMPUTE_LU_FACTORS_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ILUT_THRESHOLD_SELECT_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ILUT_THRESHOLD_SELECT_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ILUT_THRESHOLD_FILTER_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ILUT_THRESHOLD_FILTER_KERNEL);

template <typename ValueType, typename IndexType>
GKO_DECLARE_PAR_ILUT_THRESHOLD_FILTER_APPROX_KERNEL(ValueType, IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_VALUE_AND_INDEX_TYPE(
    GKO_DECLARE_PAR_ILUT_THRESHOLD_FILTER_APPROX_KERNEL);


}  // namespace par_ilut_factorization
namespace rcm {


template <typename IndexType>
GKO_DECLARE_RCM_GET_PERMUTATION_KERNEL(IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_INDEX_TYPE(GKO_DECLARE_RCM_GET_PERMUTATION_KERNEL);


template <typename IndexType>
GKO_DECLARE_RCM_GET_DEGREE_OF_NODES_KERNEL(IndexType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_INDEX_TYPE(GKO_DECLARE_RCM_GET_DEGREE_OF_NODES_KERNEL);


}  // namespace rcm


namespace set_all_statuses {


GKO_DECLARE_SET_ALL_STATUSES_KERNEL()
GKO_NOT_COMPILED(GKO_HOOK_MODULE);


}  // namespace set_all_statuses


namespace residual_norm {


template <typename ValueType>
GKO_DECLARE_RESIDUAL_NORM_KERNEL(ValueType)
GKO_NOT_COMPILED(GKO_HOOK_MODULE);
GKO_INSTANTIATE_FOR_EACH_NON_COMPLEX_VALUE_TYPE(
    GKO_DECLARE_RESIDUAL_NORM_KERNEL);


}  // namespace residual_norm
}  // namespace GKO_HOOK_MODULE
}  // namespace kernels
}  // namespace gko
