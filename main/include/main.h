#ifndef MAIN_H
#define MAIN_H

#pragma once

#include <stdint.h>

extern const uint8_t ulp_bin_start[] asm("_binary_ulp_prog_bin_start");
extern const uint8_t ulp_bin_end[] asm("_binary_ulp_prog_bin_end");

extern "C" {
  void app_main(void);
}

auto app_main(void) -> void;

#endif /* MAIN_H */