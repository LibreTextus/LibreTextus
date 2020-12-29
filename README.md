[![libretextus](https://snapcraft.io//libretextus/badge.svg)](https://snapcraft.io/libretextus)

# LibreTextus

## Dependencies

You need to install *build-essential*, *gettext*, *boost-regex*, *boost-program-options* *rapidxml* and *gtkmm*.  

```
sudo apt install libgtkmm-3.0-dev build-essential libboost-regex-dev libboost-program-options-dev gettext librapidxml-dev
```

## How to Build

```bash
make -j$(nproc)
```

## Run it

The LibreTextus binary is saved under ```build/LibreTextus``` you can run it with:

```bash
./build/LibreTextus
```

## Install

To install LibreTextus just run:

```
sudo make install
```

This will install LibreTextus under ```/usr/local/```.

If you want an icon for your desktopmanager it's possible to install a desktopfile under ```/usr/share/applications/``` with:

```
sudo make desktopicon
```

## Get Involved
If you want to make some pull requests or write issues just do it, we appreciate every help!
