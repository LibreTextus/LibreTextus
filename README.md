[![libretextus](https://snapcraft.io//libretextus/badge.svg)](https://snapcraft.io/libretextus)

# LibreTextus

## Dependencies

You need to install *cmake* *build-essential* and *gtkmm*

**WARNING:** Do not use *cmake* from the apt package because it is too old for the *CMakeLists.txt* of this project. Use instead *snap* to install it or build *cmake* from source.

```
sudo apt install libgtkmm-3.0-dev build-essential
```

## How to Build

```bash
mkdir build
cd build

cmake ..
make

./LibreTextus
```

## Get Involved
If you want to make some pull requests or write issues just do it, we appreciate every help!
