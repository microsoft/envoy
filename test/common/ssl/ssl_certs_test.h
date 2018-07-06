#pragma once

#include "test/test_common/environment.h"

#include "gtest/gtest.h"

namespace Envoy {
class SslCertsTest : public testing::Test {
public:
  static void SetUpTestCase() {
#if defined(WIN32)
    TestEnvironment::exec({TestEnvironment::runfilesPath("test/common/ssl/gen_unittest_certs.bat")});
#else
    TestEnvironment::exec({TestEnvironment::runfilesPath("test/common/ssl/gen_unittest_certs.sh")});
#endif
  }
};
} // namespace Envoy
