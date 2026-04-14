// Copyright 2026 Carlos

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "./catch.hpp"  // NOLINT(build/include_subdir)
#include "./romanos.hpp"  // NOLINT(build/include_subdir)

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]") {
  REQUIRE(romanos_para_decimal("I") == 1);
  REQUIRE(romanos_para_decimal("V") == 5);
  REQUIRE(romanos_para_decimal("X") == 10);
  REQUIRE(romanos_para_decimal("L") == 50);
  REQUIRE(romanos_para_decimal("C") == 100);
  REQUIRE(romanos_para_decimal("D") == 500);
}

/*
TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]") {
  REQUIRE(romanos_para_decimal("G") == -1);
  REQUIRE(romanos_para_decimal("i") == -1);
}
*/
