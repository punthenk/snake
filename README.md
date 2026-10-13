![alt text](snake.png)

# Snake

A simple Snake game written in C++ using [raylib](https://www.raylib.com/).

I built this project as a small exercise for myself. I enjoy coding and figuring out how to implement things myself. Snake is a simple game, which makes it a great project code in a small amount of time and have some fun.

## Requirements

- C++ compiler with C++17 support
- CMake 3.16 or newer
- Raylib 5.5   

Install raylib with your package manager. For example:

- **Fedora:** `sudo dnf install raylib-devel`
- **Arch:** `sudo pacman -S raylib`
- **macOS:** `brew install raylib`

## Building and Running

Clone the repository:

```bash
git clone https://github.com/punthenk/snake.git
cd snake
```

Create a build directory and configure the project:

```bash
cmake -B build
cmake --build build --target run
```

You can now play snake! Enjoy!

### raylib installed in a custom location?

Tell CMake where to find it:

```bash
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/raylib-install
```
