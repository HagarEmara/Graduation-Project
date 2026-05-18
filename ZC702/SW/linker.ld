/*
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.
*/

OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)
ENTRY(crtStart)

MEMORY {
  RAM      (rwx): ORIGIN = 0x00200000, LENGTH = 200m
  TCM      (rwx): ORIGIN = 0x00000000, LENGTH = 16k
}

_stack_size = 8000;

SECTIONS {

  ._vector 0x00200000: {
    *crt.o(.start_jump);
    */base/task.o(.text);
  } > RAM

  ._stack (NOLOAD):
  {
    . = ALIGN(16);
    PROVIDE (_stack_end = .);
    . = . + _stack_size;
    . = ALIGN(16);
    PROVIDE (_stack_start = .);
  } > TCM

  .TCM_DATA (NOLOAD) :
  {
    . = ALIGN(4);
    *(.tcm_data)
    *(.tcm_data.*)
    . = ALIGN(4);
  } > TCM

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _bss_start = .;
    *(.sbss*)
    *(.gnu.linkonce.sb.*)
    *(.bss .bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    . = ALIGN(4);
    _bss_end = .;
  } > RAM

  .data :
  {
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
    *(.data .data.*)
    *(.gnu.linkonce.d.*)
    . = ALIGN(8);
    PROVIDE( __global_pointer$ = . + 0x800 );
    *(.sdata .sdata.*)
    *(.gnu.linkonce.s.*)
    . = ALIGN(8);
    *(.srodata.cst16)
    *(.srodata.cst8)
    *(.srodata.cst4)
    *(.srodata.cst2)
    *(.srodata .srodata.*)
  } > RAM

  .rodata :
  {
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
  } > RAM

  .noinit (NOLOAD) : {
    . = ALIGN(4);
    *(.noinit .noinit.*)
    . = ALIGN(4);
  } > RAM

  .memory : {
    *(.text);
  } > RAM

  .ctors :
  {
    . = ALIGN(4);
    _ctors_start = .;
    KEEP(*(.init_array*))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    . = ALIGN(4);
    _ctors_end = .;
    PROVIDE ( END_OF_SW_IMAGE = . );
  } > RAM

  /* User heap placed AFTER all loaded sections.
     _heap_start = end of all loaded code/data (NOLOAD, no binary bloat).
     _heap_end   = fixed at 0x0BD00000, giving ~180 MB heap below model area
                   (model area starts at 0x0C800000 / 0x0C900000). */
  ._user_heap (NOLOAD):
  {
    . = ALIGN(16);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    PROVIDE ( _heap_start = . );
  } > RAM

  /* Hard-define _heap_end as a fixed DDR address, independent of section
     layout. This gives a huge runtime heap without bloating the binary. */
  _heap_end = 0x0BD00000;
}
