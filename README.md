# FEM

C++ project using [deal.II](https://www.dealii.org/) with CMake.

## Prerequisites

- macOS with Xcode Command Line Tools
- deal.II 9.7.1 installed at `/Applications/deal.II.app` (official Tahoe arm64 package)

Optional: source the deal.II shell environment in `~/.zshrc`:

```bash
export DEAL_II_CONF_SILENT=ON
. /Applications/deal.II.app/Contents/MacOS/dealii.conf
```

## Build

```bash
cmake -S . -B build
cmake --build build
./build/rk_butcher_table
```

`build/compile_commands.json` is generated automatically (`CMAKE_EXPORT_COMPILE_COMMANDS=ON`).
A symlink at the repo root points clangd / IDEs at that file.
