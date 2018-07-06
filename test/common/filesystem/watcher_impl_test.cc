#include <cstdint>
#include <fstream>

#include "common/common/assert.h"
#include "common/event/dispatcher_impl.h"
#if defined(WIN32)
#include "common/filesystem/win32/watcher_impl.h"
#else
#include "common/filesystem/watcher_impl.h"
#endif

#include "test/test_common/environment.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace Envoy {
namespace Filesystem {

class WatchCallback {
public:
  MOCK_METHOD1(called, void(uint32_t));
};

TEST(WatcherImplTest, All) {
  Event::DispatcherImpl dispatcher;
  Filesystem::WatcherPtr watcher = dispatcher.createFilesystemWatcher();

  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_target").c_str());
  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str());
  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_new_target").c_str());
  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str());

#if defined(WIN32)
  _mkdir(TestEnvironment::temporaryPath("envoy_test").c_str());
#else
  mkdir(TestEnvironment::temporaryPath("envoy_test").c_str(), S_IRWXU);
#endif

  { std::ofstream file(TestEnvironment::temporaryPath("envoy_test/watcher_target")); }
#if defined(WIN32)
  int rc = CreateSymbolicLink(TestEnvironment::temporaryPath("envoy_test/watcher_target").c_str(),
                              TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str(), 0);
  EXPECT_NE(0, rc);
#else
  int rc = symlink(TestEnvironment::temporaryPath("envoy_test/watcher_target").c_str(),
                   TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str());
  EXPECT_EQ(0, rc);
#endif

  { std::ofstream file(TestEnvironment::temporaryPath("envoy_test/watcher_new_target")); }
#if defined(WIN32)
  rc = CreateSymbolicLink(TestEnvironment::temporaryPath("envoy_test/watcher_new_target").c_str(),
                          TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str(), 0);
  EXPECT_NE(0, rc);
#else
  rc = symlink(TestEnvironment::temporaryPath("envoy_test/watcher_new_target").c_str(),
               TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str());
  EXPECT_EQ(0, rc);
#endif

  WatchCallback callback;
  EXPECT_CALL(callback, called(Watcher::Events::MovedTo)).Times(2);
  watcher->addWatch(TestEnvironment::temporaryPath("envoy_test/watcher_link"),
                    Watcher::Events::MovedTo, [&](uint32_t events) -> void {
                      callback.called(events);
                      dispatcher.exit();
                    });

  rename(TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str(),
         TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str());
  dispatcher.run(Event::Dispatcher::RunType::Block);

#if defined(WIN32)
  rc = CreateSymbolicLink(TestEnvironment::temporaryPath("envoy_test/watcher_new_target").c_str(),
                          TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str(), 0);
  EXPECT_NE(0, rc);
#else
  rc = symlink(TestEnvironment::temporaryPath("envoy_test/watcher_new_target").c_str(),
               TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str());
  EXPECT_EQ(0, rc);
#endif
  rename(TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str(),
         TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str());
  dispatcher.run(Event::Dispatcher::RunType::Block);
}

TEST(WatcherImplTest, Create) {
  Event::DispatcherImpl dispatcher;
  Filesystem::WatcherPtr watcher = dispatcher.createFilesystemWatcher();

  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_target").c_str());
  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str());
  unlink(TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str());
  unlink(TestEnvironment::temporaryPath("envoy_test/other_file").c_str());

#if defined(WIN32)
  _mkdir(TestEnvironment::temporaryPath("envoy_test").c_str());
#else
  mkdir(TestEnvironment::temporaryPath("envoy_test").c_str(), S_IRWXU);
#endif

  { std::ofstream file(TestEnvironment::temporaryPath("envoy_test/watcher_target")); }

  WatchCallback callback;
  EXPECT_CALL(callback, called(Watcher::Events::MovedTo));
  watcher->addWatch(TestEnvironment::temporaryPath("envoy_test/watcher_link"),
                    Watcher::Events::MovedTo, [&](uint32_t events) -> void {
                      callback.called(events);
                      dispatcher.exit();
                    });

  { std::ofstream file(TestEnvironment::temporaryPath("envoy_test/other_file")); }
  dispatcher.run(Event::Dispatcher::RunType::NonBlock);

#if defined(WIN32)
  int rc =
      CreateSymbolicLink(TestEnvironment::temporaryPath("envoy_test/watcher_target").c_str(),
                         TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str(), 0);
  EXPECT_NE(0, rc);
#else
  int rc = symlink(TestEnvironment::temporaryPath("envoy_test/watcher_target").c_str(),
                   TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str());
  EXPECT_EQ(0, rc);
#endif

  rc = rename(TestEnvironment::temporaryPath("envoy_test/watcher_new_link").c_str(),
              TestEnvironment::temporaryPath("envoy_test/watcher_link").c_str());
  EXPECT_EQ(0, rc);

  dispatcher.run(Event::Dispatcher::RunType::Block);
}

TEST(WatcherImplTest, BadPath) {
  Event::DispatcherImpl dispatcher;
  Filesystem::WatcherPtr watcher = dispatcher.createFilesystemWatcher();

  EXPECT_THROW(
      watcher->addWatch("this_is_not_a_file", Watcher::Events::MovedTo, [&](uint32_t) -> void {}),
      EnvoyException);

  EXPECT_THROW(watcher->addWatch("this_is_not_a_dir/file", Watcher::Events::MovedTo,
                                 [&](uint32_t) -> void {}),
               EnvoyException);
}

TEST(WatcherImplTest, ParentDirectoryRemoved) {
  Event::DispatcherImpl dispatcher;
  Filesystem::WatcherPtr watcher = dispatcher.createFilesystemWatcher();

#if defined(WIN32)
  _mkdir(TestEnvironment::temporaryPath("envoy_test_empty").c_str());
#else
  mkdir(TestEnvironment::temporaryPath("envoy_test_empty").c_str(), S_IRWXU);
#endif

  WatchCallback callback;
  EXPECT_CALL(callback, called(testing::_)).Times(0);

  watcher->addWatch(TestEnvironment::temporaryPath("envoy_test_empty/watcher_link"),
                    Watcher::Events::MovedTo,
                    [&](uint32_t events) -> void { callback.called(events); });

  int rc = rmdir(TestEnvironment::temporaryPath("envoy_test_empty").c_str());
  EXPECT_EQ(0, rc);

  dispatcher.run(Event::Dispatcher::RunType::NonBlock);
}

} // namespace Filesystem
} // namespace Envoy
