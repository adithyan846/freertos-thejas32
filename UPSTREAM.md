# Upstream Reference

This repository is a fork of the FreeRTOS port for CDAC VEGA THEJAS32 (ARIES) RISC-V soft processor.

## Original Repository

- **URL:** https://gitlab.com/riscv-vega/operating-systems/freertos-thejas32
- **Maintainer:** CDAC VEGA (Centre for Development of Advanced Computing)
- **Project:** VEGA RISC-V Ecosystem

## Original License

MIT License — same as this fork. See `FreeRTOS_Source/LICENSE.md`.

## Fork Details

- **Forked by:** Adithyan Kimi
- **Fork date:** October 2026
- **Purpose:** Adapt for use as a Git submodule in flight controller projects (NIDAR VEGAPilot)
- **GitHub mirror:** https://github.com/adithyan846/freertos-thejas32

## Changes Made in This Fork

| Change | Reason |
|--------|--------|
| Added `README.md` | GitHub-friendly documentation |
| Removed example files with hardcoded Adafruit IO keys | Security / GitHub push protection |
| Verified submodule compatibility | For use in parent projects |
| Updated build system paths | For cross-project builds |

## Upstream Tracking

To sync with upstream changes:

```bash
# Add upstream remote
git remote add upstream https://gitlab.com/riscv-vega/operating-systems/freertos-thejas32.git

# Fetch upstream changes
git fetch upstream

# Merge or rebase as needed
git merge upstream/main
# or
git rebase upstream/main
```

## Attribution

Per the MIT license requirements, the original copyright notice and license text are preserved in `FreeRTOS_Source/LICENSE.md`.

Original authors: CDAC VEGA Team (premjith@cdac.in, etc.)

---

*This file documents the upstream source for license compliance and project transparency.*