#include <vector>
#include <ostream>
#include <cstdio>
#include <string>

namespace e3 {
namespace cr {

struct DdNode { int index; };

struct BDD
{
    BDD operator&(const BDD &) const { return BDD(); }
    BDD operator|(const BDD &) const { return BDD(); }
    BDD operator^(const BDD &) const { return BDD(); }
    BDD operator*(const BDD &) const { return BDD(); }
    BDD operator+(const BDD &) const { return BDD(); }
    BDD operator!() const { return BDD(); }
    friend std::ostream & operator<<(std::ostream & os, const BDD &) { return os; }
    std::string FactoredFormString(const char ** n = 0) const { return ""; }

    DdNode * getNode() const { static DdNode n; return &n; }
    BDD Compose(const BDD & g, int v) const{ return g; }
};

typedef void (*PFC)(std::string);
struct Cudd
{
    Cudd(
        unsigned int numVars = 0,
        unsigned int numVarsZ = 0,
        unsigned int numSlots = 0,
        unsigned int cacheSize = 0,
        unsigned long maxMemory = 0,
        PFC defaultHandler = nullptr);

    unsigned long ReadTimeLimit() { return 0xBAD; }

    BDD bddVar() { return BDD(); }
    BDD bddZero() { return BDD(); }
    BDD bddOne() { return BDD(); }
    void ReduceHeap() {}
    void DumpDDcal(const std::vector<BDD> &) {}
    void DumpDDcal(const std::vector<BDD> &, int, int, std::FILE *) {}
    void DumpDot(const std::vector<BDD> &, int, int, std::FILE *) {}
    void DumpDaVinci(const std::vector<BDD> &, int, int, std::FILE *) {}
    void DumpBlif(const std::vector<BDD> &, int, int, int, std::FILE *) {}
    void DumpFactoredForm(const std::vector<BDD> &, int, int, std::FILE *) {}

    unsigned long ReadMemoryInUse(){ return 0; } 

    void AutodynEnable(){}
    void AutodynDisable(){}
};

}} // e3::cr
