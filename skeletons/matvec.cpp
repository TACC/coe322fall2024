#include <iostream>
using std::cout,std::cin;
#include <chrono>
#include <string>
using std::string;

#include <ranges>
using std::ranges::views::iota,
  std::ranges::views::filter,
  std::ranges::views::transform;

#include <numeric>
using std::accumulate;

#include <Eigen/Dense>
using namespace Eigen;
// ::Matrix, Eigen::Vector;
 
/*
 * Jacobi Iterative method with seq
 */
template< typename MatrixType,typename VectorType >
void JacobiSolve1( MatrixType A,VectorType sol,VectorType rhs ) {

  auto tmp{sol};
  // set initial guess to identically one
  int siz = A.rows();
  for ( auto& v : sol )
    v = 1.;
  // for a number of iteration
  for ( auto it : iota(0,10) ) {
    // one step of Jacobi
    cout << "it: " << it << '\n' << sol << '\n';
  }
}

/*
 * Jacobi Iterative method with ranges
 */
template< typename MatrixType,typename VectorType >
void JacobiSolve2( MatrixType A,VectorType sol,VectorType rhs ) {

  auto tmp{sol};
  // set initial guess to identically one
  int siz = A.rows();
  for ( auto& v : sol )
    v = 1.;
  // for a number of iteration
  for ( auto it : iota(0,10) ) {
    // one step of Jacobi
    cout << "it: " << it << '\n' << sol << '\n';
  }
}

int main()
{

  const int siz=5;
  Matrix<double,siz,siz> A;
  Vector<double,siz> sol,rhs,tmp;
  
  cout << "Matrix size: " << A.rows() << "," << A.cols() << " (" << A.size() << ")\n";

  for ( auto& v : rhs )
    v = 1.;
  cout << rhs << '\n';

  for ( auto row : iota(0,siz) ) {
    sol(row) = static_cast<double>( row );
    A(row,row) = siz;
    for ( auto col : iota(0,siz) ) {
      if (row==col) continue;
      A(row,col) = -1;
    }
  }
  cout << "sol:\n" << sol << '\n';
  rhs = A*sol;
  cout << "rhs:\n" << rhs << '\n';

  cout << "================ Solve 1\n";
  JacobiSolve1( A,sol,rhs );
  cout << "================ Solve 2\n";
  JacobiSolve2( A,sol,rhs );

  Matrix<float,Dynamic,Dynamic> Af(20,20);
  // or: MatrixXf Af(20,20);

  return 0;
}
