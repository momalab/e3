#include <iostream>
#include "cuddObj.hh"

namespace e3 { namespace cr {} }
using namespace e3::cr;

int main()
{
    Cudd mgr(0, 0);

    std::cout << "TimeLimit=" << mgr.ReadTimeLimit() << '\n';

    BDD a0 = mgr.bddVar();
    BDD a1 = mgr.bddVar();
    BDD a2 = mgr.bddVar();
    BDD a3 = mgr.bddVar();
    BDD a4 = mgr.bddVar();
    BDD a5 = mgr.bddVar();

    BDD g1, g2, g3;
    {
        BDD f = a0 ^ a1 ;//+ x2; //*x3;
        //BDD f2 = x0 + x1 * x2; //*x3;
        g1 = f * a2;
        g2 = f * a3;
        g3 = f + a2;
    }

    mgr.ReduceHeap();

    //std::cout <<"\no Blif:\n";
    //mgr.DumpBlif(std::vector<BDD>{ f });

    std::cout << "\no DDcal:\n";
    mgr.DumpDDcal(std::vector<BDD> { g1, g2, a4, a5 });

    //std::cout <<"\no Dot:\n";
    //mgr.DumpDot(std::vector<BDD>{ f });

    //std::cout <<"\no DaVinci:\n";
    //mgr.DumpDaVinci(std::vector<BDD>{ f });

    //std::cout <<"\no Form:\n";
    //mgr.DumpFactoredForm(std::vector<BDD>{ f });

    std::cout << "\no cout:\n" << g1 << '\n';
    std::cout << "\no cout:\n" << g2 << '\n';
    g1 = (a4 ^ !a5);
    std::cout << "\no cout (x4^!x5):\n" << g1 << '\n';
    mgr.DumpDDcal(std::vector<BDD> { g1 });

    //mgr.DumpFactoredForm(std::vector<BDD>{ f2 });
    //std::cout <<'\n' << f2 << '\n';

    std::cout << "Memory used: " << mgr.ReadMemoryInUse() << '\n';
}