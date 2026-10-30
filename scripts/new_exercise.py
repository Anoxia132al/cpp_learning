#!/usr/bin/env python3
"""Create a C++ learning module and register its source with CMake."""

import argparse
import re
from pathlib import Path


TARGET_PATTERN = re.compile(
    r"(?ms)^add_executable\s*\(\s*Learning\b(?P<body>.*?)^\)"
)
NAME_PATTERN = re.compile(r"[a-z][a-z0-9_]*")


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Create a matching include/*.h and src/*.cpp module."
    )
    parser.add_argument(
        "name",
        help="module name in lowercase snake_case, e.g. array_reference",
    )
    args = parser.parse_args()

    if not NAME_PATTERN.fullmatch(args.name):
        parser.error("name must use lowercase snake_case, e.g. array_reference")

    root = Path(__file__).resolve().parents[1]
    header_path = root / "include" / f"{args.name}.h"
    source_path = root / "src" / f"{args.name}.cpp"
    cmake_path = root / "CMakeLists.txt"

    if header_path.exists() or source_path.exists():
        parser.error(f"{args.name} already has a header or source file")

    with cmake_path.open("r", encoding="utf-8", newline="") as cmake_file:
        cmake_text = cmake_file.read()

    targets = list(TARGET_PATTERN.finditer(cmake_text))
    if len(targets) != 1:
        parser.error("expected exactly one add_executable(Learning ...) block")

    target = targets[0]
    source_entry = re.compile(
        rf"(?m)^\s*src/{re.escape(args.name)}\.cpp\s*$"
    )
    if source_entry.search(target.group("body")):
        parser.error(f"src/{args.name}.cpp is already listed in CMakeLists.txt")

    newline = "\r\n" if "\r\n" in cmake_text else "\n"
    close_position = target.start() + target.group(0).rfind(")")
    close_line_start = cmake_text.rfind(newline, 0, close_position) + len(newline)
    updated_cmake = (
        cmake_text[:close_line_start]
        + f"    src/{args.name}.cpp{newline}"
        + cmake_text[close_line_start:]
    )

    header_path.write_text(
        "#pragma once\n\n"
        f"void run_{args.name}();\n",
        encoding="utf-8",
    )
    source_path.write_text(
        f'#include "{args.name}.h"\n\n'
        f"void run_{args.name}()\n"
        "{\n"
        "}\n",
        encoding="utf-8",
    )
    with cmake_path.open("w", encoding="utf-8", newline="") as cmake_file:
        cmake_file.write(updated_cmake)

    print(f"Created: {header_path.relative_to(root)}")
    print(f"Created: {source_path.relative_to(root)}")
    print(f"Registered: src/{args.name}.cpp in CMakeLists.txt")
    print(f'Next: include "{args.name}.h" in src/Main.cpp and call run_{args.name}().')


if __name__ == "__main__":
    main()
