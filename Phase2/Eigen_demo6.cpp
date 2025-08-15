/*
Autocorr via FFT (fast) or via Toeplitz solve. Welch: split into overlapped windows, compute periodograms, average.

Simple Welch outline (no code for every step, but key Eigen parts):

1. Frame the signal into overlapped windows → MatrixXd frames.
2. Multiply by window vector broadcasted across columns: frames = frames.array().colwise() * w.array();
3. For each column: compute FFT → magnitude squared → accumulate and normalize by window power.
4. Average periodograms across frames → PSD estimate.

Eigen tip: do frames.array().colwise() *= w.array(); to window all frames without copies.
*/