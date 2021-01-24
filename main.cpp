#define CATCH_CONFIG_RUNNER

#include <catch_all.hpp>

auto main( int argc, char* argv[] ) -> int {
    const auto result = Catch::Session().run(
        argc, argv
    );
    return result;
}
