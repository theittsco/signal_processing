/*
Use BDCSVD or JacobiSVD for low-rank approximation of spectrograms or Hankel matrices for denoising.

Example: perform truncated SVD and reconstruct rank-k approximation:
*/
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::BDCSVD;

MatrixXd low_rank_approx(const MatrixXd& M, int k) {
    BDCSVD<MatrixXd> svd(M, Eigen::ComputeThinU | Eigen::ComputeThinV);
    MatrixXd U = svd.matrixU().leftCols(k);
    MatrixXd Vt = svd.matrixV().leftCols(k).transpose();
    MatrixXd S = svd.singularValues().head(k).asDiagonal();
    return U * S * Vt;
}
// This is useful for denoising spectrograms (soft/hard thresholding on singular values).