#include "ceres/ceres.h"
#include "glog/logging.h"

using ceres::CostFunction;
using ceres::Problem;
using ceres::SizedCostFunction;
using ceres::Solve;
using ceres::Solver;

struct costFunctor {
  template <typename T>
  bool operator()(const T* const x, T* residual) const {
    residual[0] = T(10.0) - x[0];
    return true;
  }
};
class QuadraticCostFunction : public ceres::SizedCostFunction<1, 1> {
 public:
  virtual ~QuadraticCostFunction(){};
  virtual bool Evaluate(double const* const* parameters, double* residuals,
                        double** jacobians) const {
    const double x = parameters[0][0];
    residuals[0] = 10 - x;
    if (jacobians != NULL && jacobians[0] != NULL) {
      jacobians[0][0] = -1;
    }
    return true;
  }
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  double x = 0.5;
  const double initial_x = x;
  Problem problem;

  CostFunction* cost_function = new QuadraticCostFunction;
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