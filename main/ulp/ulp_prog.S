// ld visible variables - shares them & their memory with the MCU
.global entry

// Exposed mcu active flag
.global state1
.global state2
.global state3
.global state4
.global state5

// Zero initialized variable storage
.bss

// Base pointer used by all addr_* offsets
base:

state1:
.long 0
state2:
.long 0
state3:
.long 0
state4:
.long 0
state5:
.long 0

// Offsets, to simplify variable access (by loading evtb address, and
// using this as the `offset` value in `ld` & `st`), greatly decreasing the
// number of steps needed to load & store values
// One has to have the `base` address loaded in some register though, which I
// tend to keep in r2 for most of the program.
.set addr_state1,   (state1 - base)
.set addr_state2,   (state2 - base)
.set addr_state3,   (state3 - base)
.set addr_state4,   (state4 - base)
.set addr_state5,   (state5 - base)

.text

entry:
  move  r2, base
  move  r0, 0x226 //random bits, 0000001000100110

  lsh   r1, r0, 8
  st    r1, r2, addr_state1

  lsh   r1, r0, 15
  st    r1, r2, addr_state2

  lsh   r1, r0, 16
  st    r1, r2, addr_state3

  lsh   r1, r0, 17
  st    r1, r2, addr_state4

  lsh   r1, r0, 32
  st    r1, r2, addr_state5

ulp_halt:
  halt