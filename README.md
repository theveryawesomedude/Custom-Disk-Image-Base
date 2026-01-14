# MYCD - Custom Disk Image Base

MYCD is a minimal raw disk image format intended as a base for
custom disk experiments, emulators, and virtual disks.

## Features
- Fixed 512-byte sectors
- Simple on-disk header (magic, version, volume label)
- Tooling to create blank images
- Mountable via virtual disk drivers like ImDisk

## Goals
- Provide a base for building custom filesystems
- Serve as a learning platform for disk structures
- Be extensible and open-source

## Non-goals
- Native Windows mounting without a virtual disk driver
- Built-in filesystem or file manager
