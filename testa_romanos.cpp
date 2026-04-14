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
  REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - adicoes simples", "[romanos]") {
  REQUIRE(romanos_para_decimal("II") == 2);
  REQUIRE(romanos_para_decimal("III") == 3);
  REQUIRE(romanos_para_decimal("XX") == 20);
  REQUIRE(romanos_para_decimal("VI") == 6);
  REQUIRE(romanos_para_decimal("VII") == 7);
  REQUIRE(romanos_para_decimal("VIII") == 8);
}

TEST_CASE("Numeros romanos - subtracao basica", "[romanos]") {
  REQUIRE(romanos_para_decimal("IV") == 4);
  REQUIRE(romanos_para_decimal("IX") == 9);
  REQUIRE(romanos_para_decimal("XL") == 40);
  REQUIRE(romanos_para_decimal("XC") == 90);
  REQUIRE(romanos_para_decimal("CD") == 400);
  REQUIRE(romanos_para_decimal("CM") == 900);
}

TEST_CASE("Numeros romanos - compostos e limites", "[romanos]") {
  REQUIRE(romanos_para_decimal("XIV") == 14);
  REQUIRE(romanos_para_decimal("MCMXCIV") == 1994);
  REQUIRE(romanos_para_decimal("MMM") == 3000);
}

TEST_CASE("Numeros romanos - erros e tolerancias", "[romanos]") {
  REQUIRE(romanos_para_decimal("") == -1);
  REQUIRE(romanos_para_decimal("IIIIVVVVXXXXLLLLCCCCDDDDMMMMMMA") == -1);
  REQUIRE(romanos_para_decimal("MMMI") == -1);
  REQUIRE(romanos_para_decimal("MMMM") == -1);
  REQUIRE(romanos_para_decimal("A") == -1);
  REQUIRE(romanos_para_decimal("XI A") == -1);
  REQUIRE(romanos_para_decimal("123") == -1);
  REQUIRE(romanos_para_decimal("i") == -1);
  REQUIRE(romanos_para_decimal("v") == -1);
  REQUIRE(romanos_para_decimal("Mm") == -1);
}

