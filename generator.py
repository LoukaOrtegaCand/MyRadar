import random

def generate_script():
    with open("tests/test_myradar3000.rdr", "w") as file:
        for i in range(1, 3001):
            x_start, y_start = random.randint(10, 1910), random.randint(10, 1070)
            x_end, y_end = random.randint(10, 1910), random.randint(10, 1070)
            speed, delay = random.randint(5, 9), random.randint(0, 10)
            if (x_start != x_end or y_start != y_end):
                file.write(f"A  {x_start} {y_start}  {x_end} {y_end}  {speed}  {delay}\n")

        for i in range(1, 4):
            x, y = random.randint(10, 1910), random.randint(10, 1070)
            radius = random.randint(5, 15)
            file.write(f"T  {x} {y}  {radius}\n")

generate_script()
