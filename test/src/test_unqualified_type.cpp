// Copyright (c) 2014 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <gtest/gtest.h>
#include <stub/unqualified_type.hpp>

// Small alias to make testing easier

namespace
{
    template<class A, class B>
    using test = std::is_same<typename stub::unqualified_type<A>::type, B>;
}

/// Test that the unqualified type helper works as expected
TEST(unqualified_type, test)
{
    {
        auto ok = test<const uint32_t&, uint32_t>::value;
        EXPECT_TRUE(ok);
    }

    {
        auto ok = test<uint32_t&, uint32_t>::value;
        EXPECT_TRUE(ok);
    }
}