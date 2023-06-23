sdl_flags := $(shell sdl2-config --cflags)
gmtl_dep = -Ideps/gmtl-0.6.1
flags := $(sdl_flags) $(gmtl_dep) -Wall -Wextra -std=gnu++2a


exe:
	gcc $(flags) Terrible3dRenderer/*.cpp

