/*
Use Eigen::Map to avoid copies when interfacing with C APIs or raw buffers.

Use .array() for elementwise ops and .matrix() for linear algebra.

For matrix multiplies, use noalias() when writing A = B*C; into a preallocated matrix to avoid temporary allocations: A.noalias() = B*C;

Preallocate and reuse buffers for streaming processing to avoid allocations.

Use Eigen::Ref<const VectorXd> for functions that accept Eigen expressions without copying.

Compile with -O3 -march=native to let Eigen vectorize.

For FFT-heavy code, avoid repeated planning in FFTW: create & reuse plans if buffer sizes are fixed.
*/