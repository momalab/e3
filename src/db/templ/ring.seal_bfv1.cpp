// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN  ring.seal.cpp Name=$Name

e3::SealEvalKey * g_pek_$Name = nullptr;
e3::SealEvalKey * $Name::pek = nullptr;
const $Name * $Name::unit = nullptr;
const $Name * $Name::zero = nullptr;

$Name & $Name::operator+=(const $Name & a)
{
    e3::e3seal::toek(pek->key)->evaluator->add_inplace(x.p->ct, a.x.p->ct);
    return *this;
}

$Name & $Name::operator-=(const $Name & a)
{
    e3::e3seal::toek(pek->key)->evaluator->sub_inplace(x.p->ct, a.x.p->ct);
    return *this;
}

$Name & $Name::operator*=(const $Name & a)
{
    auto ek = e3::e3seal::toek(pek->key);
    ek->evaluator->multiply_inplace(x.p->ct, a.x.p->ct);
    ek->evaluator->relinearize_inplace(x.p->ct, ek->relinkeys);
    return *this;
}

$Name $Name::operator+(const $Name & a) const
{
    $Name r(*this);
    r += a;
    return r;
}

$Name $Name::operator-(const $Name & a) const
{
    $Name r(*this);
    r -= a;
    return r;
}

$Name $Name::operator*(const $Name & a) const
{
    $Name r(*this);
    r *= a;
    return r;
}

$Name $Name::operator-() const
{
    $Name r(*this);
    e3::e3seal::toek(pek->key)->evaluator->negate(r.x.p->ct, x.p->ct);
    return *this;
}

#if SEALVER == 332

$Name $Name::operator*(const std::vector<unsigned long long> & v) const
{
    $Name r(*this);
    seal::Plaintext p;
    auto ek = e3::e3seal::toek(pek->key);
    if ( ek->isBatchEncoder ) p = e3::e3seal::batchEncode( v, *(ek->batchEncoder) );
    else ek->encoder->encode(uint64_t(v[0]), p);
    ek->evaluator->multiply_plain_inplace(r.x.p->ct, p);
    ///ek->evaluator->relinearize_inplace(r.x.p->ct, ek->relinkeys);
    return r;
}

$Name $Name::operator+(const std::vector<unsigned long long> & v) const
{
    $Name r(*this);
    seal::Plaintext p;
    auto ek = e3::e3seal::toek(pek->key);
    if ( ek->isBatchEncoder ) p = e3::e3seal::batchEncode( v, *(ek->batchEncoder) );
    else ek->encoder->encode(uint64_t(v[0]), p);
    ek->evaluator->add_plain_inplace(r.x.p->ct, p);
    return r;
}

$Name $Name::operator-(const std::vector<unsigned long long> & v) const
{
    $Name r(*this);
    seal::Plaintext p;
    auto ek = e3::e3seal::toek(pek->key);
    if ( ek->isBatchEncoder ) p = e3::e3seal::batchEncode( v, *(ek->batchEncoder) );
    else ek->encoder->encode(uint64_t(v[0]), p);
    ek->evaluator->sub_plain_inplace(r.x.p->ct, p);
    return r;
}

#else

$Name $Name::operator*(const std::vector<unsigned long long> & v) const
{
    $Name r(*this);
    seal::Plaintext p;
    auto ek = e3::e3seal::toek(pek->key);
    p = e3::e3seal::batchEncode( v, *(ek->batchEncoder) );
    ek->evaluator->multiply_plain_inplace(r.x.p->ct, p);
    ///ek->evaluator->relinearize_inplace(r.x.p->ct, ek->relinkeys);
    return r;
}

$Name $Name::operator+(const std::vector<unsigned long long> & v) const
{
    $Name r(*this);
    seal::Plaintext p;
    auto ek = e3::e3seal::toek(pek->key);
    p = e3::e3seal::batchEncode( v, *(ek->batchEncoder) );
    ek->evaluator->add_plain_inplace(r.x.p->ct, p);
    return r;
}

$Name $Name::operator-(const std::vector<unsigned long long> & v) const
{
    $Name r(*this);
    seal::Plaintext p;
    auto ek = e3::e3seal::toek(pek->key);
    p = e3::e3seal::batchEncode( v, *(ek->batchEncoder) );
    ek->evaluator->sub_plain_inplace(r.x.p->ct, p);
    return r;
}

#endif

$Name & $Name::rotate_columns()
{
    auto ek = e3::e3seal::toek(pek->key);
    if ( ek->isBatchEncoder )
        ek->evaluator->rotate_columns_inplace(x.p->ct, ek->galoiskeys );
    return *this;
}

$Name & $Name::rotate_rows(int s)
{
    auto ek = e3::e3seal::toek(pek->key);
    if ( ek->isBatchEncoder )
        ek->evaluator->rotate_rows_inplace(x.p->ct, s, ek->galoiskeys );
    return *this;
}

// === END  ring.seal.cpp Name=$Name
