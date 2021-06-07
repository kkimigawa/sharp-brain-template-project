# sharp-brain-template-project

Sharp Brain is a electronic dictionary.  
https://ja.wikipedia.org/wiki/Brain_(%E9%9B%BB%E5%AD%90%E8%BE%9E%E6%9B%B8)

Brain based Windows CE 6.0.  
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

## Transfer homebrew application to Brain

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

## References

https://blog.oucc.org/?p=303
