import os
import pty
import select
import subprocess

tests = [
    ("pr5/max.cpp", "5|3|9|-2|9|1"),
    ("pr5/max.cpp", "3|-5|-1|-9"),
    ("pr5/max.cpp", "21"),
    ("pr5/minimax.cpp", "2|2|4 3|2 1"),
    ("pr5/minimax.cpp", "2|3|1 5 3|7 2 9"),
    ("pr5/minimax.cpp", "3|3|-5 -1 -9|-8 -7 -6|-20 -3 -4"),
    ("pr6/letter.cpp", "Шла Саша по шоссе и сосала сушку"),
    ("pr6/letter.cpp", "Hello world"),
    ("pr6/spiral.cpp", "3|4|12 11 10 9|8 7 6 5|4 3 2 1"),
    ("pr6/spiral.cpp", "3|3|5 -2 9|0 7 1|-8 3 4"),
    ("pr6/spiral.cpp", "1|5|5 4 3 2 1"),
    ("pr6/spiral.cpp", "4|1|5|4|3|2"),
    ("pr7/max.cpp", "3|8"),
    ("pr7/max.cpp", "-3|-8"),
    ("pr7/max.cpp", "5|5"),
    ("pr7/overload.cpp", "4|-5|-2|-9|-3"),
    ("pr7/overload.cpp", "1|7"),
    ("pr7/input.cpp", "10|2"),
    ("pr7/input.cpp", "2|10"),
    ("pr7/array.cpp", "3|7|8|9"),
    ("pr7/array.cpp", "25"),
    ("pr8/max.cpp", "4|-4|-1|-8|-1"),
    ("pr8/alphabet.cpp", "5|яблоко|арбуз красный|груша|банан|арбуз"),
    ("pr9/max.cpp", "4|-4|-1|-8|-2"),
    ("pr9/max.cpp", "1|-7"),
    ("pr9/max.cpp", "0"),
    ("pr9/determinant.cpp", "1|5"),
    ("pr9/determinant.cpp", "2|4 3|2 1"),
    ("pr9/determinant.cpp", "3|1 2 3|4 5 6|7 8 10"),
    ("pr9/determinant.cpp", "3|1 2 3|4 5 6|7 8 9"),
    ("pr9/determinant.cpp", "4|1 2 3 4|5 6 7 8|2 6 4 8|3 1 1 2"),
    ("pr10/flower.cpp", "7"),
    ("pr10/flower.cpp", "0"),
]


def build(source):
    binary = "../build/oop/" + source[:-4]
    if not os.path.exists(binary) or os.path.getmtime(binary) < os.path.getmtime(source):
        os.makedirs(os.path.dirname(binary), exist_ok=True)
        subprocess.run(["c++", "-std=c++20", "-Wall", "-Wextra", "-o", binary, source], check=True)
    return binary


def run(binary, lines):
    pid, fd = pty.fork()
    if pid == 0:
        os.execv(binary, [binary])
    while True:
        if select.select([fd], [], [], 0.05)[0]:
            try:
                data = os.read(fd, 1024)
            except OSError:
                break
            if not data:
                break
            os.write(1, data)
        elif lines:
            os.write(fd, (lines.pop(0) + "\n").encode())
    os.waitpid(pid, 0)


os.chdir(os.path.dirname(os.path.abspath(__file__)))

for source, data in tests:
    print("\033[H\033[2J\033[3J" + source + "\n", flush=True)
    run(build(source), data.split("|"))
    input()
