#include <curves/SlurpSE3Evaluator.hpp>
#include <curves/Coefficients.hpp>
#include <iostream>

using namespace std;

namespace curves {

SlurpSE3Evaluator::SlurpSE3Evaluator(const SlurpSE3Curve& curve, const Time& time){
//  KeyCoefficientTime *coeff0, *coeff1;
//  curve.getCoefficientsAt(time, &coeff0, &coeff1);
//  keys_.push_back(coeff0->key);
//  keys_.push_back(coeff1->key);
//
//  // Compute alpha_
//  Time dt = coeff1->time - coeff0->time;
//  if(dt == 0) {
//    alpha_ = 1.0;
//  } else {
//    Time t = time - coeff0->time;
//    alpha_ = double(t)/double(dt);
//  }
//  dimension_ = curve.dim();
}

SlurpSE3Evaluator::~SlurpSE3Evaluator() {}

void SlurpSE3Evaluator::getKeys(std::vector<Key> *outKeys) const {
  CHECK_NOTNULL(outKeys);
  *outKeys = keys_;
}

void SlurpSE3Evaluator::appendKeys(std::vector<Key> *outKeys) const {
  CHECK_NOTNULL(outKeys);
  outKeys->insert(outKeys->end(), keys_.begin(), keys_.end());
}

std::vector<Key>::const_iterator SlurpSE3Evaluator::keyBegin() const {
  return keys_.begin();
}

std::vector<Key>::const_iterator SlurpSE3Evaluator::keyEnd() const {
  return keys_.end();
}


SlurpSE3Evaluator::ValueType SlurpSE3Evaluator::evaluate(
    const std::vector<Coefficient>& coefficients) const {

//  return coefficients[0].getValue() * (1.0 - alpha_) + coefficients[1].getValue() * alpha_;
}

SlurpSE3Evaluator::ValueType SlurpSE3Evaluator::evaluate(
    const Coefficients& coefficients) const {

//  return coefficients.get(keys_[0]).getValue() * (1.0 - alpha_) + coefficients.get(keys_[1]).getValue() * alpha_;
}

void SlurpSE3Evaluator::getJacobians(unsigned derivativeOrder,
                                                           const Coefficients& /* coefficients */,
                                                           const Eigen::MatrixXd& chainRule,
                                                           const std::vector<Eigen::MatrixXd*>& jacobians) const {
  // TODO(Abel and Renaud) implement velocity
  CHECK_EQ(derivativeOrder, 0);
  CHECK_NOTNULL(jacobians[0]);
  CHECK_NOTNULL(jacobians[1]);
  //TODO check matrix sizes should be chainRule.rows() x coefficient.ndim()
  *(jacobians[0]) += chainRule * Eigen::MatrixXd::Identity(dimension_,dimension_) * (1.0 - alpha_);
  *(jacobians[1]) += chainRule * Eigen::MatrixXd::Identity(dimension_,dimension_) * alpha_;
}

/// Evaluate the ambient space of the curve
SlurpSE3Evaluator::ValueType SlurpSE3Evaluator::evaluateDerivative(unsigned derivativeOrder,
                                                                            const Coefficients& coefficients) const {
  // \todo Abel and Renaud
  CHECK(false) << "To be implemented by Abel and Renaud :-)";
}

/// Evaluate the curve derivatives (functional form).
SlurpSE3Evaluator::ValueType SlurpSE3Evaluator::evaluateDerivative(unsigned derivativeOrder,
                                                                            const std::vector<Coefficient>& coefficients) const {
  // \todo Abel and Renaud
  CHECK(false) << "To be implemented by Abel and Renaud :-)";
}

/// Evaluate the ambient space of the curve (functional form).
SlurpSE3Evaluator::ValueType SlurpSE3Evaluator::evaluateAndJacobian(const std::vector<Coefficient>& coefficients,
                                                                             std::vector<Eigen::MatrixXd>* outJacobian) const {
  // \todo Abel and Renaud
  CHECK(false) << "To be implemented by Abel and Renaud :-)";
}

/// Evaluate the curve derivatives (functional form).
SlurpSE3Evaluator::ValueType SlurpSE3Evaluator::evaluateDerivativeAndJacobian(unsigned derivativeOrder,
                                                                                       const std::vector<Coefficient>& coefficients,
                                                                                       std::vector<Eigen::MatrixXd>* outJacobian) const {
  // \todo Abel and Renaud
  CHECK(false) << "To be implemented by Abel and Renaud :-)";
}

} // namespace curves