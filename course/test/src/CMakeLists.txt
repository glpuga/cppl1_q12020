# Include paths.
include_directories(
	../include
)

# Test sources.
set (GTEST_SOURCES
	isometry_TEST.cc
	foo_TEST.cc
)

cppcourse_build_tests(${GTEST_SOURCES})