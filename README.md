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

## How do I move the data directory

If you want to move the `~/.libre_textus/` directory to for example to `.local/share/LibreTextus`, you simple need to add `LIBRETEXTUS_DATA=~/.local/share/LibreTextus` to your environment.

### LibreTextus is crashing after moving its data directory

If you got the problem that *LibreTextus* is crashing after moving its data directory, its probably caused by the `sources.xml` (*placed in your data directory*) not being up to date,
so simply remove it and *LibreTextus* will regenerate it.

## Get Involved
If you want to make some pull requests or write issues just do it, we appreciate every help!
