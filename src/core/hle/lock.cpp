// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <core/hle/lock.h>

namespace HLE {

std::atomic_flag Lock::mLock = ATOMIC_FLAG_INIT;

Lock::Lock() {
    Lock::acquire();
}

Lock::~Lock() {
    Lock::release();
}

void Lock::acquire() {
    while (mLock.test_and_set(std::memory_order_acquire)) { ; }
}

bool Lock::tryAcquire() {
    return !mLock.test_and_set(std::memory_order_acquire);
}

void Lock::release() {
    mLock.clear(std::memory_order_release);
}

} // namespace HLE
