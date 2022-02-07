// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.palisade.ckks.inc Name=$Name

template <class T>
$Name $Name::add(const $Name & a, const T & b) const
{
    $Name r;
    r.x = a.x.add(b, pek->key.cc);
    return r;
}

template <class T>
$Name $Name::sub(const $Name & a, const T & b) const
{
    $Name r;
    r.x = a.x.sub(b, pek->key.cc);
    return r;
}

template <class T>
$Name $Name::mul(const $Name & a, const T & b) const
{
    $Name r;
    r.x = a.x.mul(b, pek->key.cc);
    return r;
}

// === END  ring.palisade.ckks.inc Name=$Name
