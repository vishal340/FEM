#include <deal.II/base/logstream.h>

#include <iostream>

using namespace dealii;

int main()
{
  deallog.depth_console(1);
  std::cout << "deal.II " << DEAL_II_PACKAGE_VERSION
            << " is available.\n";
  return 0;
}
