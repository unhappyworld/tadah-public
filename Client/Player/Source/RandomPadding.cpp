// We moved to non-ASLR at some point to get consistent hashes.
// Exploiters quickly moved to hardcoding fixed addresses each week.
// This is only here to move the code around a little bit each week.
#include "stdafx.h"
#include "Security/RandomConstant.h"
#include "Security/JunkCode.h"

template <int N> __forceinline void useless()
{
#ifdef _M_IX86
    junk<(N*(RBX_BUILDSEED%16) + __LINE__*N*(RBX_BUILDSEED%15) + N*N) % 17>();
#endif
    useless<N-1>();
    useless<N-1>();
}
template<> __forceinline void useless<0>() {}

// VS2012 really doesn't get why a function that is unused should exist.
extern "C"
{
#ifdef _M_IX86
#pragma comment (linker, "/export:_unusedPadding")
#endif
    void unusedPadding()
    {
        useless<9>();
    }
};

