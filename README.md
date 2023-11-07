# 04_homework


build:
```
bazel build //src:homework --define VERSION=1
```

run:
```
bazel-bin/src/homework
```

run tests:
```
bazel test --test_output=all //src/print_ip:print_ip_test
```

build deb package:
```
bazel build //src:homework_deb --define VERSION=1
```
