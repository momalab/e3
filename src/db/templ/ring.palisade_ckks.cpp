// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN ring.palisade.ckks.cpp Name=$Name

e3::PalisadeCkksEvalKey * g_pek_$Name = nullptr;
e3::PalisadeCkksEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name $Name::rotate(const $Name & a, int s)
{
    return a.x.rot(s, pek->key.cc);
}

std::vector < $Name > $Name::rotate(const $Name & a, const std::vector<int> & vs)
{
    std::vector < $Name > vr;
    auto vx = a.x.frot(vs, pek->key.cc);
    for ( auto & x : vx )
    {
        $Name r;
        r.x = x;
        vr.push_back(r);
    }
    return vr;
}

// === END ring.palisade.ckks.cpp Name=$Name
