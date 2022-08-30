#pragma once

namespace RBX
{
#ifdef _M_IX86
    typedef BOOLEAN(NTAPI* RtlDispatchExceptionPfn)(PEXCEPTION_RECORD exRec, PCONTEXT ctx);
    // extern RtlDispatchExceptionPfn vehHookContinue; // moved to App because this needs to be checked.
    extern DWORD* vehHookLocation;
    BOOLEAN RtlDispatchExceptionHook(PEXCEPTION_RECORD exRec, PCONTEXT ctx);
    bool hookPreVeh();
#endif

    void hookApi();
    void unhookApi();
}