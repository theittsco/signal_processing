// Pseudocode steps
// 1. choose L = nextpow2(n+m-1)
// 2. zero-pad x and h to length L (Eigen::VectorXd)
// 3. forward FFT both (Eigen::Map -> fftw)
 // 4. multiply X .* H (elementwise complex)
 // 5. inverse FFT -> real result (normalize)
//This yields O(L log L) rather than O(n*m).