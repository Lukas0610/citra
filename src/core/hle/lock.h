// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <atomic>

namespace HLE {

class Lock {

public:
    Lock();
    ~Lock();

    static void acquire();
    static bool tryAcquire();
    static void release();

private:
    static std::atomic_flag mLock;
};

} // namespace HLE
