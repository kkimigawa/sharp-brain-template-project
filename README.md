# sharp-brain-template-project

Sharp Brain is a electronic dictionary.  
https://ja.wikipedia.org/wiki/Brain_(%E9%9B%BB%E5%AD%90%E8%BE%9E%E6%9B%B8)

Sharp Brain based Windows CE 6.0.  
And you can run homebrew applications.

This repository is template homebrew application project.

## Setup

### for Ubuntu

1. Install CeGCC
    ```bash
    sudo echo "deb https://max.kellermann.name/debian cegcc_buster-default main" > /etc/apt/sources.list
    sudo apt update
    sudo install gcc-arm-mingw32ce
    ```

## Usage

1. Clone this project
2. Build
    ```bash
    make
    ```
3. Clean project
    ```bash
    make clean
    ```

## Transfer homebrew application to Sharp Brain

1. Connect USB cable
2. Transfer binary data
    ```
    SDCard Root
    └ アプリ
      └ {homebrew application name}
        └ AppMain.exe
        └ index.din
        └ AppMain.cfg
    ```
    "アプリ" means "app" in Japanese.
    <p align="left">
        <img src="https://user-images.githubusercontent.com/13421166/121055591-5d88df00-c7f8-11eb-825f-3a82175776b4.png" />
    </p>

## References

* CeGCC  
  https://max.kellermann.name/projects/cegcc/
* Example Sharp Brain source code.  
  https://blog.oucc.org/?p=303
