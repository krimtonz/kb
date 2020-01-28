# Prerequisites
In order to build kb, you need to have the [n64 toolchain](https://github.com/glankk/n64) installed.

kb requires [libundermine-f3dex](https://github.com/krimtonz/libundermine) This is also provided as a git submodule
via `git submodule update --init`

To build the libunderime-f3dex submodule run `make libum`

# Building
To build all kb binaries, run `make all` to only build a sepecific version run `make kb-VERSION` Where VERSION is
`kb-NBKJ`

# Patching
The patching scripts will run the building process, so you can skip the building process if you plan on patching.

To build and patch kb run

`build/makerom /path/to/vanilla/rom.z64`
