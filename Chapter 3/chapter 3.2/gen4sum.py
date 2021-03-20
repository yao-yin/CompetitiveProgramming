import os
import random

with open(r"C:\Users\InYuo\Documents\GitHub\CompetitiveProgramming\Chapter 3\chapter 3.2\4 Values whose Sum is 0.01.inp", "w") as f:
    f.write("4000\n")
    for i in range(4000):
        f.write("{} {} {} {}\n".format(random.randint(168435456, 268435456), random.randint(168435456, 268435456), random.randint(168435456,268435456), random.randint(168435456,268435456)) )