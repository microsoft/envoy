// NOLINT(namespace-envoy)
#include "test/test_common/environment.h"
#include "test/test_runner.h"

#ifdef ENVOY_HANDLE_SIGNALS
#include "exe/signal_action.h"
#endif

const char* __asan_default_options() {
  static char result[] = {"check_initialization_order=true strict_init_order=true"};
  return result;
}

// The main entry point (and the rest of this file) should have no logic in it,
// this allows overriding by site specific versions of main.cc.
int main(int argc, char** argv) {
#if defined(WIN32)
  WORD wVersionRequested;
  WSADATA wsaData;
  int err;

  /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
  wVersionRequested = MAKEWORD(2, 2);

  err = WSAStartup(wVersionRequested, &wsaData);
  if (err != 0) {
    /* Tell the user that we could not find a usable */
    /* Winsock DLL.                                  */
    printf("WSAStartup failed with error: %d\n", err);
    return 1;
  }
#endif
#ifdef ENVOY_HANDLE_SIGNALS
  // Enabled by default. Control with "bazel --define=signal_trace=disabled"
  Envoy::SignalAction handle_sigs;
#endif

#if !defined(WIN32)
  ::setenv("TEST_RUNDIR",
           (Envoy::TestEnvironment::getCheckedEnvVar("TEST_SRCDIR") + "/" +
            Envoy::TestEnvironment::getCheckedEnvVar("TEST_WORKSPACE"))
               .c_str(),
           1);
  // Select whether to test only for IPv4, IPv6, or both. The default is to
  // test for both. Options are {"v4only", "v6only", "all"}. Set
  // ENVOY_IP_TEST_VERSIONS to "v4only" if the system currently does not support IPv6 network
  // operations. Similary set ENVOY_IP_TEST_VERSIONS to "v6only" if IPv4 has already been
  // phased out of network operations. Set to "all" (or don't set) if testing both
  // v4 and v6 addresses is desired. This feature is in progress and will be rolled out to all tests
  // in upcoming PRs.
  ::setenv("ENVOY_IP_TEST_VERSIONS", "all", 0);
#else
  _putenv(("TEST_RUNDIR=" + Envoy::TestEnvironment::getCheckedEnvVar("TEST_SRCDIR") +
           "/" + 
           Envoy::TestEnvironment::getCheckedEnvVar("TEST_WORKSPACE"))
              .c_str());
  if (!getenv("ENVOY_IP_TEST_VERSIONS"))
  {
    _putenv("ENVOY_IP_TEST_VERSIONS=all");
  }
#endif

  return Envoy::TestRunner::RunTests(argc, argv);
}
