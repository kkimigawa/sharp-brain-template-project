# sharp-brain-template-project

Sharp Brain is a electronic dictionary.  
https://ja.wikipedia.org/wiki/Brain_(%E9%9B%BB%E5%AD%90%E8%BE%9E%E6%9B%B8)

Brain based Windows CE 6.0.
And you can run on homebrew application.

## Setup

### Ubuntu

1. Add sources.list
    ```bash
    sudo echo "deb https://max.kellermann.name/debian cegcc_buster-default main" > /etc/apt/sources.list
    sudo apt update
    sudo get install gcc-arm-mingw32ce
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
