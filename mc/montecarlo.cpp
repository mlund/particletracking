#include <faunus/faunus.h>

using namespace Faunus;                   // use Faunus namespace
typedef Space<Geometry::CuboidNoPBC> Tspace;   // Type of simulation space: change to Geometry::Cuboid for PBC

namespace Faunus {
  namespace Potential {
    // let's make a new pair potential
    struct RepulsionR3 : public PairPotentialBase {
      double f, s, e;
      inline RepulsionR3(Tmjson &j, const string &sec="repulsionr3") : PairPotentialBase(sec) {
        name = "1/r3 repulsion";
        f = j[sec]["prefactor"] | 1.0;
        e = j[sec]["lj-prefactor"] | 1.0;
        s = j[sec]["sigma"] | 1.0;
      }
      template<class Tparticle>
        double operator() (const Tparticle &a, const Tparticle &b, double r2) {
          double r = sqrt(r2);
          return f / (r*r2) + e * pow( s/r, 12 );
        }
    };
  }
}

int main() {
  InputMap in("montecarlo.json");            // open parameter file for user input
  Tspace spc(in);                         // simulation space, particles etc.
  Energy::Nonbonded<Tspace,Potential::RepulsionR3> pot(in);// Hamiltonian, non-bonded only

  spc.load("state");                      // load old configuration if any

  Histogram<double> hist(1.0);
  Move::Propagator<Tspace> mv(in,pot,spc);// particle move class

  for (int i=0; i<4e4; i++) {
    mv.move();
    // build histogram of histances
    for (size_t i=0; i<spc.p.size()-1; i++)
      for (size_t j=i+1; j<spc.p.size(); j++) {
        double r = spc.geo.dist( spc.p[i], spc.p[j] );
        hist(r)++;
      }
  }

  spc.save("state");                      // save final state
  hist.save("hist.dat");                  // distance distribution: change name to histpbc.dat when PBC are used
  FormatPQR::save("confout.pqr", spc.p);  // save PQR file for i.e. VMD
  cout << spc.info() + pot.info() + mv.info(); // final information

}
