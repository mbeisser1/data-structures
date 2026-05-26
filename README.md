# data-structures

C++17 data structure experiments.

## IDE (autocomplete, Ctrl+click)

Uses the **C/C++ extension** (`ms-vscode.cpptools`), not clangd. Include paths are in `.vscode/c_cpp_properties.json` — no CMake configure or build required for navigation on project and system headers.

Install the C/C++ extension, reload the window, and Ctrl+click on `<exception>`, `<string>`, etc. should work immediately.

To add a new include root (e.g. a new library folder), append a path under `includePath` in `c_cpp_properties.json`.

Catch2 headers in tests only appear after a one-time `cmake -S . -B build -DBUILD_TESTING=ON` (FetchContent download). Add this path to `includePath` if you need go-to-definition on Catch2:

```json
"${workspaceFolder}/build/_deps/catch2-src/src"
```

## Build

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build
```

Tests pull in Catch2 automatically if it is not installed system-wide.

## Format

Uses `.clang-format` at the repo root. Format with **Shift+Alt+F** (requires the `xaver.clang-format` extension).
