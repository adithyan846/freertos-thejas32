# FreeRTOS Port for CDAC VEGA THEJAS32 (ARIES)

This is a fork of the original FreeRTOS port for the **CDAC VEGA THEJAS32 (ARIES)** RISC-V soft processor, maintained by CDAC VEGA.

## Upstream Source

**Original repository:** https://gitlab.com/riscv-vega/operating-systems/freertos-thejas32

This fork is hosted at: https://github.com/adithyan846/freertos-thejas32

## Changes from Upstream

- Added GitHub-compatible build system
- Removed example files containing hardcoded credentials
- Ready for use as a Git submodule in flight controller projects

## License

This project is licensed under the MIT License — see [FreeRTOS_Source/LICENSE.md](FreeRTOS_Source/LICENSE.md) for details.

The original CDAC VEGA FreeRTOS port is also MIT licensed.

## Building

```bash
# From the repository root
make              # Build RTOSDemo.elf/.bin/.hex
make flash        # Flash via xmodem to /dev/ttyUSB0
make monitor      # Flash + open serial console (picocom @ 115200)
```

See the [original documentation](https://gitlab.com/riscv-vega/operating-systems/freertos-thejas32) for hardware setup and board details.

## Hardware

- **Target:** CDAC VEGA THEJAS32 (ARIES) RISC-V RV32I_ZICSR
- **Clock:** 100 MHz system clock
- **Memory:** 256 KB SRAM at 0x200000
- **UART:** 0x10000100 @ 115200 baud
- **Timer:** Machine timer (mtime/mtimecmp) at 0x20010580 / 0x20010480

## Submodule Usage

To use in another project:

```bash
git submodule add https://github.com/adithyan846/freertos-thejas32.git freertos-thejas32
git submodule update --init --recursive
```

Then include FreeRTOS headers from `freertos-thejas32/FreeRTOS_Source/include/` and link the port objects.