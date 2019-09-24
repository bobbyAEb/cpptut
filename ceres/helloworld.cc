#include "ceres/ceres.h"
#include "glog/logging.h"

using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solve;
using ceres::Solver;

struct costFunctor {
  template <typename T>
  bool operator()(const T* const x, T* residual) const {
    residual[0] = T(10.0) - x[0];
    return true;
  }
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  double x = 0.5;
  const double initial_x = x;
  Problem problem;

  CostFunction* cost_function =
      new AutoDiffCostFunction<costFunctor, 1, 1>(new costFunctor);
  problem.AddResidualBlock(cost_function, NULL, &x);

  Solver::Options options;
  options.minimizer_progress_to_stdout = true;
  options.linear_solver_type = ceres::DENSE_QR;
  Solver::Summary summary;
  Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << "\n";
  std::cout << initial_x << "->" << x << std::endl;
  return 0;
}